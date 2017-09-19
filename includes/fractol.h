/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 12:43:11 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/19 19:49:38 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	int					*data;
	int					bpp;
	int					sizeline;
	int					endian;
}						t_mlx;

typedef struct			s_fract
{
	double				cr;				//r = Reel
	double				ci;				//i = Imaginaire
	double				nr;				//Nouveau reel
	double				ni;				//Nouvel imaginaire 
	double				ar;				//Ancien reel
	double				ai;				//Ancien imaginaire
	double				zoom;
	double				mx;				//Pour les depalcements x
	double				my;				//pour les deplacements y
	int					x;
	int					y;
	int					i;
	int					color;
	int					maxi;			//Le nombre maximum d'iterations
}						t_fract;

typedef struct			s_base
{
	struct	s_mlx		mx;
	struct	s_fract		fr;
	char				name;
	int					winx;
	int					winy;
	int					win_size;
}						t_base;

/*
** Start of the program			|  fractol.c
*/

void					fractol(t_base *base);

/*
** Fractals algorithms			|  fractals.c
*/

void					julia(t_base *base, t_fract *fr);

/*
** UI, colors and display		| display.c
*/

void					px_img(t_base *base, int x, int y, int color);
void					get_color(t_fract *fr, int i);
void					ui(t_base *base);

/*
** All the events fucntions		|  event.c
*/

void					refresh(t_base *base);
int						event(int keycode, void *param);
void					ev_move(int k, t_base *base);
void					ev_else(int k, t_base * base);


/*
** The init functions			|  init.c
*/

void					init_base(t_base *base, char *av);
t_fract					init_fract();

/*
** Various functions			 utils.c
*/

char					get_fractal(char *av);
void					error(int e);

#endif
