/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 08:01:18 by tmack             #+#    #+#             */
/*   Updated: 2016/09/30 12:57:35 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_frac *m)
{
	m->img = mlx_new_image(m->init, m->s_x_max, m->s_y_max);
	m->data = mlx_get_data_addr(m->img, &(m->bpp), &(m->size),
			&(m->end));
	 //after how much iterations the function should stop
	m->w_x_min = -0.7;
	m->w_x_max = 0.27015;
	//loop through every pixel
	m->s_y = -1;
	while (++m->s_y < m->s_y_max)
	{
		m->s_x = -1;
		while (++m->s_x < m->s_x_max)
		{
			//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			m->zx = 1.5 * (m->s_x - m->s_x_max / 2) / (m->zoom * m->s_x_max) + m->pan_x + m->m_x;
			m->zy = (m->s_y - m->s_y_max / 2) / (m->zoom * m->s_y_max) + m->pan_y + m->m_y;
			//i will represent the number of iterations
			//start the iteration process
			m->iterate = -1;
			while (++m->iterate < m->iterate_max)
			{
				//remember value of previous iteration
				m->zx2 = m->zx;
				m->zy2 = m->zy;
				//the actual iteration, the real and imaginary part are calculated
				m->zx = m->zx2 * m->zx2 - m->zy2 * m->zy2 + m->w_x_min;
				m->zy = 2 * m->zx2 * m->zy2 + m->w_x_max;
				//if the point is outside the circle with radius 2: stop
				if((m->zx * m->zx + m->zy * m->zy) > 4)
					break;
			}
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
	 mlx_put_image_to_window(m->init, m->win, m->img, 0, 0);
}
