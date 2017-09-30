/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:42:28 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/30 20:00:34 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
		#include <stdio.h>

/*
** Catch the mouses movments
*/

int		evmv_mouse(int x, int y, t_base *base)
{
	if (base->mouse)
	{
		base->frfr.sx = (((double)x - base->winx / 2) / 150);
		base->frfr.sy = (((double)y - base->winy / 2) / 150);
		// base->frfr.nr = -0.5 + (double)x / base->winx;
        // base->frfr.ni = -0.5 + (double)y / base->winy;
	}
	refresh(base);
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
	if (k == 1)
		base->frfr.color = (x + y) / 255;
	else if (k == 4)
		base->frfr.zoom += 0.1 * base->frfr.zoom;
	else if (k == 4)
		base->frfr.zoom += 0.1 * base->frfr.zoom;
	else if (k == 5)
		base->frfr.zoom -= 0.1 * base->frfr.zoom;
	refresh(base);
	return (0);
}

/*
** Move events, iterations & zoom
*/

void	ev_move(int k, t_base *base)
{
			// ft_putendlcolor("ev_move()", MAGENTA);
	if (k == 69)
		base->frfr.zoom += 0.2 * base->frfr.zoom;
	else if (k == 78 && base->frfr.zoom > 0.2)
		base->frfr.zoom -= 0.2 * base->frfr.zoom;
	else if (k == 67 && base->frfr.maxi < 200)
		base->frfr.maxi += 1;
	else if (k == 75 && base->frfr.maxi > 5)
		base->frfr.maxi -= 1;
	else if (k == 126)
		base->frfr.my -= 0.2 / base->frfr.zoom;
	else if (k == 125)
		base->frfr.my += 0.2 / base->frfr.zoom;
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
			// ft_putendlcolor("ev_else()", MAGENTA);
	if (k == 53)
		clean(base);
	else if (k == 50 || k == 38 || k == 46)
		base->frfr = init_fract(base);
	else if (k == 86)
		base->frfr.r += 5;
	else if (k == 87)
		base->frfr.g += 5;
	else if (k == 88)
		base->frfr.b += 5;
	else if (k == 83)
		base->frfr.r -= 5;
	else if (k == 84)
		base->frfr.g -= 5;
	else if (k == 85)
		base->frfr.b -= 5;
	else if (k == 49)
		base->mouse = (base->mouse == 1) ? 0 : 1;
	if (k == 38)
		base->frfr.j = 0;
	if (k == 46)
		base->frfr.j = 1;
	refresh(base);
}

/*
** Redirect the events and show/hide menus
*/

int		event(int k, void *param)
{
			// ft_putendlcolor("event", MAGENTA);
	t_base *base;
		
	base = (t_base *)param;
	if (k == 20)
		base->ui1 = (base->ui1 == 0) ? 1 : 0;
	else if (k == 21)
		base->ui2 = (base->ui2 == 0) ? 1 : 0;
	else if (k == 126 || k == 125 || k == 124 || k == 123 || k == 78 || k == 69
		|| k == 75 || k == 67)
		ev_move(k, base);
	else if (k == 83 || k == 84 || k == 85 || k == 49 || k == 53 || k == 50
		|| k == 38 || k == 46 || k == 86 || k == 87 || k == 88)
		ev_else(k, base);
	refresh(base);
	return (0);
}
