/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:38:11 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/19 17:37:05 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Call the fractal given in arg
*/

void	fractol(t_base *base)
{	
			ft_putendlcolor("fractol()", MAGENTA);
	if (base->name == 'j')
		julia(base, &base->fr);
/*	else if (base->name == 'm')
		mandelbrot(base, &base->fr);
	else if (base->name == 'b')
		buddhabrot(base, &base->fr);
*/	mlx_put_image_to_window(base->mx.mlx, base->mx.win, base->mx.img, 0, 0);
	ui(base);
	mlx_hook(base->mx.win, 2, 0, event, base);
	mlx_loop(base->mx.mlx);
}

int		main(int ac, char **av)
{
	t_base base;

	if (ac != 2)
		error(1);
	init_base(&base, av[1]);
	fractol(&base);
	return (0);
}