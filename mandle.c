/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 07:27:40 by tmack             #+#    #+#             */
/*   Updated: 2016/09/30 10:44:53 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    set_img(t_frac *m)
{
	m->img = mlx_new_image(m->init, m->s_x_max, m->s_y_max);
	m->data = mlx_get_data_addr(m->img, &(m->bpp), &(m->size),
			&(m->end));
	m->px_width = ((m->w_x_max) - m->w_x_min) / (m->s_x_max + m->zoom);
	m->px_height = ((m->w_y_max) - m->w_y_min) / (m->s_y_max + m->zoom);
	m->s_y = -1;
}

void    calc_img(t_frac *m)
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

void    set_attrb(t_frac *m)
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

void        draw(t_frac *m)
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

