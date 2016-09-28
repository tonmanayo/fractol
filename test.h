/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 10:43:10 by tmack             #+#    #+#             */
/*   Updated: 2016/09/28 15:42:55 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_H 600
# define WIN_W 480
# define MAX_S 200
typedef struct	s_win
{
	void			*init;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size;
	int				end;
	float			x;
	float			y;
	float			a;
	float			b;
	float			i_x;
	float			i_y;
	float			z_x;
	float			z_y;
}				t_win;
