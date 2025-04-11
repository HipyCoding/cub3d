/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:21:11 by jidrizi           #+#    #+#             */
/*   Updated: 2025/04/11 19:32:44 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	error_msg(char *msg)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
}

int break_or_error(t_elements *elements, int purpose)
{
	if (purpose == BREAK)
	{
		if (elements->no_count > 0 && elements->so_count > 0
			&& elements->ea_count > 0 && elements->we_count > 0
			&& elements->f_count > 0 && elements->c_count > 0)
			return (1);
	}
	else if (purpose == ERROR)
	{
		if (elements->no_count != 1 || elements->so_count != 1
			|| elements->ea_count != 1 || elements->we_count != 1
			|| elements->f_count != 1 || elements->c_count != 1)
			return (1);
	}
	return (0);
}

int	check_map_characters(char *map)
{
	int	i;
	int	spawn;

	i = 0;
	spawn = 0;
	while (map[i] && (map[i] == '1' || map[i] == '0'
		|| map[i] == 'N' || map[i] == 'S' || map[i] == 'E' || map[i] ==  'W'
		|| map[i] == ' ' || map[i] == '\t' || map[i] == '\n'))
	{
		if (map[i] == 'N' || map[i] == 'S' || map[i] == 'E' || map[i] ==  'W')
			spawn++;
		i++;
	}
	if (map[i] != '\0' || spawn != 1)
		return (error_msg("Map content is not correct"), EXIT_FAILURE);
	return(EXIT_SUCCESS);
}

int	get_number_of_lines(char *map)
{
	int number_of_lines;

	number_of_lines = 0;
	while (*map)
	{
		if (*map == '\n')
			number_of_lines++;
		map++;
	}
	return (number_of_lines + 1);
}

void	spaces_2_X(char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			*str = 'X';
		str++;
	}
}

void	make_map_square(char **map_arr)
{
	size_t	i;
	size_t	max_len;
	char	*new_str;

	i = 0;
	max_len = 0;
	while (map_arr[i])
	{
		if (ft_strlen(map_arr[i]) > max_len)
			max_len = ft_strlen(map_arr[i]);
		i++;
	}
	i = 0;
	while (map_arr[i])
	{
		new_str = ft_calloc(max_len + 1, sizeof(char));
		ft_memset(new_str, 'X', max_len);
		ft_memcpy(new_str, map_arr[i], ft_strlen(map_arr[i]));
		ft_free_and_null((void **)&map_arr[i]);
		map_arr[i] = new_str;
		spaces_2_X(map_arr[i]);
		i++;
	}
}

// !!!!! FOR DEBUGGING PURPOSES ONLY !!!!!
// void	print_map(char **map_arr)
// {
// 	while (*map_arr != NULL)
// 	{
// 		while (**map_arr)
// 		{
// 			if (**map_arr && **map_arr == '0')
// 				printf("\033[1;32m%c", **map_arr);
// 			else if (**map_arr && **map_arr == 'X')
// 				printf("\033[1;31m%c", **map_arr);
// 			else if (**map_arr && **map_arr == '1')
// 				printf("\033[1;34m%c", **map_arr);
// 			else
// 				printf("\033[0m%c", **map_arr);
// 			printf("\033[0m");
// 			map_arr[0]++;
// 		}
// 		printf("\n");
// 		map_arr++;
// 	}
// }
