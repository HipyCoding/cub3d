/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:21:11 by jidrizi           #+#    #+#             */
/*   Updated: 2025/03/28 17:55:18 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	error_msg(char *msg)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
}

// yes it looks stupid but i use this to get around norm
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

char	*remove_white_spaces(char *map)
{
	static int	x = 0;
	static int	y = 0;
	char		*new_map;

	new_map = ft_calloc(ft_strlen(map) + 1, sizeof(char));
	while (map[x])
	{
		if (map[x] != ' ' && map[x] != '\t')
		{
			new_map[y] = map[x];
		}
		else
			new_map[y] = '1';
		y++;
		x++;
	}
	new_map[y] = '\0';
	return (new_map);
}
