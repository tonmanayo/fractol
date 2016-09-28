/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 07:14:40 by tmack             #+#    #+#             */
/*   Updated: 2016/09/28 17:02:19 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "test.h"
# include <math.h>


void		draw(t_win *win)
{
	double	c_re;
	double	c_im;
	double	x = 0;
	double	y = 0;
	int		row = -1;
	int iteration = 0;
	double x_new ;

	win->img = mlx_new_image(win->init, WIN_W, WIN_H);
	win->data = mlx_get_data_addr(win->img, &(win->bpp), &(win->size),
			&(win->end));
	while (++row < WIN_H)
   	{
		int col = -1;
		while (++col < WIN_W)
		{
			c_re = ((col - (WIN_W * win->z_x) / (2.0 + win->i_x)) * (4.0 * win->z_x) / WIN_W);
			c_im = ((row - (WIN_H * win->z_x) / 2.0 ) * (4.0 * win->z_x) / WIN_W);
			x = 0;
			y = 0;
			iteration = 0;
			while (x * x + y * y <= 4 && iteration < MAX_S) 
			{
				x_new = x * x - y * y + c_re;
				y = 2 * x * y + c_im;
				x = x_new;
				iteration++;
			if (iteration < MAX_S)
			{
				win->data[((int)col * (win->bpp / 8)) + ((int)row * win->size)] =
					(iteration * 20) % 256;
				win->data[((int)col * (win->bpp / 8)) + ((int)row * win->size) + 1] =
					(iteration * iteration) % 256;
				win->data[((int)col * (win->bpp / 8)) + ((int)row * win->size) + 2] =
				((int)(sin(iteration))) % 256;
			}
			else
			{
				win->data[((int)col * (win->bpp / 8)) + ((int)row * win->size)] = 255;
				win->data[((int)col * (win->bpp / 8)) + ((int)row * win->size) + 1] = 255;
				win->data[((int)col * (win->bpp / 8)) + ((int)row * win->size) + 2] = 255;
			}
			}
		}
	}
	mlx_put_image_to_window(win->init, win->win, win->img, 0, 0);
}

int		mouse_hook(int	keycode, int x, int y,  t_win *win)
{
	if (keycode == 4)
	{
		win->z_x = (win->z_x + 0.1) * 0.75 ;
		mlx_destroy_image(win->init, win->img);
		draw(win);
	}

	if (keycode == 5)
	{
		win->z_x = (win->z_x + 0.1) / 0.75;
		mlx_destroy_image(win->init, win->img);
		draw(win);
	}
	return(0);
}

int     key_hook(int keycode, t_win *win)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		win->i_x += 1;
		mlx_destroy_image(win->init, win->img);
		draw(win);
	}
	if (keycode == 124)
	{
		win->i_x -= 1;
		mlx_destroy_image(win->init, win->img);
		draw(win);
	}
	if (keycode == 126)
	{
		win->z_x += 0.5;
		mlx_destroy_image(win->init, win->img);
		draw(win);
	}
	if (keycode == 125)
	{
		win->z_x -= 0.5;
		mlx_destroy_image(win->init, win->img);
		draw(win);
	}
	return (0);
}

void		init(t_win *win)
{
	win->bpp = 0;
	win->size = 0;
	win->end = 0;
	win->i_x = 0;
	win->z_x = 0;
	win->z_y = 0;
	win->i_y = 0;
}

void   main_init(t_win *win)
{
	init(win);
	win->data = NULL;
	win->a = 0.00;
	win->b = 0.00;
	win->x = 0.00;
	win->y = 0.00;
	win->init = mlx_init();
	win->win = mlx_new_window(win->init, 480, 600, "fractol");
	draw(win);
	mlx_key_hook(win->win, key_hook, win);
	mlx_mouse_hook(win->win, mouse_hook, win);
}

int main()
{
	t_win	win;

	main_init(&win);
	mlx_loop(win.init);
}

