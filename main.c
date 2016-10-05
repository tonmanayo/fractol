/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 07:40:42 by tmack             #+#    #+#             */
/*   Updated: 2016/10/05 07:02:20 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	init_mandle(t_frac *m)
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

void	init_julia(t_frac *m)
{
	m->w_x_min = -0.7;
	m->w_x_max = 0.27015;
	m->s_x_max = 800;
	m->s_y_max = 600;
	m->w_y_min = -2.00;
	m->w_y_max = 4.00;
	m->iterate_max = 200;
	m->e_rad = 2.00;
	m->e_rad2 = m->e_rad * m->e_rad;
}

void	chose_fractal(t_frac *m)
{
	if (ft_strcmp(m->argv, "mandelbrot") == 0)
	{
		if (m->img != NULL)
			mlx_destroy_image(m->init, m->img);
		mandelbrot(m);
	}
	else if (ft_strcmp(m->argv, "julia") == 0)
	{
		if (m->img != NULL)
			mlx_destroy_image(m->init, m->img);
		julia(m);
	}
	else if (ft_strcmp(m->argv, "mandelbrot_three") == 0)
	{
		if (m->img != NULL)
			mlx_destroy_image(m->init, m->img);
		mandelbrot_three(m);
	}
	else
	{
		printf("error: invalid argument! please enter: mandelbrot | /\
				julia | mandelbrot_three");
		exit(0);
	}
}

void	main_init(t_frac *win, char **argv)
{
	win->m_x = 0;
	win->m_y = 0;
	win->zoom = 1;
	win->pan_y = 0;
	win->pan_x = 0;
	win->size = 0;
	win->bpp = 0;
	win->end = 0;
	win->argv = strdup(argv[1]);
	win->data = NULL;
	win->init = mlx_init();
	win->win = mlx_new_window(win->init, 800, 600, "fractol");
	chose_fractal(win);
	mlx_expose_hook(win->win, expose, win);
	mlx_key_hook(win->win, key_hook, win);
	mlx_mouse_hook(win->win, mouse_hook, win);
	mlx_hook(win->win, 6, (1L << 6), mouse_move, win);
	mlx_loop(win->init);
}

int		main(int argc, char **argv)
{
	t_frac	m;

	if (ft_strcmp(argv[1], "julia") == 0)
		init_julia(&m);
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		init_mandle(&m);
	else if (ft_strcmp(argv[1], "mandelbrot_three") == 0)
		init_mandle(&m);
	main_init(&m, argv);
}
