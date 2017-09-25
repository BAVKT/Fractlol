/* ************************************************************************** */
/*						                                                      */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:39:23 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/20 13:22:37 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Multi-threading
*/

void	mthread(t_base *base)
{
			ft_putendlcolor("mthread()", MAGENTA);
	pthread_t	*th;
	t_base		*tmp;
	int			max;
	int			i;
	int			j;

	i = 0;
	j = 4;
	max = j;
	tmp = base;
	th = (pthread_t *)malloc(sizeof(pthread_t) * j);
	while (i < 4)
	{
		tmp->fr.x = i * (base->winx / max);
		tmp->winx /= j;
		tmp->fr.y = i * (base->winy / max);
		tmp->winy /= j;
		pthread_create(&th[i], NULL, start_draw, NULL);
		i++;
		j--;
	}
	pthread_join(start_draw, NULL);
}

/*
** Init and start the fractal
*/

void	start_draw(t_base *base)
{
			//ft_putendlcolor("Start_fract()", MAGENTA);
	int x;

	x = base->fr.x;
	base->fr.mx = (base->fr.j == 1) ? -0.5 : base->fr.mx;
	while (base->fr.y < base->winy)
	{
		base->fr.x = x;
		while (base->fr.x < base->winx)
		{
			base->fr.nr = 0;
			base->fr.ni = 0;
			base->fr.ar = 0;
			base->fr.ai = 0;
			base->fr.i = 0;
			tab_fr[base->fr.j](base, &base->fr);
			get_color(&base->fr);
			px_img(base, &base->fr);
			base->fr.x++;
		}
		base->fr.y++;
	}
}

/*
** Algorithm for the Julia fractal
*/

void	julia(t_base *base, t_fract *fr)
{
			//ft_putendlcolor("Julia()", MAGENTA);
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
	}
}

/*
** Algorithm for the Mandelbrot fractal
*/

void	mandelbrot(t_base *base, t_fract *fr)
{
			// ft_putendlcolor("Mandelrot()", MAGENTA);
	fr->cr = 1.5 * (fr->x - base->winx / 2) / (0.5 * fr->zoom * base->winx) + fr->mx;
	fr->ci = (fr->y - base->winy / 2) / (0.5 * fr->zoom * base->winy) + fr->my;
	while(fr->i < fr->maxi)
	{
		fr->ar = fr->nr;
		fr->ai = fr->ni;
		fr->nr = fr->ar * fr->ar - fr->ai * fr->ai + fr->cr;
		fr->ni = 2 * fr->ar * fr->ai + fr->ci;
		if((fr->nr * fr->nr + fr->ni * fr->ni) > 4 )
			break;
		fr->i++;
	}
}
	