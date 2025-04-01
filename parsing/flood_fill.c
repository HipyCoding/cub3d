/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:07:16 by jidrizi           #+#    #+#             */
/*   Updated: 2025/04/01 04:28:54 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../cub3d.h"

static void	find_spawn(char **map_arr, size_t *x, size_t *y, t_player *player)
{
	*y = 0;
	while (map_arr[*y])
	{
		*x = 0;
		while (map_arr[*y][*x]
			&& map_arr[*y][*x] != 'N' && map_arr[*y][*x] != 'S'
			&& map_arr[*y][*x] != 'E' && map_arr[*y][*x] != 'W')
			(*x)++;
		
		if (map_arr[*y][*x] == 'N' || map_arr[*y][*x] == 'S'
				|| map_arr[*y][*x] == 'E' || map_arr[*y][*x] == 'W')
		{
			player->spawn_dir = map_arr[*y][*x];
			player->pos_x = (double)*x + 0.5;
			player->pos_y = (double)*y + 0.5;
			return;
		}
		else if (map_arr[*y][*x] == '\0')
			(*y)++;
	}
}

char	**copy_array(char **map_arr)
{
	char	**copy;
	int		i;
	
	i = 0;
	while (map_arr[i])
	i++;
	copy = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (map_arr[i])
	{
		copy[i] = ft_strdup(map_arr[i]);
		i++;
	}
	return (copy);
}

void	free_array_copy(char **map_arr)
{
	int	i;

	i = 0;
	while (map_arr[i])
	{
		ft_free_and_null((void **)&map_arr[i]);
		i++;
	}
	ft_free_and_null((void **)&map_arr);
}

static int	flood_fill(char **copy, size_t x, size_t y, size_t map_height)
{
	static int		return_value = EXIT_SUCCESS;
	const size_t	left = x - 1;
	const size_t	right = x + 1;
	const size_t	up = y - 1;
	const size_t	down = y + 1;

	if (return_value == EXIT_FAILURE || x < 0 || y < 0 || y > map_height - 1)
		return (EXIT_FAILURE);
	if (copy[y][x] != '1' && copy[y][x] != '0')
		return_value = EXIT_FAILURE;
	if (copy[y][x] == '1')
		return (EXIT_SUCCESS);
	copy[y][x] = '1';
	return_value = flood_fill(copy, x, up, map_height);
	return_value = flood_fill(copy, x, down, map_height);
	return_value = flood_fill(copy, left, y, map_height);
	return_value = flood_fill(copy, right, y, map_height);
	return_value = flood_fill(copy, left, up, map_height);
	return_value = flood_fill(copy, right, up, map_height);
	return_value = flood_fill(copy, left, down, map_height);
	return_value = flood_fill(copy, right, down, map_height);
	return (return_value);
}

// used to check if the map is surrounded by walls
int flood_fill_check(char **map_arr, size_t map_height, t_player *player)
{
	char	**copy;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	copy = copy_array(map_arr);
	find_spawn(copy, &x, &y, player);
	copy[y][x] = '0';
	if (flood_fill(copy, x, y, map_height) == EXIT_FAILURE)
		return (free_array_copy(copy), EXIT_FAILURE);
	free_array_copy(copy);
	return (EXIT_SUCCESS);
}
