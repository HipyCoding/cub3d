# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: christian <christian@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 13:15:17 by candrese          #+#    #+#              #
#    Updated: 2025/03/31 05:05:01 by christian        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

INCLUDES_DIR = includes
OBJ_DIR = bin

INCLUDES = -I.

SRCS = main.c \
	execution/animations.c \
	execution/clean.c \
	execution/controls.c \
	execution/dda.c \
	execution/rays.c \
	execution/textures.c \
	execution/draw_vertical_line.c \
	execution/execution.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = $(INCLUDES_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = $(INCLUDES_DIR)/MLX42
MLX_BUILD = $(INCLUDES_DIR)/mlx_build
MLX = $(MLX_BUILD)/libmlx42.a

FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(INCLUDES_DIR):
	@mkdir -p $(INCLUDES_DIR)

$(LIBFT): | $(INCLUDES_DIR)
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@make -C $(LIBFT_DIR)

$(MLX): | $(INCLUDES_DIR)
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	fi
	@mkdir -p $(MLX_BUILD)
	@cd $(MLX_DIR) && cmake -B ../mlx_build && cmake --build ../mlx_build -j4

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -L$(LIBFT_DIR) -lft -L$(MLX_BUILD) -lmlx42 -L$(shell brew --prefix glfw)/lib -lglfw $(FRAMEWORKS) -o $(NAME)
	
#$(CC) $(OBJS) $(CFLAGS) -L$(LIBFT_DIR) -lft -L$(MLX_BUILD) -lmlx42 -lglfw $(FRAMEWORKS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		make -C $(LIBFT_DIR) clean; \
	fi

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX_BUILD)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		make -C $(LIBFT_DIR) fclean; \
	fi
	@rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
