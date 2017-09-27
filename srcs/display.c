/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:38:15 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/27 21:30:59 by vmercadi         ###   ########.fr       */
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
	unsigned char	c;
	int				size;

	size = fr->maxi / 8;
	if (fr->i == fr->maxi)
		c = 0;
	else
		c = 255 * (fr->i * 8) / fr->maxi;

	// if (fr->i == fr->maxi)
	// 	c = 0;
	// else if (fr->i > size * 7)
	// 	c = 
	// else if (fr->i > size * 6)
	// else if (fr->i > size * 5)
	// else if (fr->i > size * 4)
	// else if (fr->i > size * 3)
	// else if (fr->i > size * 2)
	// else if (fr->i > size * 1)


	fr->color = (c & 255);
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
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 50, w, "Move   =  Scroll Wheel");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 70, w, "Colors =  NumPad");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 90, w, "Quit   =  Esc");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 110, w, "Zoom   =  +  &  -");
	mlx_string_put(base->mx.mlx, base->mx.win, 50, 130, w, "Reset  =  ~");
	mlx_string_put(base->mx.mlx, base->mx.win, base->winx - 220, base->winy - 30,
		w, ft_strjoin("Iterations = ", ft_itoa(base->fr[0].maxi)));
	mlx_string_put(base->mx.mlx, base->mx.win, base->winx - 220, base->winy - 50,
		w, ft_strjoin("Zoom       = ", ft_strjoin(ft_itoa(base->fr[0].zoom * 100), "%")));
}
