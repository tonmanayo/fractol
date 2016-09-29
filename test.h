/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 10:43:10 by tmack             #+#    #+#             */
/*   Updated: 2016/09/29 12:32:17 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_H 800
# define WIN_W 600
# define MAX_S 200
typedef struct		s_frac
{
/*
** minilibX
*/
	void			*init;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size;
	int				end;
/*
** screen
*/
	int				s_x;
	int				s_y;
	int				s_x_max;
	int				s_y_max;
/*
** world
*/
	double			w_x;
	double			w_y;
	double			w_x_min;
	double			w_x_max;
	double			w_y_min;
	double			w_y_max;
/*
** pixel
*/
	double			px_width;
	double			px_height;
/*
** imagenary numbers z = zx + zy * i 2zx = zx^2
*/
	double			zx;
	double			zy;
	double			zx2;
	double			zy2;
/*
** depth by itteration
*/
	int				iterate;
	int				iterate_max;
/*
** escape values, radius
*/
	double			e_rad;
	double			e_rad2;
/*
** pan x and y
*/
  	int			pan_x;
	int			pan_y;	
	double			zoom;	
}					t_frac;

