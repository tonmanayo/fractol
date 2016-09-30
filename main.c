/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 07:40:42 by tmack             #+#    #+#             */
/*   Updated: 2016/09/30 12:07:25 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void		init_m(t_frac *m)
{
	m->s_x_max = 800;
	m->s_y_max = 600;
	m->w_x_min = -2.50;
	m->w_x_max = 2.00;
	m->w_y_min = -2.00;
	m->w_y_max = 4.00;
	m->iterate_max = 200;
	m->e_rad = 2.00;
	m->e_rad2 = m->e_rad * m->e_rad;
}

void	main_init(t_frac *win)
{
	win->m_x = 0;
	win->m_y = 0;
	win->zoom = 1;
	win->pan_y = 0;
	win->pan_x = 0;
	win->size = 0;
	win->bpp = 0;
	win->end = 0;
	init_m(win);
	win->data = NULL;
	win->init = mlx_init();
	win->win = mlx_new_window(win->init, 800, 600, "fractol");
	julia(win);
//	draw(win);
	mlx_hook(win->win, 6, (1L<<6), mouse_move, win); 
	mlx_key_hook(win->win, key_hook, win);
	mlx_mouse_hook(win->win, mouse_hook, win);
}

int		main()
{
	t_frac	m;

	main_init(&m);
	mlx_loop(m.init);
}

