/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:48:54 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/19 19:12:19 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Return the the letter corresponding to the fractal
*/

char	get_fractal(char *av)
{
			ft_putendlcolor("get_fractal()", MAGENTA);
	char c;

	c = 'y';
	if (!ft_strcmp(av, "Julia") || !ft_strcmp(av, "julia") ||
			!ft_strcmp(av, "J"))
		c = 'j';
	else if (!ft_strcmp(av, "Mandelbrot") || 
			!ft_strcmp(av, "mandelbrot") || !ft_strcmp(av, "M"))
		c = 'm';
	else if (!ft_strcmp(av, "Buddhabrot") || 
			!ft_strcmp(av, "buddhabrot") || !ft_strcmp(av, "B"))
		c = 'b';
	else
		error(2);
	return (c);
}

/*
** All the error messages
*/

void	error(int e)
{
	ft_putstr_fd("Error : ", 2);
	if (e == 0)
		ft_putendl_fd("Usage : ./fractol FractalName", 2);		
	else if (e == 1)
		ft_putendl_fd("Wrong number of arguments.", 2);
	else if (e == 2)
		ft_putendl_fd("Wrong fractal name.", 2);
	exit(1);
}

/*
** Free all the tabs
*/

void	clean(t_base *base)
{
	mlx_destroy_window(base->mx.mlx, base->mx.win);
	mlx_destroy_image(base->mx.mlx, base->mx.img);
	exit(0);
}
