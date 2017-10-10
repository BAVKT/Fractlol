/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:29:39 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/10 17:23:48 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Return the the letter corresponding to the fractal
*/

int		get_fractal(char *av)
{
	int j;

	j = 0;
	if (!ft_strcmp(av, "Julia") || !ft_strcmp(av, "j") ||
		!ft_strcmp(av, "julia") || !ft_strcmp(av, "J"))
		j = 0;
	else if (!ft_strcmp(av, "Mandelbrot") || !ft_strcmp(av, "m") ||
			!ft_strcmp(av, "mandelbrot") || !ft_strcmp(av, "M"))
		j = 1;
	else if (!ft_strcmp(av, "Reversebrot") || !ft_strcmp(av, "rb") ||
			!ft_strcmp(av, "reversebrot") || !ft_strcmp(av, "RB"))
		j = 2;
	else if (!ft_strcmp(av, "Reversejulia") || !ft_strcmp(av, "rj") ||
			!ft_strcmp(av, "reversejulia") || !ft_strcmp(av, "RJ"))
		j = 3;
	else if (!ft_strcmp(av, "Spark") || !ft_strcmp(av, "s") ||
			!ft_strcmp(av, "spark") || !ft_strcmp(av, "S"))
		j = 4;
	else if (!ft_strcmp(av, "zbli") || !ft_strcmp(av, "Z"))
		j = 5;
	else if (!ft_strcmp(av, "plumes") || !ft_strcmp(av, "P"))
		j = 6;
	else
		error(2);
	return (j);
}

/*
** Init and start the fractal needed
*/

void	*start_draw(void *tmp)
{
	t_fract *fr;
	int		x;

	fr = (t_fract*)tmp;
	x = fr->x;
	while (fr->y < fr->twiny)
	{
		fr->x = x;
		while (fr->x < fr->winx)
		{
			fr->nr = 0;
			fr->ni = 0;
			fr->ar = 0;
			fr->ai = 0;
			fr->i = 0;
			init_tab(fr);
			fr->tab[fr->j]((void *)fr);
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

void	julia(void *f)
{
	t_fract *fr;

	fr = (t_fract *)f;
	fr->nr = 1.5 * (fr->x - fr->winx / 2) /
		(0.5 * fr->zoom * fr->winx) + fr->mx;
	fr->ni = (fr->y - fr->winy / 2) / (0.5 * fr->zoom * fr->winy) + fr->my;
	fr->i = 0;
	fr->cr = 0.285 + fr->sx;
	fr->ci = 0.01 + fr->sy;
	while (fr->i < fr->maxi)
	{
		fr->ar = fr->nr;
		fr->ai = fr->ni;
		fr->nr = fr->ar * fr->ar - fr->ai * fr->ai + fr->cr;
		fr->ni = 2 * fr->ar * fr->ai + fr->ci;
		if ((fr->nr * fr->nr + fr->ni * fr->ni) > 4)
			break ;
		fr->i++;
	}
}

/*
** Algorithm for the Mandelbrot fractal
*/

void	mandelbrot(void *f)
{
	t_fract *fr;

	fr = (t_fract *)f;
	fr->cr = 1.5 * (fr->x - fr->winx / 2) /
		(0.5 * fr->zoom * fr->winx) + fr->mx;
	fr->ci = (fr->y - fr->winy / 2) / (0.5 * fr->zoom * fr->winy) + fr->my;
	while (fr->i < fr->maxi)
	{
		fr->ar = fr->nr + fr->sx;
		fr->ai = fr->ni + fr->sy;
		fr->nr = fr->ar * fr->ar - fr->ai * fr->ai + fr->cr;
		fr->ni = 2 * fr->ar * fr->ai + fr->ci;
		if ((fr->nr * fr->nr + fr->ni * fr->ni) > 4)
			break ;
		fr->i++;
	}
}
