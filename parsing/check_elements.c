/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:15:24 by jidrizi           #+#    #+#             */
/*   Updated: 2025/03/27 16:12:51 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
// in each function whenever we have an error i set the map to NULL

static void	handle_textures(char **map)
{
	char	*path;
	int		i;
	int		fd;

	i = 0;
	while (map[0][i] && map[0][i] != ' ' && map[0][i] != '\t'
			&& map[0][i] != '\n')
		i++;
	path = ft_substr(map[0], 0, i);
	fd = open(path, O_RDONLY);
	ft_free_and_null((void **)&path);
	// add this back later
	// if (fd < 0)
	// 	map[0] = NULL;
	map[0] += i;
	close(fd);
}

static int	get_num(char **map)
{
	int		num;
	int		i;
	char	*sub_s;

	i = 0;
	while (map[0][0] == ' ' || map[0][0] == '\t' || map[0][0] == '\n')
		map[0]++;
	if (!(map[0][i] >= '0' && map[0][i] <= '9'))
	{
		map[0] = NULL;
		return (-1);
	}
	while (map[0][i] >= '0' && map[0][i] <= '9')
		i++;
	if (i > 3)
	{
		map[0] = NULL;
		return (-1);
	}
	sub_s = ft_substr(map[0], 0, i);
	num = ft_atoi(sub_s);
	map[0] += i;
	return (ft_free_and_null((void **)&sub_s), num);
}

static void	handle_color(char **map)
{
	int	value;
	int	num;

	value = 1;
	while (value <= 3 && map[0])
	{
		num = get_num(map);
		if (!(num >= 0 && num <= 255))
		{
			map[0] = NULL;
			return ;
		}
		while (value < 3 && (map[0][0] == ' '
			|| map[0][0] == '\t' || map[0][0] == '\n'))
			map[0]++;
		if (value < 3 && map[0][0] == ',')
			map[0]++;
		else if (value < 3 && map[0][0] != ',')
		{
			map[0] = NULL;
			return ;
		}
		value++;
	}
}

static void	handle_element(char **map, t_elements *elements, int instance)
{
	if (instance == NO)
	elements->no_count++;
	else if (instance == SO)
	elements->so_count++;
	else if (instance == WE)
	elements->we_count++;
	else if (instance == EA)
	elements->ea_count++;
	else if (instance == F)
	elements->f_count++;
	else if (instance == C)
	elements->c_count++;
	if (instance == F || instance == C)
		return (map[0]++, handle_color(map), (void)0);
	else
		map[0] += 2;
	while (map[0][0] && (map[0][0] == ' ' || map[0][0] == '\t'
		|| map[0][0] == '\n'))
		map[0]++;
	handle_textures(map);
	}

int	check_elements(char **map, t_elements *elements)
{
	while (map[0] && map[0][0])
	{
		if (map[0][0] == 'N' && map[0][1] == 'O')
			handle_element(map, elements, NO);
		else if (map[0][0] == 'S' && map[0][1] == 'O')
			handle_element(map, elements, SO);
		else if (map[0][0] == 'W' && map[0][1] == 'E')
			handle_element(map, elements, WE);
		else if (map[0][0] == 'E' && map[0][1] == 'A')
			handle_element(map, elements, EA);
		else if (map[0][0] == 'F')
			handle_element(map, elements, F);
		else if (map[0][0] == 'C')
			handle_element(map, elements, C);
		if (break_or_error(elements, BREAK) == 1 && map[0])
			break ;
		if (map[0] && map[0][0]!= ' ' && map[0][0]!= '\t' && map[0][0]!= '\n')
			map[0] = NULL;
		if (map[0])
			map[0] += 1;
	}
	if (break_or_error(elements, ERROR) == 1 || !map[0])
		return (error_msg("Elements are not correct\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
