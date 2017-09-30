/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:38:15 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/30 20:04:31 by vmercadi         ###   ########.fr       */
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
		fr->color = (fr->i * (fr->r * fr->g *fr->b)) % 16581375;
}

/*
** Start the ui and display the menus
*/

void	ui(t_base *base)
{
	int g;

	g = 0x00ff00;
	mlx_string_put(base->mx.mlx, base->mx.win, 10, 
		base->winy - 25, g, "Shorcut = # ");
	mlx_string_put(base->mx.mlx, base->mx.win, 10,
		base->winy - 45, g, "Stats   = $ ");
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
			//ft_putendlcolor("ui()", MAGENTA);
	int		w;

	w = 0xffffff;
	mlx_string_put(base->mx.mlx, base->mx.win, 20, 20, 0x00ff00, "     - KEYS -");
	mlx_string_put(base->mx.mlx, base->mx.win, 20, 50, w, "Quit     =  Esc");
	mlx_string_put(base->mx.mlx, base->mx.win, 20, 70, w, "Reset    =  ~");
	mlx_string_put(base->mx.mlx, base->mx.win, 20, 90, w, "Zoom     =  +  &  -");
	mlx_string_put(base->mx.mlx, base->mx.win, 20, 110, w, "Move     =  Scroll Wheel");
	if (base->mouse)
		mlx_string_put(base->mx.mlx, base->mx.win, 20, 130, w, "SpaceBar =  Mouse ON");
	else
		mlx_string_put(base->mx.mlx, base->mx.win, 20, 130, w, "SpaceBar =  Mouse OFF");
}

/*
** Display the bottom right UI
*/

void	ui2(t_base *base)
{
	int		w;
	int		wx;
	char	*str;

	str = ft_strjoin_free(ft_itoa(base->fr[0].zoom * 100 / INT_MAX), "%");
	w = 0xffffff;
	wx = base->winx - 180;
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 30,
		w, ft_strjoin("Iterations = ", ft_itoa(base->fr[0].maxi)));
	if (base->fr[0].zoom * 10 > 999999999)
		mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 50,
		0xff0000, ft_strjoin("   Zoom    = ", "Over 999B"));
	else
		mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 50,
		w, ft_strjoin("   Zoom    = ", str));
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 70,
		w, ft_strjoin("    R      = ", ft_itoa(base->frfr.r)));
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 90,
		w, ft_strjoin("    G      = ", ft_itoa(base->frfr.g)));
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 110,
		w, ft_strjoin("    B      = ", ft_itoa(base->frfr.b)));
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 140,
		0x00ff00, "     - STATS -");

}
