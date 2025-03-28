/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:08:25 by jidrizi           #+#    #+#             */
/*   Updated: 2025/03/28 16:10:33 by jidrizi          ###   ########.fr       */
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
# include "includes/MLX42/include/MLX42/MLX42.h"

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

//PROTOTYPES

void	error_msg(char *msg);
int		parse(int argc, char **argv);
char	*get_map_whole(char *arg1);
int		check_elements(char **map, t_elements *elements);
int		break_or_error(t_elements *elements, int purpose);
int		check_map_characters(char *map);
char	*remove_white_spaces(char *map);


#endif