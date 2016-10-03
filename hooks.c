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
        m->iterate_max++;
        m->pan_x += (((double)x - m->s_y_max / 2) / m->s_x_max / 2) / m->zoom * 10;
        m->pan_y += (((double)y - m->s_x_max / 2) / m->s_y_max / 2 )/ m->zoom * 10;
        m->zoom *= 1.1;
    }
    if (keycode == 5)
    {
        m->pan_x += (((double)x - m->s_y_max / 2) / m->s_x_max / 2) / m->zoom * 10;
        m->pan_y += (((double)y - m->s_x_max / 2) / m->s_y_max / 2) / m->zoom * 10;
        m->zoom /= 1.1;
    }
    //	mlx_destroy_image(m->init, m->img);
     julia(m);
   // mandelbrot(m);
    return(0);
}

int     key_hook(int keycode, t_frac *win)
{
    printf("%i\n", keycode);
    if (keycode == 65307) //53 exit
        exit(0);
    if (keycode == 65361) //123 right
        win->pan_x += 10 / (win->zoom * 20 );
    if (keycode == 65363) //124 left
        win->pan_x -= 10 / (win->zoom * 20 );
    if (keycode == 65362) // 126 up
        win->pan_y += 10 / (win->zoom * 20 );
    if (keycode == 65364) // 125 down
        win->pan_y -= 10 / (win->zoom * 20 );
     julia(win);
  //  mandelbrot(win);
    return (0);
}

int		mouse_move(int x, int y, t_frac *m)
{

    if (x >= 0 && y >= 0 && x <= m->s_x_max && y <= m->s_y_max)
    {
   //     m->w_x = (double)x / (double)m->s_x_max * 4 - 2;
     //   m->w_y = (double)y / (double)m->s_y_max * 4 - 2;
      m->m_x = (x - (m->s_x / 2)) * 0.5;
    m->m_y = (y - (m->s_y / 2)) * 0.5;
    //	mlx_destroy_image(m->init, m->img);
    // julia(m);
    }
     //   mandelbrot(m);
    return (0);
}
