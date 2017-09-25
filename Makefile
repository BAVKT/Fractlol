# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 06:27:28 by vmercadi          #+#    #+#              #
#    Updated: 2017/09/25 21:27:14 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = srcs/fractol.c srcs/init.c srcs/display.c srcs/fractals.c srcs/event.c \
      srcs/utils.c srcs/sierpinski.c

MLX_S = autre/minilibx_macos_sierra/

INCLUDES = -I includes -I autre/minilibx_macos -I libft

CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

MFLAGS = -framework OpenGL -framework AppKit -L $(MLX_S) -lmlx -lpthread

SRCO = $(SRC:%.c=%.o)

LIB = libft/libft.a

.PHONY: all re cleans

all: $(NAME)

$(NAME):$(SRCO)
	@make -s -C $(MLX_S)
	@make -s -C libft/
	@gcc $(FLAGS) $(LIB) -o $(NAME) $(SRC) $(MFLAGS) $(INCLUDES)
	@echo 'Everything compiled nicely and softly !'

it: all
	./fractol M

clean:
	@rm -rf $(SRCO)
	@make clean -s -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -s -C libft/

ultra: all clean

re: fclean all
