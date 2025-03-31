/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:06:32 by jidrizi           #+#    #+#             */
/*   Updated: 2025/03/31 17:49:09 by jidrizi          ###   ########.fr       */
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

static char	**make_map_arr(char *map, size_t *map_height)
{
	static int	i = 0;
	char		**map_arr;
	char		*map_line;
	int			current_line;

	while (map[0] == '\n')
		map++;
	*map_height = (size_t)get_number_of_lines(map);
	map_arr = ft_calloc(*map_height + 1, sizeof(char *));
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

char	**parse(int argc, char **argv)
{
	static t_elements	elements;
	char				*map_string;
	char				**map_array;
	char				*free_map_string;
	size_t				map_height;

	if (argc != 2)
		return (error_msg("Number of arguments isn't correct\n"), NULL);
	if (check_cub(argv[1]) == EXIT_FAILURE)
		return (NULL);
	map_string = get_map_whole(argv[1]);
	if (!map_string)
		return (NULL);
	free_map_string = map_string;
	if (check_elements(&map_string, &elements) == EXIT_FAILURE)
		return (ft_free_and_null((void **)&free_map_string), NULL);
	if (check_map_characters(map_string) == EXIT_FAILURE)
		return (ft_free_and_null((void **)&free_map_string), NULL);
	map_array = make_map_arr(map_string, &map_height);
	ft_free_and_null((void **)&free_map_string);
	if (flood_fill_check(map_array, map_height) == EXIT_FAILURE)
		return (error_msg("Fail on flood fill bruh\n"), NULL);
	return (map_array);
}
