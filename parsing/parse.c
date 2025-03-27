/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:06:32 by jidrizi           #+#    #+#             */
/*   Updated: 2025/03/27 16:57:44 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_cub(char *map_dot_cub)
{
	int	len;
	int	dif;

	len = ft_strlen(map_dot_cub);
	len -= 4;
	if (len < 0)
		return (error_msg("File is not a .cub file\n"), EXIT_FAILURE);
	dif = ft_strncmp(&map_dot_cub[len], ".cub", 4);
	if (dif != 0)
		return (error_msg("File is not a .cub file\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse(int argc, char **argv)
{
	static t_elements	elements;
	char				*map_string;
	// char				*tmp; (dont forget to free map_string later)
	char				**map_arr;

	if (argc != 2)
		return (error_msg("Number of arguments isn't correct\n"), EXIT_FAILURE);
	if (check_cub(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map_string = get_map_whole(argv[1]);
	if (!map_string)
		return (EXIT_FAILURE);
	if (check_elements(&map_string, &elements) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_map_characters(map_string) == EXIT_FAILURE)
		return (EXIT_FAILURE);
						//ok the map string pointer has been moved now to the map content
						// but don't forget you need to free the map string at the end
	if (check_actual_map(map_string) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
