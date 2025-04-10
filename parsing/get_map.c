/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:52:54 by jidrizi           #+#    #+#             */
/*   Updated: 2025/04/11 22:26:31 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_number_of_lines(char *map)
{
	int	number_of_lines;

	number_of_lines = 0;
	while (*map)
	{
		if (*map == '\n')
			number_of_lines++;
		map++;
	}
	return (number_of_lines + 1);
}

static char	*fill_map_str(char *current_line, char *map_file, int fd)
{
	char	*temp_line;

	temp_line = NULL;
	while (current_line)
	{
		temp_line = map_file;
		map_file = ft_strjoin(temp_line, current_line);
		ft_free_and_null((void **)&temp_line);
		ft_free_and_null((void **)&current_line);
		if (!map_file)
			return (NULL);
		current_line = get_next_line(fd);
	}
	return (map_file);
}

char	*get_map_whole(char *arg1)
{
	int		fd;
	char	*map;
	char	*current_line;

	fd = open(arg1, O_RDONLY);
	if (fd < 0)
		return (error_msg("Something wrong with map file\n"), NULL);
	map = NULL;
	current_line = get_next_line(fd);
	if (!current_line)
		return (error_msg("Something wrong with map file\n"), close(fd), NULL);
	map = fill_map_str(current_line, map, fd);
	if (!map)
		return (close(fd), error_msg("Something wrong with map file\n"), NULL);
	return (close(fd), map);
}
