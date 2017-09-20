/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:58:11 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/20 16:33:33 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void sierpinski(float x1, float y1, float x2, float y2, float x3, float y3)
{
	drawLine(int(x1), int(y1), int(x2), int(y2), RGB_Black);
	drawLine(int(x1), int(y1), int(x3), int(y3), RGB_Black);
	drawLine(int(x2), int(y2), int(x3), int(y3), RGB_Black);
	subTriangle(1, (x1 + x2) / 2, (y1 + y2) / 2, (x1 + x3) / 2,
		(y1 + y3) / 2, (x2 + x3) / 2, (y2 + y3) / 2);
}

void  triangles(int n, float x1, float y1, float x2, float y2, float x3, float y3)
{
	drawLine(int(x1), int(y1), int(x2), int(y2), RGB_Black);
	drawLine(int(x1), int(y1), int(x3), int(y3), RGB_Black);
	drawLine(int(x2), int(y2), int(x3), int(y3), RGB_Black);

	if(n < depth)
	{
		subTriangle(n+1, (x1 + x2) / 2 + (x2 - x3) / 2, (y1 + y2) / 2 + (y2 - y3) / 2, 
			(x1 + x2) / 2 + (x1 - x3) / 2, (y1 + y2) / 2 + (y1 - y3) / 2, 
			(x1 + x2) / 2, (y1 + y2) / 2);
		subTriangle(n+1, (x3 + x2) / 2 + (x2 - x1) / 2, (y3 + y2) / 2 + (y2 - y1) / 2, 
			(x3 + x2) / 2 + (x3 - x1) / 2, (y3 + y2) / 2 + (y3 - y1) / 2, 
			(x3 + x2) / 2, (y3 + y2) / 2 );
		subTriangle(n+1, (x1 + x3) / 2 + (x3 - x2) / 2, (y1 + y3) / 2 + (y3 - y2) / 2, 
			(x1 + x3) / 2 + (x1 - x2) / 2, (y1 + y3) / 2 + (y1 - y2) / 2, 
			(x1 + x3) / 2, (y1 + y3) / 2);
  }
}