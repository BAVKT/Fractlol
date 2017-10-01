/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:38:15 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/01 18:51:38 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Print the pixel in the image
*/

void	px_img(t_fract *fr)
{
	if (fr->x > fr->winx || fr->x < 0 || fr->y > fr->winy || fr->y < 0)
		return ;
	fr->data[fr->y * fr->winx + fr->x] = fr->color;
}

/*
** return the color needed for the pixel
*/

void	get_color(t_fract *fr)
{
	if (fr->i >= fr->maxi)
		fr->color = 0;
	else
		fr->color = (fr->i * (fr->r * fr->g * fr->b)) % 16581375;
}

/*
** Start the ui, display the menus and the fractal name
*/

void	ui(t_base *base)
{
	get_name(base);
	mlx_string_put(base->mx.mlx, base->mx.win, (base->winx -
		(ft_strlen(base->name) * 10) - 10), 5, 0xffffff, base->name);
	mlx_string_put(base->mx.mlx, base->mx.win, 10,
		base->winy - 25, W, "Shorcut = # ");
	mlx_string_put(base->mx.mlx, base->mx.win, 10,
		base->winy - 45, W, "Stats   = $ ");
	if (base->ui1)
		ui1(base);
	if (base->ui2)
		ui2(base);
}

/*
** Display the upper left UI on the window
*/

void	ui1(t_base *base)
{
	void	*w;
	void	*mx;

	w = base->mx.win;
	mx = base->mx.mlx;
	mlx_string_put(mx, w, 20, 20, G, "     - KEYS -");
	mlx_string_put(mx, w, 20, 50, W, "Quit     =  Esc");
	mlx_string_put(mx, w, 20, 70, W, "Reset    =  R");
	mlx_string_put(mx, w, 20, 90, W, "Fractal  =  <  &  >");
	mlx_string_put(mx, w, 20, 110, W, "Zoom     =  +  &  -");
	mlx_string_put(mx, w, 20, 130, W, "Move     =  Scroll Wheel");
	if (base->mouse)
		mlx_string_put(mx, w, 20, 150, W, "SpaceBar =  Mouse     [ON]");
	else
		mlx_string_put(mx, w, 20, 150, W, "SpaceBar =  Mouse     [OFF]");
	if (base->autoiter)
		mlx_string_put(mx, w, 20, 170, W, "Enter    =  Auto-iter [ON]");
	else
		mlx_string_put(mx, w, 20, 170, W, "Enter    =  Auto-iter [OFF]");
}

/*
** Display the bottom right UI
*/

void	ui2(t_base *base)
{
	int		wx;
	char	*str;

	str = ft_strjoin_free(ft_itoa(base->fr[0].zoom * 100 / INT_MAX), "%");
	wx = base->winx - 180;
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 30,
		W, ft_strjoin("Iterations = ", ft_itoa(base->fr[0].maxi)));
	if (base->fr[0].zoom * 10 > 999999999999)
		mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 50,
		0xff0000, ft_strjoin("   Zoom    = ", "Over 999M"));
	else
		mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 50,
		W, ft_strjoin("   Zoom    = ", str));
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 70,
		W, ft_strjoin("    R      = ", ft_itoa(base->frfr.r)));
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 90,
		W, ft_strjoin("    G      = ", ft_itoa(base->frfr.g)));
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 110,
		W, ft_strjoin("    B      = ", ft_itoa(base->frfr.b)));
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 140,
		0x00ff00, "     - STATS -");
}
