/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 07:52:41 by tmack             #+#    #+#             */
/*   Updated: 2016/09/30 12:12:20 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     mouse_hook(int  keycode, int x, int y, t_frac *m)
{
	if (keycode == 4)
	{
		m->zoom += 0.5;
		m->iterate_max++;
//		m->pan_x += (x - (m->s_x / 2));
//		m->pan_y += (y - (m->s_y / 2));
	}
	if (keycode == 5)
	{
		m->zoom -= 0.5;
//		m->pan_x += (x - (m->s_x / 2));
//		m->pan_y += (y - (m->s_y / 2));
	}
	mlx_destroy_image(m->init, m->img);
	julia(m);
//	draw(m);
	return(0);
}

int     key_hook(int keycode, t_frac *win)
{
	if (keycode == 53)
		exit(0);
/*	if (keycode == 123)
		win->pan_x += 30;
	if (keycode == 124)
		win->pan_x -= 30;
	if (keycode == 126)
		win->pan_y += 30;
	if (keycode == 125)
		win->pan_y -= 30;*/
	julia(win);
//	draw(win);
	return (0);
}

int		mouse_move(int x, int y, t_frac *m)
{
	m->m_x = (x - (m->s_x / 2)) * 0.5;
	m->m_y = (y - (m->s_y / 2)) * 0.5;
	mlx_destroy_image(m->init, m->img);
	julia(m);
	return (0);
}
