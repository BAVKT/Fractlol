/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:39:23 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/19 19:54:09 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Algorithm for the Julia fractal
*/

void	julia(t_base *base, t_fract *fr)
{
			ft_putendlcolor("Julia()", MAGENTA);
	fr->y = 0;
	while (fr->y < base->winy)
	{
		fr->x = 0;
		while (fr->x < base->winx)
		{
			fr->nr = 1.5 * (fr->x - base->winx / 2) / (0.5 * fr->zoom * base->winx) + fr->mx;
			fr->ni = (fr->y - base->winy / 2) / (0.5 * fr->zoom * base->winy) + fr->my;
			fr->i = 0;
			while (fr->i < fr->maxi)
			{
				fr->ar = fr->nr;
				fr->ai = fr->ni;
				fr->nr = fr->ar * fr->ar - fr->ai * fr->ai + fr->cr;
				fr->ni = 2 * fr->ar * fr->ai + fr->ci;
				if((fr->nr * fr->nr + fr->ni * fr->ni) > 4)
					break;
				fr->i++;
			get_color(fr, fr->i);
			px_img(base, fr->x, fr->y, fr->color);
			}
			fr->x++;
		}
		fr->y++;
	}
}
