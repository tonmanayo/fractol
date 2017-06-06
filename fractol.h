/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:14:17 by tmack             #+#    #+#             */
/*   Updated: 2016/10/05 07:29:48 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"

# define WIN_H 800
# define WIN_W 600
# define MAX_S 200

typedef struct		s_frac
{
	char			*argv;
	void			*init;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size;
	int				end;
	int				s_x;
	int				s_y;
	int				s_x_max;
	int				s_y_max;
	double			w_x;
	double			w_y;
	double			w_x_min;
	double			w_x_max;
	double			w_y_min;
	double			w_y_max;
	double			px_width;
	double			px_height;
	double			zx;
	double			z_tmp;
	double			zy;
	double			zx2;
	double			zy2;
	int				iterate;
	int				iterate_max;
	double			e_rad;
	double			e_rad2;
	double			pan_x;
	double			pan_y;
	double			zoom;
	int				m_x;
	int				m_y;
}					t_frac;
/*
** functions
*/
int					expose(t_frac *m);
void				set_colour(t_frac *m);
void				set_img(t_frac *m);
void				set_attrb(t_frac *m);
void				mandelbrot(t_frac *m);
int					mouse_hook(int keycode, int x, int y, t_frac *m);
int					key_hook(int keycode, t_frac *win);
int					mouse_move(int x, int y, t_frac *m);
void				julia(t_frac *m);
void				init_mandle(t_frac *m);
void				init_julia(t_frac *m);
void				chose_fractal(t_frac *m);
void				mandelbrot_three(t_frac *m);

#endif
