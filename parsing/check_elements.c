/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:15:24 by jidrizi           #+#    #+#             */
/*   Updated: 2025/04/01 09:16:41 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../cub3d.h"

void assign_texture_path(int instance, t_texture *texture, char *path)
{
if (instance == NO)
texture->no_texture_path = path;
else if (instance == SO)
texture->so_texture_path = path;
else if (instance == WE)
texture->we_texture_path = path;
else if (instance == EA)
texture->ea_texture_path = path;
}

static void handle_textures(char **map, t_texture *texture, int instance)
{
	char	*path;
	int		i;
	int		fd;

	i = 0;
	while (map[0][i] && map[0][i] != ' ' && map[0][i] != '\t' && map[0][i] != '\n')
		i++;
	path = ft_substr(map[0], 0, i);
	if (ft_strlen(path) < 4 || ft_strncmp(&path[ft_strlen(path) - 4], ".png", 4) != 0)
	{
		map[0] = NULL;
		return (ft_free_and_null((void **)&path), (void)0);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		map[0] = NULL;
		return (ft_free_and_null((void **)&path), (void)0);
	}
	close(fd);
	assign_texture_path(instance, texture, path);
	map[0] += i;
}

int	get_num(char **map)
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

static void	handle_element(char **map, t_elements *elements, int instance,
			t_texture *texture)
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
		return (map[0]++, handle_color(map, texture, instance), (void)0);
	else
		map[0] += 2;
	while (map[0][0] && (map[0][0] == ' ' || map[0][0] == '\t'
		|| map[0][0] == '\n'))
		map[0]++;
	handle_textures(map, texture, instance);
	}

int	check_elements(char **map, t_elements *elements, t_texture *texture)
{
	while (map[0] && map[0][0])
	{
		if (map[0][0] == 'N' && map[0][1] == 'O')
			handle_element(map, elements, NO, texture);
		else if (map[0][0] == 'S' && map[0][1] == 'O')
			handle_element(map, elements, SO, texture);
		else if (map[0][0] == 'W' && map[0][1] == 'E')
			handle_element(map, elements, WE, texture);
		else if (map[0][0] == 'E' && map[0][1] == 'A')
			handle_element(map, elements, EA, texture);
		else if (map[0][0] == 'F')
			handle_element(map, elements, F, texture);
		else if (map[0][0] == 'C')
			handle_element(map, elements, C, texture);
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
