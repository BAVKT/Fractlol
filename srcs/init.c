/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:32:42 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/19 19:11:54 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_base(t_base *base, char *av)
{
			ft_putendlcolor("init_base()", MAGENTA);
	base->name = get_fractal(av);
	base->fr = init_fract();
	base->winx = 2000;
	base->winy = 1200;
	base->mx.bpp = 8;
	base->mx.endian = 0;
	base->win_size = base->winx * base->winy;
	base->mx.sizeline = base->winy;
	base->mx.mlx = mlx_init();
	base->mx.win = mlx_new_window(base->mx.mlx, base->winx, base->winy, "Fractlol");
	base->mx.img = mlx_new_image(base->mx.mlx, base->winx, base->winy);
	base->mx.data = (int*)mlx_get_data_addr(base->mx.img,&base->mx.bpp, &base->mx.sizeline, &base->mx.endian);
	mlx_string_put(base->mx.mlx, base->mx.win, (base->winx / 2) - 100,
		 (base->winy / 2) - 20, 0xffffff, "PLEASE WAIT...");
	mlx_put_image_to_window(base->mx.mlx, base->mx.win, base->mx.img, 0, 0);
}

t_fract	init_fract()
{
			ft_putendlcolor("init_fract()", MAGENTA);
	t_fract fr;

	fr.x = 0;
	fr.y = 0;
	fr.i = 0;
	fr.nr = 0;
	fr.ni = 0;
	fr.ar = 0;
	fr.ai = 0;
	fr.mx = 0;
	fr.my = 0;
	fr.zoom = 1;
	fr.cr = - 0.7;
	fr.maxi = 250;
	fr.ci = 0.27015;
	fr.color = 0xffffff;
	return (fr);
}
