/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:38:11 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/19 19:11:50 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	px_img(t_base *base, int x, int y, int color)
{
	if (x > base->winx || x < 0 || y > base->winy || y < 0)
		return ;
	base->mx.data[y * base->winx + x] = color;
}

void	get_color(t_fract *fr, int i)
{
	double q;

	q = (double)i / (double)fr->maxi;
	if (i <= fr->maxi)
		fr->color = 0x00ff00;
	if (q > 0.5)
	    fr->color = (fr->color >> 8 | fr->color << 16);
	else
	    fr->color = (fr->color >> 8);
}

void	draw(t_base *base, t_fract *fr)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < base->winy)
	{
		x = 0;
		while (x < base->winx)
		{
			fr->nr = 1.5 * (x - base->winx / 2) / (0.5 * fr->zoom * base->winx) + fr->mx;
			fr->ni = (y - base->winy / 2) / ( 0.5 * fr->zoom * base->winy) + fr->my;
			i = 0;
			while (i < fr->maxi)
			{
				fr->ar = fr->nr;
				fr->ai = fr->ni;
				fr->nr = fr->ar * fr->ar - fr->ai * fr->ai + fr->cr;
				fr->ni = 2 * fr->ar * fr->ai + fr->ci;
      			if((fr->nr * fr->nr + fr->ni * fr->ni) > 4)
      				break;
      			i++;
			}
			x++;
			get_color(fr, i);
			px_img(base, x, y, fr->color);
		}
		y++;
	}
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
void	init_base(t_base *base)
{
			ft_putendlcolor("init_base()", MAGENTA);
	// base->name = get_fractal(av);
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



/*
t_fract	init_fract()
{
	t_fract fr;

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

void	init_base(t_base *base)
{
	base->fr = init_fract();
	base->winx = 2000;
	base->winy = 1200;
	base->mx.bpp = 8;
	base->mx.endian = 0;
	base->mx.sizeline = base->winy;
	base->mx.mlx = mlx_init();
	base->mx.win = mlx_new_window(base->mx.mlx, base->winx, base->winy, "Fractlol");
	base->mx.img = mlx_new_image(base->mx.mlx, base->winx, base->winy);
	base->mx.data = (int*)mlx_get_data_addr(base->mx.img, &base->mx.bpp, &base->mx.sizeline, &base->mx.endian);
	mlx_string_put(base->mx.mlx, base->mx.win, (base->winx / 2) - 100,
		 (base->winy / 2) - 20, 0xffffff, "PLEASE WAIT...");
	mlx_put_image_to_window(base->mx.mlx, base->mx.win, base->mx.img, 0, 0);
}
*/
int		main()
{
	t_base base;
	init_base(&base);
	draw(&base, &base.fr);
	mlx_put_image_to_window(base.mx.mlx, base.mx.win, base.mx.img, 0, 0);
	mlx_loop(base.mx.mlx);
	return (0);
}