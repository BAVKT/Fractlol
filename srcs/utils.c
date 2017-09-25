/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:48:54 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/25 17:04:39 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Return the the letter corresponding to the fractal
*/

void	get_fractal(char *av, t_fract *fr)
{
			ft_putendlcolor("get_fractal()", MAGENTA);
	if (!ft_strcmp(av, "Julia") || !ft_strcmp(av, "j") ||
		!ft_strcmp(av, "julia") || !ft_strcmp(av, "J"))
		fr->j = 0;
	else if (!ft_strcmp(av, "Mandelbrot") || !ft_strcmp(av, "m") ||
			!ft_strcmp(av, "mandelbrot") || !ft_strcmp(av, "M"))
		fr->j = 1;
	else if (!ft_strcmp(av, "Buddhabrot") || !ft_strcmp(av, "b") ||
			!ft_strcmp(av, "buddhabrot") || !ft_strcmp(av, "B"))
		fr->j = 2;
	else if (!ft_strcmp(av, "Sierpinski") || !ft_strcmp(av, "s") ||
			!ft_strcmp(av, "sierpinski") || !ft_strcmp(av, "S"))
		fr->j = 3;
	else
		error(2);
}

/*
** All the error messages
*/

void	error(int e)
{
	if (e == 0)
	{
		ft_putendl_fd("Usage : ./fractol FractalName", 2);		
		exit(1);
	}
	ft_putstr_fd("Error : ", 2);
	if (e == 1)
		ft_putendl_fd("Wrong number of arguments.", 2);
	else if (e == 2)
		ft_putendl_fd("Wrong fractal name.", 2);
	else if (e == 3)
		ft_putendl_fd("ECHEC CRITIK", 2);
	exit(1);
}

/*
** Free all the tabs needed
*/

void	clean(t_base *base)
{
	mlx_destroy_window(base->mx.mlx, base->mx.win);
	mlx_destroy_image(base->mx.mlx, base->mx.img);
	exit(0);
}

// /*
// ** Multi-threading
// */

// void	mthread()
// {
//     pthread_t	th[8];
//     int			i;

//     i = 0;
//     while (i < 8)
// 	    pthread_create(&th[i++], NULL, julia, NULL);

// }
