/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:58:11 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/28 16:03:04 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// /*
// ** Sierpinski fractal
// ** We just draw lines between xy1/xy2 | xy2/xy3 | xy1/xy3
// */


			// IM = fabsl((X - POS_X - (((HEIGHT + (W * 1000)) / 2)) *
			// 			(4.0 / WIDTH)));
			// RE = fabsl((Y - POS_Y - (((HEIGHT + (H * 1000)) / 2)) *
			// 			(4.0 / WIDTH)));
			// while (((int)IM % 3 != 1 || ((int)RE % 3) != 1) && ++ITER < MAXI)
			// {
			// 	IM /= 3;
			// 	RE /= 3;
			// }
			// if (ITER != MAXI)
			// 	ITER = 1;




// void sierpinski(t_base *base,)
// {
// 	t_si si;

// 	si->i = 3;
// 	si->x1 = 20;
// 	si->y1 = base->winx - 20;
// 	si->x2 = base->winy - 20;
// 	si->y2 = base->winx - 20;
// 	si->x3 = base->winx / 2;
// 	si->y3 = 20;
// 	start_line(base, &si);
// 	si->x2 = si->x1;
// 	si->y2 = si->y1;
// 	start_line(base, si);
// 	si->x3 = si->x1;
// 	si->y3 = si->y1;
// 	start_line(base, si);
// 	triangles(0, (si->x1 + si->x2) / 2, (si->y1 + si->y2) / 2, (si->x1 + si->x3) / 2,
// 		(si->y1 + si->y3) / 2, (si->x2 + si->x3) / 2, (si->y2 + si->y3) / 2);
// }

// void	init_triangle(t_si si)
// {
// 	si->a = si->x1;
// 	si->b = si->y1;
// 	si->c = si->x2;
// 	si->d = si->y2;
// 	si->e = si->x3;
// 	si->f = si->y3;
// 	start_line(base, si);
// 	si->x2 = si->a;
// 	si->y2 = si->b;
// 	start_line(base, si);
// 	si->x3 = si->x1;
// 	si->y3 = si->y1;
// 	start_line(base, si);

// }

// /*
// ** Draw triangles until the end of 
// */

// void	triangles(t_siact *si)
// {
// 	init_triangles(base, si);
// 	if(si->i < si->maxi)
// 	{
// 		triangles(si->i + 1, (si->x1 + si->x2) / 2 + (si->x2 - si->x3) / 2,
// 			(si->y1 + si->y2) / 2 + (si->y2 - si->y3) / 2,
// 			(si->x1 + si->x2) / 2 + (si->x1 - si->x3) / 2,
// 			(si->y1 + si->y2) / 2 + (si->y1 - si->y3) / 2,
// 			(si->x1 + si->x2) / 2, (si->y1 + si->y2) / 2);
// 		triangles(si->i + 1, (si->x3 + si->x2) / 2 + (si->x2 - si->x1) / 2,
// 			(si->y3 + si->y2) / 2 + (si->y2 - si->y1) / 2,
// 			(si->x3 + si->x2) / 2 + (si->x3 - si->x1) / 2,
// 			(si->y3 + si->y2) / 2 + (si->y3 - si->y1) / 2,
// 			(si->x3 + si->x2) / 2, (si->y3 + si->y2) / 2 );
// 		triangles(si->i + 1, (si->x1 + si->x3) / 2 + (si->x3 - si->x2) / 2,
// 			(si->y1 + si->y3) / 2 + (si->y3 - si->y2) / 2,
// 			(si->x1 + si->x3) / 2 + (si->x1 - si->x2) / 2,
// 			(si->y1 + si->y3) / 2 + (si->y1 - si->y2) / 2,
// 			(si->x1 + si->x3) / 2, (si->y1 + si->y3) / 2);
// 		si->i++;
// 	}
// }

// /*
// ** Init the lines values and start the line()
// */

// void	start_line(t_base *base, t_siact *si)
// {
// 	int	xx;
// 	int	yy;

// 	si->x = si->x2;
// 	si->y = si->y2;
// 	si->x1 = si->x3 - si->x2;
// 	si->y1 = si->y3 - si->y2;
// 	xx = (si->x1 > 0) ? 1 : -1;
// 	yy = (si->y1 > 0) ? 1 : -1;
// 	si->x1 = si->x1;
// 	si->y1 = si->y1;
// 	px_img(base, si);
// 	if (si->x2 >= base->winx || si->y2 >= base->winy ||
// 		si->x3 >= base->winx || si->y3 >= base->winy ||
// 		si->x2 < 0 || si->y2 < 0 || si->x3 < 0 || si->y3 < 0)
// 		return ;
// 	if (si->x1 > si->y1)
// 		line1(base, xx, yy);
// 	else
// 		line2(base, xx, yy);
// }

// /*
// ** Draw the line between the points
// */

// void	line1(t_base *base, int xx, int yy)
// {
// 	int	i;
// 	int cumul;

// 	i = 1;
// 	cumul = si->x1 / 2;
// 	while (i <= si->x1)
// 	{
// 		si->x += xx;
// 		cumul += si->y1;
// 		if (cumul >= si->x1)
// 		{
// 			cumul -= si->x1;
// 			si->y += yy;
// 		}
// 		px_img(base, si);
// 		i++;
// 	}
// }

// void	line2(t_base *base, int xx, int yy)
// {
// 	int	i;
// 	int cumul;

// 	i = 1;
// 	cumul = si->y1 / 2;
// 	while (i <= si->y1)
// 	{
// 		si->y += yy;
// 		cumul += si->x1;
// 		if (cumul >= si->y1)
// 		{
// 			cumul -= si->y1;
// 			si->x += xx;
// 		}
// 		px_img(base, si);
// 		i++;
// 	}
// }
