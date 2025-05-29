# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inandres <inandres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 10:27:06 by inandres          #+#    #+#              #
#    Updated: 2025/04/24 13:15:38 by inandres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INCLUDE = 		-Imlx
LIBS = -Lmlx -lmlx -lX11 -lXext -lm

SOURCES = 	sources/ft_game_finish.c \
			sources/ft_key_input.c \
			sources/ft_is_posible.c \
			sources/ft_map_check.c \
			sources/ft_print_map.c \
			sources/ft_read_map.c \
			sources/ft_so_long_utils.c \
			sources/so_long.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c
			
DIR_OBJ = objects
OBJECTS = $(addprefix $(DIR_OBJ)/,$(SOURCES:%.c=%.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -g3



OBJECTS = $(SOURCES:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)
	
$(NAME): $(OBJECTS)
	@$(MAKE) -C mlx  2>/dev/null
	@$(CC) $(OBJECTS) $(LIBS) $(INCLUDE) -o $(NAME)
	clear

all: $(NAME)
	@echo "\033[32m  ===================================================================="
	@echo "\033[32m:.                               ___                _____________     .:"
	@echo "\033[32m.:                              /   (___           |@B0red_Cuerv0|    :."
	@echo "\033[32m:.                             /        (                             .:"
	@echo "\033[32m.:                            /         |                             :."
	@echo "\033[32m:.                           /__________|                             .:"
	@echo "\033[32m.:                 _________/___________|_________                    :."
	@echo "\033[32m:.                (_______________________________)_                  .:"
	@echo "\033[32m:.                       /     __   |          ____/                  :."
	@echo "\033[32m:.                     /      /  \  |         /__                     .:"
	@echo "\033[32m:.                   /        \__/  |      _____/                     :."
	@echo "\033[32m:.                 /                |__   /___                        .:"
	@echo "\033[32m:.               /                 /   /_____/                        :."
	@echo "\033[32m:.             /__________________/   /                               .:"
	@echo "\033[32m:.                         /   /\     \                               :."
	@echo "\033[32m:.                        /___/  \_____\                              .:"
	@echo "\033[32m  ===================================================================="

clean	:
	@make clean -C mlx
	@rm -rf $(DIR_OBJ)

fclean	:	clean
	@rm -rf $(NAME)

re	:	fclean all

.PHONY : all clean fclean re make_dir make_lib
