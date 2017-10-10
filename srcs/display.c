/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:38:15 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/10 17:23:40 by vmercadi         ###   ########.fr       */
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
** Start the ui, display the menus and the fractal name
*/

void	ui(t_base *base)
{
	if (base->hide)
	{
		mlx_string_put(base->mx.mlx, base->mx.win, 5, 5, W, "[H]");
		return ;
	}
	get_name(base);
	mlx_string_put(base->mx.mlx, base->mx.win, (base->winx -
		(ft_strlen(base->name) * 10) - 10), 5, 0xffffff, base->name);
	ft_strdel(&base->name);
	mlx_string_put(base->mx.mlx, base->mx.win, 10,
		base->winy - 25, W, "Hide all = H ");
	mlx_string_put(base->mx.mlx, base->mx.win, 10,
		base->winy - 45, W, "Shorcut  = # ");
	mlx_string_put(base->mx.mlx, base->mx.win, 10,
		base->winy - 65, W, "Stats    = $ ");
	if (base->ui1)
		ui1(base);
	if (base->ui2)
	{
		ui3(base);
		ui4(base);
	}
}

/*
** Upper left UI on the window
*/

void	ui1(t_base *base)
{
	void	*w;
	void	*mx;

	w = base->mx.win;
	mx = base->mx.mlx;
	mlx_string_put(mx, w, 20, 20, G, "     - KEYS -");
	mlx_string_put(mx, w, 20, 50, W, "Quit      = Esc");
	mlx_string_put(mx, w, 20, 70, W, "Reset     = R");
	mlx_string_put(mx, w, 20, 90, W, "Move      = Arows");
	mlx_string_put(mx, w, 20, 110, W, "Iteration = *  &  /");
	mlx_string_put(mx, w, 20, 130, W, "Fractal   = <  &  >");
	mlx_string_put(mx, w, 20, 150, W, "Zoom      = +  &  -  &  Scroll");
	(base->mouse) ? mlx_string_put(mx, w, 20, 170, W,
	"Woah      = SpaceBar [ON]") : mlx_string_put(mx, w, 20, 170, W,
	"Woah      = SpaceBar [OFF]");
	(base->frfr.yolo) ? mlx_string_put(mx, w, 20, 190, W,
	"Yolo      = Y        [ON]") : mlx_string_put(mx, w, 20, 190, W,
	"Yolo      = Y        [OFF]");
	(base->autoiter) ? mlx_string_put(mx, w, 20, 210, W,
	"Auto-iter = Enter    [ON]") : mlx_string_put(mx, w, 20, 210, W,
	"Auto-iter = Enter    [OFF]");
	(base->frfr.badtrip) ? mlx_string_put(mx, w, 20, 230, W,
	"Badtrip   = Delete   [ON]") : mlx_string_put(mx, w, 20, 230, W,
	"Badtrip   = Delete   [OFF]");
}

/*
** Bottom right UI
*/

void	ui3(t_base *base)
{
	int		wx;
	char	*str;
	char	*t;

	str = ft_strjoin_free(ft_itoa(base->fr[0].zoom * 100 / INT_MAX), "%");
	wx = base->winx - 180;
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 30,
		W, (t = ft_strjoin_free2("Iterations = ", ft_itoa(base->fr[0].maxi))));
	ft_strdel(&t);
	if (base->fr[0].zoom * 10 > 999999999999)
		mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 50,
		0xff0000, ft_strjoin_free("   Zoom    = ", "Over"));
	else
		mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 50,
		W, (t = ft_strjoin_free2("   Zoom    = ", str)));
	ft_strdel(&t);
}

/*
** New UI because SHITTY LEAKS ARE SHITTY
*/

void	ui4(t_base *base)
{
	int		wx;
	char	*tmp;

	wx = base->winx - 180;
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 70,
		W, (tmp = ft_strjoin_free2("    R      = ", ft_itoa(base->frfr.r))));
	ft_strdel(&tmp);
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 90,
		W, (tmp = ft_strjoin_free2("    G      = ", ft_itoa(base->frfr.g))));
	ft_strdel(&tmp);
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 110,
		W, (tmp = ft_strjoin_free2("    B      = ", ft_itoa(base->frfr.b))));
	ft_strdel(&tmp);
	mlx_string_put(base->mx.mlx, base->mx.win, wx, base->winy - 140,
		0x00ff00, "     - STATS -");
}
