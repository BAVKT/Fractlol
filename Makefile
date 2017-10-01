# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 17:07:31 by vmercadi          #+#    #+#              #
#    Updated: 2017/10/01 17:04:21 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = srcs/fractol.c srcs/init.c srcs/display.c srcs/fractals.c srcs/event.c \
      srcs/utils.c srcs/fractals2.c

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
	@echo '---------------------------------------'
	@echo 'Everything compiled nicely and softly !'
	@echo '---------------------------------------'

it: all
	./fractol M

clean:
	@rm -rf $(SRCO)
	@make clean -s -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -s -C libft/

re: fclean all
	
ultra: all clean

reit: re clean
	./fractol M
