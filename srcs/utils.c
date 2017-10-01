/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:48:54 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/01 18:51:39 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Multi-threading
*/

void	mthread(t_base *base)
{
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
** Return the the letter corresponding to the fractal
*/

void	get_fractal(char *av, t_fract *fr)
{
	if (!ft_strcmp(av, "Julia") || !ft_strcmp(av, "j") ||
		!ft_strcmp(av, "julia") || !ft_strcmp(av, "J"))
		fr->j = 0;
	else if (!ft_strcmp(av, "Mandelbrot") || !ft_strcmp(av, "m") ||
			!ft_strcmp(av, "mandelbrot") || !ft_strcmp(av, "M"))
		fr->j = 1;
	else
		error(2);
}

/*
** Return the name of the current fractal
*/

void	get_name(t_base *base)
{
	if (base->frac == 0)
		base->name = ft_strdup("Mandelbrot");
	else if (base->frac == 1)
		base->name = ft_strdup("Julia");
	else if (base->frac == 2)
		base->name = ft_strdup("Reversebrot");
	else if (base->frac == 3)
		base->name = ft_strdup("Reversejulia");
	else if (base->frac == 4)
		base->name = ft_strdup("Cell");
	else if (base->frac == 5)
		base->name = ft_strdup("Zbli");
	else if (base->frac == 6)
		base->name = ft_strdup("Plumes");
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
	else if (e == 4)
		ft_putendl_fd("Multithreading failed.", 2);
	exit(1);
}

/*
** Free all the tabs needed
*/

int		clean(t_base *base)
{
	mlx_destroy_window(base->mx.mlx, base->mx.win);
	mlx_destroy_image(base->mx.mlx, base->mx.img);
	ft_strdel(&base->name);
	exit(0);
	return (0);
}
