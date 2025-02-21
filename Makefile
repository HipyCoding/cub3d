# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: christian <christian@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 13:15:17 by candrese          #+#    #+#              #
#    Updated: 2025/02/20 21:43:42 by christian        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRCS = main.c animations.c
OBJ_DIR = bin
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = MLX42
MLX_BUILD = mlx_build
MLX = $(MLX_BUILD)/libmlx42.a
MLX_FLAGS = -lmlx42 -Iinclude -L/opt/homebrew/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@make -C $(LIBFT_DIR)

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git; \
	fi
	@mkdir -p $(MLX_BUILD)
	@cd $(MLX_DIR) && cmake -B ../$(MLX_BUILD) && cmake --build ../$(MLX_BUILD)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -L$(LIBFT_DIR) -lft -L$(MLX_BUILD) $(MLX_FLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLX_BUILD)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
