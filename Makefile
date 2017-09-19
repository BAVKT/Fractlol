# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 06:27:28 by vmercadi          #+#    #+#              #
#    Updated: 2017/09/19 19:11:45 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = srcs/fractol.c srcs/init.c srcs/display.c srcs/fractals.c srcs/event.c \
      srcs/utils.c

INCLUDES = -I includes -I autre/minilibx_macos -I libft

CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

MFLAGS = -framework OpenGL -framework AppKit -L $(MLX) -lmlx

SRCO = $(SRC:%.c=%.o)

LIB = libft/libft.a

MLX = autre/minilibx_macos/

MLX_S = autre/minilibx_macos_sierra/

.PHONY: all re cleans

all: $(NAME)

$(NAME):$(SRCO)
	@make -C $(MLX)
	@make -C libft/
	@gcc $(FLAGS) $(LIB) -o $(NAME) $(SRC) $(MFLAGS) $(INCLUDES)

sierra:
	@make -C $(MLX_S)
	@make -C libft/
	@gcc $(FLAGS) $(LIB) -o $(NAME) $(SRC) $(MFLAGS) $(INCLUDES)

clean:
	@rm -rf $(SRCO)
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/

ultra: all clean

re: fclean all







