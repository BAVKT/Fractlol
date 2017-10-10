# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 17:07:31 by vmercadi          #+#    #+#              #
#    Updated: 2017/10/10 17:54:52 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = srcs/fractol.c srcs/init.c srcs/display.c srcs/fractals.c srcs/event.c \
      srcs/utils.c srcs/fractals2.c

MLX_S = autre/minilibx_macos_sierra/

MLX = autre/minilibx_macos/

INCLUDES = -I includes -I $(MLX_S) -I libft

CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

MFLAGS = -framework OpenGL -framework AppKit -L -lmlx -lpthread

SRCO = $(SRC:%.c=%.o)

LIB = libft/libft.a

.PHONY: all re cleans

all: $(NAME)

$(NAME):$(SRCO)
	@make -s -C $(MLX)
	@make -s -C libft/
	@gcc $(FLAGS) $(LIB) -o $(NAME) $(SRC) $(MFLAGS) $(MLX) $(INCLUDES)
	@echo '---------------------------------------'
	@echo 'Everything compiled nicely and softly !'
	@echo '---------------------------------------'

sierra:$(SRCO)
	@make -s -C $(MLX_S)
	@make -s -C libft/
	@gcc $(FLAGS) $(LIB) -o $(NAME) $(SRC) $(MFLAGS) $(MLX_S) $(INCLUDES)
	@echo '---------------------------------------'
	@echo 'Everything compiled nicely and softly !'
	@echo '---------------------------------------'

it: all
	@./fractol J

clean:
	@rm -rf $(SRCO)
	@make clean -s -C libft/
	@make clean -s -C $(MLX)/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -s -C libft/

re: fclean all
	
ultra: all clean

reit: re clean
	@./fractol J
