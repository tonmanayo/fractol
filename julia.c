/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 08:01:18 by tmack             #+#    #+#             */
/*   Updated: 2016/10/05 07:10:46 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_formula(t_frac *m)
{
	m->iterate = -1;
	while (++m->iterate < m->iterate_max &&
			((m->zx * m->zx + m->zy * m->zy) < 4))
	{
		m->zx2 = m->zx;
		m->zx = m->zx * m->zx - m->zy * m->zy + m->w_x_min;
		m->zy = 2 * m->zx2 * m->zy + m->w_x_max;
	}
}

void	julia(t_frac *m)
{
	set_img(m);
	m->s_y = -1;
	while (++m->s_y < m->s_y_max)
	{
		m->s_x = -1;
		while (++m->s_x < m->s_x_max)
		{
			m->zx = 1.0 * (m->s_x - m->s_x_max / 2) /
				(0.3 * m->zoom * m->s_x_max) + m->pan_x;
			m->zy = (m->s_y - m->s_x_max / 2) /
				(0.3 * m->zoom * m->s_y_max) + m->pan_y;
			julia_formula(m);
			set_colour(m);
		}
	}
	mlx_put_image_to_window(m->init, m->win, m->img, 0, 0);
}
