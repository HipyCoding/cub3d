/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:06:32 by jidrizi           #+#    #+#             */
/*   Updated: 2025/03/30 18:02:48 by jidrizi          ###   ########.fr       */
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

static char	**make_map_arr(char *map)
{
	char	**map_arr;
	char	*map_line;
	int		number_of_lines;
	int		current_line;
	static int		i = 0;

	while (map[0] == '\n')
		map++;
	number_of_lines = get_number_of_lines(map);
	map_arr = ft_calloc(number_of_lines + 1, sizeof(char *));
	current_line = 0;
	while (map[i])
	{
		while (map[i] && map[i] != '\n')
			i++;
		map_line = ft_substr(map, 0, i);
		if (map[i] && map[i] == '\n')
			i++;
		map_arr[current_line] = map_line;
		current_line++;
		map += i;
		i = 0;
	}
	make_map_square(map_arr);
	return (map_arr);
}

// used to check if the map is surrounded by walls
static int flood_fill_check(char **map_arr)
{
	if ()
	return (EXIT_SUCCESS);
}

int	parse(int argc, char **argv)
{
	static t_elements	elements;
	char				*map_string;
	char				**map_array;
	char				*free_map_string;

	if (argc != 2)
		return (error_msg("Number of arguments isn't correct\n"), EXIT_FAILURE);
	if (check_cub(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map_string = get_map_whole(argv[1]);
	if (!map_string)
		return (EXIT_FAILURE);
	free_map_string = map_string;
	if (check_elements(&map_string, &elements) == EXIT_FAILURE)
		return (ft_free_and_null((void **)&free_map_string), EXIT_FAILURE);
	if (check_map_characters(map_string) == EXIT_FAILURE)
		return (ft_free_and_null((void **)&free_map_string), EXIT_FAILURE);
	map_array = make_map_arr(map_string);
	ft_free_and_null((void **)&free_map_string);
	if (flood_fill_check(map_array) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
