# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: christian <christian@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 13:15:17 by candrese          #+#    #+#              #
#    Updated: 2025/04/11 19:28:25 by christian        ###   ########.fr        #
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
	execution/execution.c \
	parsing/parse.c \
	parsing/misc.c \
	parsing/get_map.c \
	parsing/check_elements.c \
	parsing/flood_fill.c \
	parsing/parse_color.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
EUGENELIBFT_DIR = $(INCLUDES_DIR)/eugenelibft
EUGENELIBFT = $(EUGENELIBFT_DIR)/libft.a
MLX_DIR = $(INCLUDES_DIR)/MLX42
MLX_BUILD = $(INCLUDES_DIR)/mlx_build
MLX = $(MLX_BUILD)/libmlx42.a

GLFW_PATH = $(shell brew --prefix glfw 2>/dev/null || echo "/usr/local")
GLFW_FLAGS = -L$(GLFW_PATH)/lib -lglfw

FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/execution
	@mkdir -p $(OBJ_DIR)/parsing

$(EUGENELIBFT):
	@git submodule update --init ./includes/eugenelibft
	@make -C ./includes/eugenelibft

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(INCLUDES_DIR):
	@mkdir -p $(INCLUDES_DIR)

$(MLX): | $(INCLUDES_DIR)
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	fi
	@mkdir -p $(MLX_BUILD)
	@cd $(MLX_BUILD) && cmake $(CURDIR)/$(MLX_DIR) && cmake --build . -j4

$(NAME): $(EUGENELIBFT) $(MLX) $(OBJS)
	$(CC) $(OBJS) $(EUGENELIBFT) $(CFLAGS) -L$(MLX_BUILD) -lmlx42 $(GLFW_FLAGS) $(FRAMEWORKS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@if [ -d "$(EUGENELIBFT_DIR)" ]; then \
		make -C $(EUGENELIBFT_DIR) clean; \
	fi

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX_BUILD)
	@if [ -d "$(EUGENELIBFT_DIR)" ]; then \
		make -C $(EUGENELIBFT_DIR) fclean; \
	fi
	@rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re $(OBJ_DIR)