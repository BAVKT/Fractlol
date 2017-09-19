/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:38:15 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/19 19:35:25 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Print the pixel in the image
*/

void	px_img(t_base *base, int x, int y, int color)
{
	if (x > base->winx || x < 0 || y > base->winy || y < 0)
		return ;
	base->mx.data[y * base->winx + x] = color;
}

/*
** return the color needed for the pixel
*/

void	get_color(t_fract *fr, int i)
{
	int r;
	int g;
	int b;

	fr->color = fr->mx * fr->my;
	r = 255 * i / fr->maxi;
	g = 255 * i / fr->maxi;
	b = 255 * i / fr->maxi;
	fr->color = (fr->color | r);
	fr->color = (fr->color << 8 | g);
	fr->color = (fr->color << 16 | b);
}

/*
** Print the UI on the window
*/

void	ui(t_base *base)
{
			ft_putendlcolor("ui()", MAGENTA);
	int w;

	w = 0xffffff;
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 20, 0x00ff00, "    - KEYS -");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 50, w, "Move   =  Scroll Wheel");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 70, w, "Colors =  NumPad");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 90, w, "Quit   =  Esc");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 110, w, "Zoom   =  +  &  -");
}
