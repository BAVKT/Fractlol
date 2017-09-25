/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:38:15 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/25 19:50:22 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Print the pixel in the image
*/

void	px_img(t_base *base, t_fract *fr)
{
	if (fr->x > base->winx || fr->x < 0 || fr->y > base->winy || fr->y < 0)
		return ;
	base->mx.data[fr->y * base->winx + fr->x] = fr->color;
}

/*
** return the color needed for the pixel
*/

void	get_color(t_fract *fr)
{
	unsigned char c;

	if (fr->i == fr->maxi)
		c = 0;
	else
		c = 255 * fr->i / fr->maxi;
	fr->color = ((c & 255) << 24);
	fr->color = ((c & 255) << 16);
	fr->color = ((c & 255) << 8);
	fr->color = (c & 255);

}

/*
** Print the UI on the window
*/

void	ui(t_base *base)
{
			ft_putendlcolor("ui()", MAGENTA);
	int		w;

	w = 0xffffff;
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 20, 0x00ff00, "    - KEYS -");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 50, w, "Move   =  Scroll Wheel");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 70, w, "Colors =  NumPad");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 90, w, "Quit   =  Esc");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 110, w, "Zoom   =  +  &  -");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 130, w, "Reset  =  ~");
	mlx_string_put(base->mx.mlx, base->mx.win, base->winx - 190, base->winy - 30,
		w, ft_strjoin("Iterations = ", ft_itoa(base->fr.maxi)));
	mlx_string_put(base->mx.mlx, base->mx.win, base->winx - 190, base->winy - 50,
		w, ft_strjoin("Zoom       = ", ft_strjoin(ft_itoa(base->fr.zoom * 100), "%")));
}
