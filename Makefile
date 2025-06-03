# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: machouba <machouba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 12:16:13 by machouba          #+#    #+#              #
#    Updated: 2024/05/08 14:57:23 by machouba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g3
XFLAGS = -Lmlx_linux -Imlx_linux -lX11 -lXext -lm -lz -Ofast
MLX_PATH = minilibx-linux/
LIBFT_SO_LONG_PATH = libft/
LIB_MLX = minilibx-linux/libmlx.a
LIBFT_SO_LONG = libft/libft.a

SOURCE = ./sources/

MAP = $(addprefix map/, correct_map.c init_map.c map_utils.c parsing_map.c path_utils.c path_valid.c)
DISPLAY = $(addprefix aff/, display_utils.c display.c render_map.c)
MOVE = $(addprefix mouv/, move_down.c move_up.c move_left.c move_right.c move_utils.c)
GAME = $(addprefix $(SOURCE), $(MAP) $(DISPLAY) $(MOVE) so_long.c end_game.c)

SRC = $(GAME)
OBJ = $(SRC:%.c=%.o)

all: minilibx-linux $(NAME) 

$(NAME): $(OBJ)
	@make -sC $(MLX_PATH)
	@make -sC $(LIBFT_SO_LONG_PATH)
	$(RM) $(NAME)
	make all -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIB_MLX) $(XFLAGS) $(LIBFT_SO_LONG) -o $(NAME)

minilibx-linux:
	git clone https://github.com/42Paris/minilibx-linux.git $@
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

clean:
	$(RM) $(OBJ)
	make clean -C ./libft
	make clean -C $(MLX_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re