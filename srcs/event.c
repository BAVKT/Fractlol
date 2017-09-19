/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:42:28 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/19 17:37:59 by vmercadi         ###   ########.fr       */
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
	fractol(base);
	mlx_put_image_to_window(base->mx.mlx, base->mx.win, base->mx.img, 0, 0);
	ui(base);
}

/*
** Redirect the events
*/

int		event(int keycode, void *param)
{
			ft_putendlcolor("event", MAGENTA);
	t_base base;

	keycode = 0;
	param = NULL;
	refresh(&base);
	return (0);
}