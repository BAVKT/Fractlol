/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 12:43:11 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/01 18:51:35 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <pthread.h>
# include <limits.h>
# define NBTH 8
# define FRAC base->frac
# define W 0xffffff
# define G 0x00ff00

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
	double				cr;
	double				ci;
	double				nr;
	double				ni;
	double				ar;
	double				ai;
	double				zoom;
	double				mx;
	double				my;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
	unsigned int		color;
	int					x;
	int					y;
	int					sx;
	int					sy;
	int					maxx;
	int					maxy;
	int					i;
	int					j;
	int					maxi;
	int					winx;
	int					winy;
	int					twiny;
	int					*data;
}						t_fract;

typedef struct			s_base
{
	struct s_mlx		mx;
	struct s_fract		fr[NBTH];
	struct s_fract		frfr;
	char				*name;
	char				*av;
	int					winx;
	int					winy;
	int					win_size;
	int					mouse;
	int					autoiter;
	int					ui1;
	int					ui2;
	int					frac;
}						t_base;

typedef void			(*t_ft) (t_fract*);

/*
** Start of the program			|  fractol.c
*/

void					fractol(t_base *base);

/*
** Fractals algorithms			|  fractals.c
*/

void					*start_draw(void *base);
void					julia(t_fract *fr);
void					mandelbrot(t_fract *fr);

/*
** Other fractals algorithms	|  fractals2.c
*/

void					reversebrot(t_fract *fr);
void					reversejulia(t_fract *fr);
void					cell(t_fract *fr);
void					zbli(t_fract *fr);
void					plume(t_fract *fr);

/*
** UI, colors and display		| display.c
*/

void					px_img(t_fract *fr);
void					get_color(t_fract *fr);
void					ui(t_base *base);
void					ui1(t_base *base);
void					ui2(t_base *base);

/*
** All the events fucntions		|  event.c
*/

void					refresh(t_base *base);
int						event(int keycode, void *param);
void					ev_move(int k, t_base *base);
void					ev_else(int k, t_base *base);
int						ev_mouse(int k, int x, int y, void *param);
int						evmv_mouse(int x, int y, t_base *base);

/*
** The init functions			|  init.c
*/

void					init_base(t_base *base, char *av);
t_fract					init_fract(t_base *base);
t_fract					init_fracthr(t_base *base);

/*
** Various functions			|  utils.c
*/

void					get_fractal(char *av, t_fract *fr);
void					get_name(t_base *base);
void					error(int e);
int						clean(t_base *base);
void					mthread(t_base *base);

static const t_ft tab_fr[] =
{
	&julia,
	&mandelbrot,
	&reversebrot,
	&reversejulia,
	&cell,
	&zbli,
	&plume
};

#endif
