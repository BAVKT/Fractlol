/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:42:28 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/20 16:54:43 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Clear the current image, draw the new one and display it
*/

void	refresh(t_base *base)
{
			 ft_putendlcolor("refresh()", MAGENTA);
	if (base->name == 'j')
		julia(base, &base->fr);
	else if (base->name == 'm')
		mandelbrot(base, &base->fr);
	mlx_put_image_to_window(base->mx.mlx, base->mx.win, base->mx.img, 0, 0);
	ui(base);
}

/*
** Move events & zoom
*/

void	ev_move(int k, t_base *base)
{
			ft_putendlcolor("ev_move()", MAGENTA);
	if (k == 126)
		base->fr.zoom++;
	else if (k == 125)
		base->fr.zoom--;
	else if (k == 69 && base->fr.maxi < 100)
		base->fr.maxi += 2;
	else if (k == 78 && base->fr.maxi > 5)
		base->fr.maxi -= 2;
			ft_putstr("maxi = ");
			ft_putnbrendl(base->fr.maxi);
}

/*
** Other events
*/

void	ev_else(int k, t_base * base)
{
	if (k == 53)
		clean(base);
	else if (k == 83)
		base->fr.color = 0xff0000;
	else if (k == 84)
		base->fr.color = 0x00ff00;
	else if (k == 85)
		base->fr.color = 0xffff00;
	else if (k == 86)
		base->fr.color = 0xff00ff;
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
		|| keycode == 78 || keycode == 69)
		ev_move(keycode, base);
	else if (keycode == 83 || keycode == 84 || keycode == 85 || keycode == 86
		|| keycode == 53)
		ev_else(keycode, base);
	refresh(base);
	return (0);
}