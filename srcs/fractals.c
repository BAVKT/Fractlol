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
			// ft_putendlcolor("mthread()", MAGENTA);
	pthread_t	th[NBTH];
	int			i;
	int			size;

	i = 0;
	size = base->winy / NBTH;
	while (i < NBTH)
	{
		base->fr[i] = init_fracthr(base);
		base->fr[i].y = i * size;
		base->fr[i].twiny = (i + 1) * size;
		if (pthread_create(&th[i], NULL, start_draw, (void *)&base->fr[i]))
			error(4);
		i++;
	}
	i = 0;
	while (i < NBTH)
		pthread_join(th[i++], NULL);
}

/*
** Init and start the fractal
*/

void	*start_draw(void *tmp)
{
			//ft_putendlcolor("Start_fract()", MAGENTA);
	t_fract *fr;

	fr = (t_fract*)tmp;
	fr->y = 0;
	while (fr->y < fr->twiny)
	{
		fr->x = 0;
		while (fr->x < fr->winx)
		{
			fr->nr = 0;
			fr->ni = 0;
			fr->ar = 0;
			fr->ai = 0;
			fr->i = 0;
			tab_fr[fr->j](fr);
			get_color(fr);
			px_img(fr);
			fr->x++;
		}
		fr->y++;
	}
	pthread_exit(0);
}

/*
** Algorithm for the Julia fractal
*/

void	julia(t_fract *fr)
{
			//ft_putendlcolor("Julia()", MAGENTA);
	fr->nr = 1.5 * (fr->x - fr->winx / 2) / (0.5 * fr->zoom * fr->winx) + fr->mx;
	fr->ni = (fr->y - fr->winy / 2) / (0.5 * fr->zoom * fr->winy) + fr->my;
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

void	mandelbrot(t_fract *fr)
{
			// ft_putendlcolor("Mandelrot()", MAGENTA);
	fr->cr = 1.5 * (fr->x - fr->winx / 2) / (0.5 * fr->zoom * fr->winx) + fr->mx;
	fr->ci = (fr->y - fr->winy / 2) / (0.5 * fr->zoom * fr->winy) + fr->my;
	while(fr->i < fr->maxi)
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