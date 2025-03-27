/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:06:32 by jidrizi           #+#    #+#             */
/*   Updated: 2025/03/25 18:58:27 by jidrizi          ###   ########.fr       */
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

// static int get_map_arr(char **map)
// {
// 	static int	i = 0;

// 	while(map[0][0] == ' ' || map[0][0] == '\t' || map[0][0] == '\n')
// 		map[0]++;// this should move the pointer  to the start of the actual map i guess
	
// }

int	parse(int argc, char **argv)
{
	static t_elements	elements;
	char		*map;

	if (argc != 2)
		return (error_msg("Number of arguments isn't correct\n"), EXIT_FAILURE);
	if (check_cub(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map = get_map_whole(argv[1]);
	if (!map)
		return (EXIT_FAILURE);
	if (check_elements(&map, &elements) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// if (get_map_arr(&map) == EXIT_FAILURE);
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
