/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:08:25 by jidrizi           #+#    #+#             */
/*   Updated: 2025/04/01 06:36:27 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

//EXTERNAL LIBS
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

//LOCAL LIBS
# include "includes/eugenelibft/libft.h"
# include "../includes/MLX42/include/MLX42/MLX42.h"
# include "../cub3d.h"

//MACROS

#define BREAK -1
#define ERROR -2

//TYPES

typedef struct s_elements
{
	int		no_count;
	int		so_count;
	int		we_count;
	int		ea_count;
	int		f_count;
	int		c_count;
}t_elements;

enum e_enum_elements
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
};

void	print_2d_array(char **arr, int fd, char *s);

//PROTOTYPES

int		get_num(char **map);
void	handle_color(char **map, t_texture *texture, int instance);
void	error_msg(char *msg);
char	**parse(int argc, char **argv, t_cub3d *c);
char	*get_map_whole(char *arg1);
int		check_elements(char **map, t_elements *elements, t_texture *texture);
int		break_or_error(t_elements *elements, int purpose);
int		check_map_characters(char *map);
int		get_number_of_lines(char *map);
void	make_map_square(char **map_arr);
int		flood_fill_check(char **map_arr, size_t map_height, t_player *player);
char	**copy_array(char **map_arr);
void	free_array_copy(char **map_arr);

#endif
