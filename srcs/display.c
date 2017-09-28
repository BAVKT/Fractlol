/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:38:15 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/28 20:41:31 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Print the pixel in the image
*/

void	px_img(t_fract *fr)
{
	if (fr->x > fr->winx || fr->x < 0 || fr->y > fr->winy || fr->y < 0)
		return ;
	fr->data[fr->y * fr->winx + fr->x] = fr->color;
}

/*
** return the color needed for the pixel
*/

void	get_color(t_fract *fr)
{
	if (fr->i >= fr->maxi)
		fr->color = 0;
	else
		fr->color = (fr->i * (fr->r * fr->g *fr->b)) % 16581375;
}

/*
** Print the UI on the window
*/

void	ui(t_base *base)
{
			//ft_putendlcolor("ui()", MAGENTA);
	int		w;

	w = 0xffffff;
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 20, 0x00ff00, "    - KEYS -");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 50, w, "Quit     =  Esc");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 70, w, "Reset    =  ~");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 90, w, "Zoom     =  +  &  -");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 110, w, "Move     =  Scroll Wheel");
	if (base->mouse)
		mlx_string_put(base->mx.mlx, base->mx.win, 50, 130, w, "SpaceBar =  Mouse ON");
	else
		mlx_string_put(base->mx.mlx, base->mx.win, 50, 130, w, "SpaceBar =  Mouse OFF");
	mlx_string_put(base->mx.mlx, base->mx.win, base->winx - 220, base->winy - 30,
		w, ft_strjoin("Iterations = ", ft_itoa(base->fr[0].maxi)));
	mlx_string_put(base->mx.mlx, base->mx.win, base->winx - 220, base->winy - 50,
		w, ft_strjoin("Zoom       = ", ft_strjoin(ft_itoa(base->fr[0].zoom * 100), "%")));
}
