/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 07:14:40 by tmack             #+#    #+#             */
/*   Updated: 2016/09/29 13:35:10 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "test.h"
# include <math.h>

void		init_m(t_frac *m)
{
	m->s_x_max = 800;
	m->s_y_max = 600;
	m->w_x_min = -2.50;
	m->w_x_max = 2.00;
	m->w_y_min = -2.00;
	m->w_y_max = 4.00;
	m->iterate_max = 400;
	m->e_rad = 2.00;
	m->e_rad2 = m->e_rad * m->e_rad;
}

void	calc_img(t_frac *m)
{
	m->w_x = m->w_x_min + (m->pan_x + m->s_x) * m->px_width;
	m->zx = 0.0;
	m->zy = 0.0;
	m->zx2 = m->zx * m->zx;
	m->zy2 = m->zy * m->zy;
	m->iterate = -1;
	while (++m->iterate < m->iterate_max && ((m->zx2 + m->zy2) < m->e_rad2 ))
	{
		m->zy = 2 * m->zx * m->zy + m->w_y;
		m->zx = m->zx2 - m->zy2 + m->w_x;
		m->zx2 = m->zx * m->zx;
		m->zy2 = m->zy * m->zy;
	}
}

void	set_img(t_frac *m)
{
	m->img = mlx_new_image(m->init, m->s_x_max, m->s_y_max);
	m->data = mlx_get_data_addr(m->img, &(m->bpp), &(m->size),
			&(m->end));
	m->px_width = ((m->w_x_max) - m->w_x_min) / (m->s_x_max + m->zoom);
	m->px_height = ((m->w_y_max) - m->w_y_min) / (m->s_y_max + m->zoom);
	m->s_y = -1;
}

void	set_attrb(t_frac *m)
{
	m->s_x = -1;
	while (++m->s_x < m->s_x_max)
	{
		calc_img(m);
		if (m->iterate < m->iterate_max)
		{
			m->data[(m->s_x * (m->bpp / 8)) + (m->s_y * m->size)] =
				(m->iterate * 20) % 256;
			m->data[(m->s_x * (m->bpp / 8)) + (m->s_y * m->size) + 1] =
				(m->iterate * m->iterate) % 256;
			m->data[(m->s_x * (m->bpp / 8)) + (m->s_y * m->size) + 2] =
				((int)(sin(m->iterate))) % 256;
		}
		else
		{
			m->data[(m->s_x * (m->bpp / 8)) + (m->s_y * m->size)] = 255;
			m->data[(m->s_x * (m->bpp / 8)) + (m->s_y * m->size) + 1] = 255;
			m->data[(m->s_x * (m->bpp / 8)) + (m->s_y * m->size) + 2] = 255;
		}
	}
}

void		draw(t_frac *m)
{
	set_img(m);
	while(++m->s_y < m->s_y_max)
	{
		m->w_y = m->w_y_min + (m->pan_y + m->s_y) * m->px_height;
		if (fabs(m->w_y) < (m->px_height / 2))
			m->w_y = 0;
		set_attrb(m);
	}
	mlx_put_image_to_window(m->init, m->win, m->img, 0, 0);
}

int		mouse_hook(int	keycode, int x, int y, t_frac *m)
{
	if (keycode == 4)
	{
		m->zoom += 200;
		m->pan_x += (x - (m->s_x / 2));
		m->pan_y += (y - (m->s_y / 2));
	}
	if (keycode == 5)
	{
		m->zoom -= 200;
		m->pan_x += (x - (m->s_x / 2));
		m->pan_y += (y - (m->s_y / 2));
	}
	draw(m);
	mlx_destroy_image(m->init, m->img);
	return(0);
}

int     key_hook(int keycode, t_frac *win)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		win->pan_x += 30;
	if (keycode == 124)
		win->pan_x -= 30;
	if (keycode == 126)
		win->pan_y += 30;
	if (keycode == 125)
		win->pan_y -= 30;
	draw(win);
	return (0);
}

void	main_init(t_frac *win)
{
	win->zoom = 0;
	win->pan_y = 0;
	win->pan_x = 0;
	win->size = 0;
	win->bpp = 0;
	win->end = 0;
	init_m(win);
	win->data = NULL;
	win->init = mlx_init();
	win->win = mlx_new_window(win->init, 800, 600, "fractol");
	draw(win);
	mlx_key_hook(win->win, key_hook, win);
	mlx_mouse_hook(win->win, mouse_hook, win);
}

int		main()
{
	t_frac	m;

	main_init(&m);
	mlx_loop(m.init);
}

