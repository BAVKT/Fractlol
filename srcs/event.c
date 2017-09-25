/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:42:28 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/25 21:27:21 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Clear the current image, draw the new one and display it
*/

void	refresh(t_base *base)
{
			 ft_putendlcolor("refresh()", MAGENTA);
	// start_draw(base, &base->fr);
	mthread(base);
	mlx_put_image_to_window(base->mx.mlx, base->mx.win, base->mx.img, 0, 0);
	ui(base);
}

/*
** Move events & zoom
*/

void	ev_move(int k, t_base *base)
{
			ft_putendlcolor("ev_move()", MAGENTA);
	if (k == 69)
		base->fr.zoom += 0.1;
	else if (k == 78)
		base->fr.zoom -= 0.1;
	else if (k == 67 && base->fr.maxi < 100)
		base->fr.maxi += 2;
	else if (k == 75 && base->fr.maxi > 5)
		base->fr.maxi -= 2;
	else if (k == 126)
		base->fr.my += 0.1 / base->fr.zoom;
	else if (k == 125)
		base->fr.my -= 0.1 / base->fr.zoom;
	else if (k == 124)
		base->fr.mx += 0.1 / base->fr.zoom;
	else if (k == 123)
		base->fr.mx -= 0.1 / base->fr.zoom;
}

/*
** Other events
*/

void	ev_else(int k, t_base *base)
{
			ft_putendlcolor("ev_else()", MAGENTA);
	if (k == 53)
		clean(base);
	else if (k == 50 || k == 38 || k == 46)
		base->fr = init_fract();
	else if (k == 83)
		base->fr.color = 0xff;
	else if (k == 84)
		base->fr.color = 0xee;
	else if (k == 85)
		base->fr.color = 0xbb;
	else if (k == 86)
		base->fr.color = 0xaa;
	if (k == 38)
		base->fr.j = 0;
	if (k == 46)
		base->fr.j = 1;
}
/*
** Redirect the events
*/

int		event(int keycode, void *param)
{
			// ft_putendlcolor("event", MAGENTA);
	t_base *base;
		
	base = (t_base *)param;
			ft_putnbrendl(keycode);
	if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123
		|| keycode == 78 || keycode == 69 || keycode == 75 || keycode == 67)
		ev_move(keycode, base);
	else if (keycode == 83 || keycode == 84 || keycode == 85 || keycode == 86
		|| keycode == 53 || keycode == 50 || keycode == 38 || keycode == 46)
		ev_else(keycode, base);
	refresh(base);
	return (0);
}