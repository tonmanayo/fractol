/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 09:58:33 by tmack             #+#    #+#             */
/*   Updated: 2016/10/04 14:26:42 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    calc_img_n(t_frac *m, double x)
{
	m->w_x = (m->s_x_max / m->s_y_max) * (m->s_x - m->s_x_max / 2) / x + m->pan_x;
	m->zx = 0.00;
	m->zy = 0.00;
	m->zx2 = 0.00;
	m->zy2 = 0.00;
	m->iterate = -1;
	while (++m->iterate < m->iterate_max && ((m->zx2 + m->zy2) < 4))
	{
		m->zx = m->zx2 * m->zx - 3 * m->zx * m->zy2 + m->w_x;
		m->zy =  3 * m->zx2 * m->zy - m->zy2 * m->zy + m->w_y;
		m->zx2 = m->zx * m->zx ;
		m->zy2 = m->zy * m->zy ;
	}
}

void        mandelbrot_three(t_frac *m)
{
	double  x;
	double  y;

	x = 0.5 * m->zoom * m->s_x_max;
	y = 0.5 * m->zoom * m->s_y_max;
	set_img(m);
	while(++m->s_y < m->s_y_max)
	{
		m->w_y = (m->s_y - m->s_x_max / 2) / y + m->pan_y;
		m->s_x = -1;
		while (++m->s_x < m->s_x_max)
		{
			calc_img_n(m, x);
			set_colour(m);
		}
	}
	mlx_put_image_to_window(m->init, m->win, m->img, 0, 0);
}
