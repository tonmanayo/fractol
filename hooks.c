/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 07:52:41 by tmack             #+#    #+#             */
/*   Updated: 2016/10/04 09:58:02 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int  keycode, int x, int y, t_frac *m)
{
    if (keycode == 4)
    {
        m->iterate_max++;
        m->pan_x += (((double)x - m->s_y_max / 2) / m->s_x_max / 2) /
			m->zoom * 10;
        m->pan_y += (((double)y - m->s_x_max / 2) / m->s_y_max / 2 ) /
			m->zoom * 10;
        m->zoom *= 1.1;
    }
    if (keycode == 5)
    {
        m->pan_x += (((double)x - m->s_y_max / 2) / m->s_x_max / 2) / m->zoom * 10;
        m->pan_y += (((double)y - m->s_x_max / 2) / m->s_y_max / 2) / m->zoom * 10;
        m->zoom /= 1.1;
    }
    chose_fractal(m);
    return(0);
}

int		expose(t_frac *m)
{
	chose_fractal(m);
	return (0);
}

int     key_hook(int keycode, t_frac *win)
{
    printf("%i\n", keycode);
    if (keycode == 53) // 65307 exit
        exit(0);
    if (keycode == 123) // 65361 right
        win->pan_x += 10 / (win->zoom * 20 );
    if (keycode == 124) // 65363 left
        win->pan_x -= 10 / (win->zoom * 20 );
    if (keycode == 126) //  65362 up
        win->pan_y += 10 / (win->zoom * 20 );
    if (keycode == 125) // 65364 down
        win->pan_y -= 10 / (win->zoom * 20 );
    chose_fractal(win);
    return (0);
}

int		mouse_move(int x, int y, t_frac *m)
{

    if (x >= 0 && y >= 0 && x <= m->s_x_max && y <= m->s_y_max)
    {
        m->w_x_min = (double)x / (double)m->s_x_max * 4 - 2;
        m->w_y_max = (double)y / (double)m->s_y_max * 4 - 2;
    	chose_fractal(m);
    }
    return (0);
}
