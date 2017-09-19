/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:42:28 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/19 20:01:30 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Clear the current image, draw the new one and display it
*/

void	refresh(t_base *base)
{
			ft_putendlcolor("refresh()", MAGENTA);
	int	i;

	i = 0;
	while (i < (base->win_size - 1))
		base->mx.data[i++] = 0;
	if (base->name == 'j')
		julia(base, &base->fr);
	mlx_put_image_to_window(base->mx.mlx, base->mx.win, base->mx.img, 0, 0);
	ui(base);
}

/*
** Move events & zoom
*/

void	ev_move(int k, t_base *base)
{
			ft_putendlcolor("ev_move()", MAGENTA);
			ft_putnbrendl(base->fr.maxi);
	if (k == 126)
		base->fr.my++;
	else if (k == 125)
		base->fr.mx++;
	else if (k == 123)
		base->fr.maxi++;
	else if (k == 124)
		base->fr.maxi--;
}


void	ev_else(int k, t_base * base)
{
	if (k == 83)
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
			ft_putendlcolor("event", MAGENTA);
	t_base *base;
		
	base = (t_base *)param;
			ft_putnbrendl(keycode);
	if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
		ev_move(keycode, base);
	else if (keycode == 83 || keycode == 84 || keycode == 85 || keycode == 86)
		ev_else(keycode, base);
	refresh(base);
	return (0);
}