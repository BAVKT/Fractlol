/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:42:28 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/28 17:42:51 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Catch the mouses movments
*/

int		evmv_mouse(int x, int y, t_base *base)
{
	x = y = base->winx;
	// base->frfr.sx = (((long double)x - base->winx / 2) / 150);
	// base->frfr.sy = (((long double)y - base->winy / 2) / 150);
	// 	ft_putnbrendl(base->frfr.sx);
	// 	ft_putnbrendl(base->frfr.sy);
	// refresh(base);
	return (0);
}

/*
** Mouse events
*/

int		ev_mouse(int k, int x, int y, void *param)
{
			 // ft_putendlcolor("ev_mouse()", MAGENTA);			
	t_base *base;
		
	base = (t_base *)param;
	if (k == 5555)
		x = 0;
	y = 0;
			// ft_putnbrendl(k);
			// ft_putnbrendl(x);
			// ft_putnbrendl(y);
	refresh(base);
	return (0);
}

/*
** Move events, iterations & zoom
*/

void	ev_move(int k, t_base *base)
{
			//ft_putendlcolor("ev_move()", MAGENTA);
	if (k == 69)
		base->frfr.zoom += 0.1 * base->frfr.zoom;
	else if (k == 78 && base->frfr.zoom > 0.2)
		base->frfr.zoom -= 0.1 * base->frfr.zoom;
	else if (k == 67 && base->frfr.maxi < 200)
		base->frfr.maxi += 1;
	else if (k == 75 && base->frfr.maxi > 5)
		base->frfr.maxi -= 1;
	else if (k == 126)
		base->frfr.my += 0.2 / base->frfr.zoom;
	else if (k == 125)
		base->frfr.my -= 0.2 / base->frfr.zoom;
	else if (k == 124)
		base->frfr.mx += 0.2 / base->frfr.zoom;
	else if (k == 123)
		base->frfr.mx -= 0.2 / base->frfr.zoom;
	refresh(base);

}

/*
** Other events : Quit, choose fractal, change color, reinit 
*/

void	ev_else(int k, t_base *base)
{
			ft_putendlcolor("ev_else()", MAGENTA);
	if (k == 53)
		clean(base);
	else if (k == 50 || k == 38 || k == 46)
		base->frfr = init_fract(base);
	else if (k == 83)
		base->frfr.color = 0xff;
	else if (k == 84)
		base->frfr.color = 0xee;
	else if (k == 85)
		base->frfr.color = 0xbb;
	else if (k == 86)
		base->frfr.color = 0xaa;
	if (k == 38)
		base->frfr.j = 0;
	if (k == 46)
		base->frfr.j = 1;
	refresh(base);
}

/*
** Redirect the events
*/

int		event(int keycode, void *param)
{
			// ft_putendlcolor("event", MAGENTA);
	t_base *base;
		
	base = (t_base *)param;
			//ft_putnbrendl(keycode);
	if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123
		|| keycode == 78 || keycode == 69 || keycode == 75 || keycode == 67)
		ev_move(keycode, base);
	else if (keycode == 83 || keycode == 84 || keycode == 85 || keycode == 86
		|| keycode == 53 || keycode == 50 || keycode == 38 || keycode == 46)
		ev_else(keycode, base);
	return (0);
}
