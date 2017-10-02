/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:50:47 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/02 16:26:58 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Mandelbrot where + & - are swapped
*/

void	reversebrot(t_fract *fr)
{
	fr->cr = 1.5 * (fr->x - fr->winx / 2) /
		(0.5 * fr->zoom * fr->winx) + fr->mx;
	fr->ci = (fr->y - fr->winy / 2) / (0.5 * fr->zoom * fr->winy) + fr->my;
	while (fr->i < fr->maxi)
	{
		fr->ar = fr->nr - fr->sx;
		fr->ai = fr->ni - fr->sy;
		fr->nr = fr->ar * fr->ar + fr->ai * fr->ai - fr->cr;
		fr->ni = 2 * fr->ar * fr->ai - fr->ci;
		if ((fr->nr * fr->nr - fr->ni * fr->ni) > 4)
			break ;
		fr->i++;
	}
}

/*
** Julia where + & - are swapped
*/

void	reversejulia(t_fract *fr)
{
	fr->nr = 1.5 * (fr->x - fr->winx / 2) /
		(0.5 * fr->zoom * fr->winx) + fr->mx;
	fr->ni = (fr->y - fr->winy / 2) / (0.5 * fr->zoom * fr->winy) + fr->my;
	fr->i = 0;
	while (fr->i < fr->maxi)
	{
		fr->ar = fr->nr - fr->sx;
		fr->ai = fr->ni - fr->sy;
		fr->nr = fr->ar * fr->ar - fr->ai * fr->ai - fr->cr;
		fr->ni = 2 * fr->ar * fr->ai - fr->ci;
		if ((fr->nr * fr->nr - fr->ni * fr->ni) > 4)
			break ;
		fr->i++;
	}
}

/*
** Julia with ni = -2 instead of 2
*/

void	cell(t_fract *fr)
{
	fr->nr = 1.5 * (fr->x - fr->winx / 2) /
		(0.5 * fr->zoom * fr->winx) + fr->mx;
	fr->ni = (fr->y - fr->winy / 2) / (0.5 * fr->zoom * fr->winy) + fr->my;
	fr->i = 0;
	while (fr->i < fr->maxi)
	{
		fr->ar = fr->nr + fr->sx;
		fr->ai = fr->ni + fr->sy;
		fr->nr = fr->ar * fr->ar - fr->ai * fr->ai + fr->cr;
		fr->ni = -2 * fr->ar * fr->ai + fr->ci;
		if ((fr->nr * fr->nr + fr->ni * fr->ni) > 4)
			break ;
		fr->i++;
	}
}

/*
** Reverse julia with ni = -2 instead of 2
*/

void	zbli(t_fract *fr)
{
	fr->nr = 1.5 * (fr->x - fr->winx / 2) /
		(0.5 * fr->zoom * fr->winx) + fr->mx;
	fr->ni = (fr->y - fr->winy / 2) / (0.5 * fr->zoom * fr->winy) + fr->my;
	fr->i = 0;
	while (fr->i < fr->maxi)
	{
		fr->ar = fr->nr - fr->sx;
		fr->ai = fr->ni + fr->sy;
		fr->nr = fr->ar * fr->ar - fr->ai * fr->ai + fr->cr;
		fr->ni = -2 * fr->ar * fr->ai - fr->ci;
		if ((fr->nr * fr->nr - fr->ni / fr->ni) > 4)
			break ;
		fr->i++;
	}
}

/*
** Reverse julia with ni = -2 instead of 2
*/

void	plume(t_fract *fr)
{
	fr->nr = 1.5 * (fr->x - fr->winx / 2) /
		(0.5 * fr->zoom * fr->winx) + fr->mx;
	fr->ni = (fr->y - fr->winy / 2) / (0.5 * fr->zoom * fr->winy) + fr->my;
	fr->i = 0;
	while (fr->i < fr->maxi)
	{
		fr->ar = fr->nr + fr->sx;
		fr->ai = fr->ni - fr->sy;
		fr->nr = 1.7 * fr->ar * fr->ar - fr->ai * fr->ai + fr->cr;
		fr->ni = 2.8 * fr->ar * fr->ai - fr->ci;
		if ((3 * fr->nr * fr->nr - fr->ni * fr->ni) > 4)
			break ;
		fr->i++;
	}
}
