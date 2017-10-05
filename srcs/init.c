/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:32:42 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/05 16:28:03 by vmercadi         ###   ########.fr       */
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
** Return the name of the current fractal
*/

void	get_name(t_base *base)
{
	if (base->j == 0)
		base->name = ft_strdup("Julia");
	else if (base->j == 1)
		base->name = ft_strdup("Mandelbrot");
	else if (base->j == 2)
		base->name = ft_strdup("Reversebrot");
	else if (base->j == 3)
		base->name = ft_strdup("Reversejulia");
	else if (base->j == 4)
		base->name = ft_strdup("Spark");
	else if (base->j == 5)
		base->name = ft_strdup("Zbli");
	else if (base->j == 6)
		base->name = ft_strdup("Plumes");
}

void	init_base(t_base *base, char *av)
{
	base->av = ft_strdup(av);
	base->winx = WINX;
	base->winy = WINY;
	base->mx.bpp = 8;
	base->mx.endian = 0;
	base->win_size = base->winx * base->winy;
	base->mouse = 1;
	base->ui1 = 0;
	base->ui2 = 0;
	base->ui3 = 0;
	base->mx.sizeline = base->winy;
	base->frfr = init_fract(base);
	base->j = get_fractal(av);
	base->hide = 0;
	base->autoiter = 0;
	base->mx.mlx = mlx_init();
	base->mx.win = mlx_new_window(
		base->mx.mlx, base->winx, base->winy, "Fractol");
	base->mx.img = mlx_new_image(base->mx.mlx, base->winx, base->winy);
	base->mx.data = (int*)mlx_get_data_addr(
		base->mx.img, &base->mx.bpp, &base->mx.sizeline, &base->mx.endian);
	mlx_string_put(base->mx.mlx, base->mx.win, (base->winx / 2) - 100,
		(base->winy / 2) - 20, 0xffffff, "PLEASE WAIT...");
	mlx_put_image_to_window(base->mx.mlx, base->mx.win, base->mx.img, 0, 0);
}

t_fract	init_fract(t_base *base)
{
	t_fract	fr;

	fr.x = 0;
	fr.y = 0;
	fr.i = 0;
	fr.j = base->j;
	fr.mx = 0.0;
	fr.my = 0.0;
	fr.sx = 0.0;
	fr.sy = 0.0;
	fr.r = 230;
	fr.g = 105;
	fr.b = 250;
	fr.zoom = 1.0;
	fr.yolo = 0;
	fr.cr = 0.285;
	fr.maxi = 10;
	fr.ci = 0.1;
	fr.badtrip = 0;
	fr.posx = base->winx / 2;
	fr.posy = base->winy / 2;
	return (fr);
}

/*
** Make a copie of the struct fr for each thread
*/

t_fract	init_fracthr(t_base *base)
{
	t_fract	fr;

	fr.j = base->j;
	fr.i = base->frfr.i;
	fr.x = base->frfr.x;
	fr.y = base->frfr.y;
	fr.r = base->frfr.r;
	fr.g = base->frfr.g;
	fr.b = base->frfr.b;
	fr.mx = base->frfr.mx;
	fr.my = base->frfr.my;
	fr.sx = base->frfr.sx;
	fr.sy = base->frfr.sy;
	fr.cr = -base->frfr.cr;
	fr.ci = base->frfr.ci;
	fr.winx = base->winx;
	fr.winy = base->winy;
	fr.data = base->mx.data;
	fr.zoom = base->frfr.zoom;
	fr.maxi = base->frfr.maxi;
	fr.posx = base->frfr.posx;
	fr.posy = base->frfr.posy;
	fr.yolo = base->frfr.yolo;
	fr.badtrip = base->frfr.badtrip;
	return (fr);
}
