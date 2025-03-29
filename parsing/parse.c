/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:06:32 by jidrizi           #+#    #+#             */
/*   Updated: 2025/03/28 18:35:18 by jidrizi          ###   ########.fr       */
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

// static int	check_actual_map(char **map)
// {
	
// }

int	parse(int argc, char **argv)
{
	static t_elements	elements;
	char				*map_string;
	char				*tmp;

	if (argc != 2)
		return (error_msg("Number of arguments isn't correct\n"), EXIT_FAILURE);
	if (check_cub(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map_string = get_map_whole(argv[1]);
	if (!map_string)
		return (EXIT_FAILURE);
	tmp = map_string;
	if (check_elements(&map_string, &elements) == EXIT_FAILURE)
		return (ft_free_and_null((void **)&tmp), EXIT_FAILURE);
	if (check_map_characters(map_string) == EXIT_FAILURE)
		return (ft_free_and_null((void **)&tmp), EXIT_FAILURE);
	map_string = make_map_square(map_string);
	ft_free_and_null((void **)&tmp);
	printf("%s\n", map_string);
	// if (check_actual_map(&map_string) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
