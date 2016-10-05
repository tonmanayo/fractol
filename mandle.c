/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 07:27:40 by tmack             #+#    #+#             */
/*   Updated: 2016/10/05 07:13:19 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_img(t_frac *m)
{
	m->img = mlx_new_image(m->init, m->s_x_max, m->s_y_max);
	m->data = mlx_get_data_addr(m->img, &(m->bpp), &(m->size),
			&(m->end));
	m->s_y = -1;
}

void	calc_img(t_frac *m, double x)
{
	m->w_x = 1.0 * (m->s_x - m->s_x_max / 2) / x + m->pan_x;
	m->zx = 0.00;
	m->zy = 0.00;
	m->zx2 = m->zx * m->zx;
	m->zy2 = m->zy * m->zy;
	m->iterate = -1;
	while (++m->iterate < m->iterate_max && ((m->zx2 + m->zy2) < 4))
	{
		m->zy = 2 * m->zx * m->zy + m->w_y;
		m->zx = m->zx2 - m->zy2 + m->w_x;
		m->zx2 = m->zx * m->zx;
		m->zy2 = m->zy * m->zy;
	}
}

void	set_colour(t_frac *m)
{
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

void	mandelbrot(t_frac *m)
{
	double	x;
	double	y;

	x = 0.5 * m->zoom * m->s_x_max;
	y = 0.5 * m->zoom * m->s_y_max;
	set_img(m);
	while (++m->s_y < m->s_y_max)
	{
		m->w_y = (m->s_y - m->s_x_max / 2) / y + m->pan_y;
		m->s_x = -1;
		while (++m->s_x < m->s_x_max)
		{
			calc_img(m, x);
			set_colour(m);
		}
	}
	mlx_put_image_to_window(m->init, m->win, m->img, 0, 0);
}
