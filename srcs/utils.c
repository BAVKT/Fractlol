/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:48:54 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/25 13:34:52 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Return the the letter corresponding to the fractal
*/

char	get_fractal(char *av)
{
			ft_putendlcolor("get_fractal()", MAGENTA);
	char c;

	c = 'y';
	if (!ft_strcmp(av, "Julia") || !ft_strcmp(av, "j") ||
		!ft_strcmp(av, "julia") || !ft_strcmp(av, "J"))
		c = 'j';
	else if (!ft_strcmp(av, "Mandelbrot") || !ft_strcmp(av, "s") ||
			!ft_strcmp(av, "mandelbrot") || !ft_strcmp(av, "M"))
		c = 'm';
	else if (!ft_strcmp(av, "Buddhabrot") || !ft_strcmp(av, "s") ||
			!ft_strcmp(av, "buddhabrot") || !ft_strcmp(av, "B"))
		c = 'b';
	else if (!ft_strcmp(av, "Sierpinski") || !ft_strcmp(av, "s") ||
			!ft_strcmp(av, "sierpinski") || !ft_strcmp(av, "S"))
		c = 's';
	else
		error(2);
	return (c);
}

/*
** All the error messages
*/

void	error(int e)
{
	if (e == 0)
	{
		ft_putendl_fd("Usage : ./fractol FractalName", 2);		
		exit(1);
	}
	ft_putstr_fd("Error : ", 2);
	if (e == 1)
		ft_putendl_fd("Wrong number of arguments.", 2);
	else if (e == 2)
		ft_putendl_fd("Wrong fractal name.", 2);
	exit(1);
}

/*
** Free all the tabs needed
*/

void	clean(t_base *base)
{
	mlx_destroy_window(base->mx.mlx, base->mx.win);
	mlx_destroy_image(base->mx.mlx, base->mx.img);
	exit(0);
}

/*
** Multi-threading
*/

void	mthread()
{
    pthread_t	th[8];
    int			i;

    i = 0;
    while (i < 8)
	    pthread_create(&th[i++], NULL, myThreadFun, NULL);


}


// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}
  
int main()
{
    pthread_t tid;
    printf("Before Thread\n");
    pthread_create(&tid, NULL, myThreadFun, NULL);
    pthread_join(tid, NULL);
    printf("After Thread\n");
    exit(0);
}