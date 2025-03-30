/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:07:16 by jidrizi           #+#    #+#             */
/*   Updated: 2025/03/30 23:25:46 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	find_spawn(char **map_arr, int *x, int *y)
{

	while (map_arr[y[0]])
	{
		while (map_arr[y[0]][x[0]]
			&& map_arr[y[0]][x[0]] != 'N' && map_arr[y[0]][x[0]] != 'S'
			&& map_arr[y[0]][x[0]] != 'E' && map_arr[y[0]][x[0]] != 'W')
			x[0]++;
		if (map_arr[y[0]][x[0]] == 'N' || map_arr[y[0]][x[0]] == 'S'
				|| map_arr[y[0]][x[0]] == 'E' || map_arr[y[0]][x[0]] == 'W')
			return (EXIT_SUCCESS);
		else if (map_arr[y[0]][x[0]] == '\0')
			y[0]++;
	}
	return (EXIT_FAILURE);
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

static int	flood_fill(char **copy, int x, int y)
{
	static int return_value = EXIT_SUCCESS;

	if (copy[y] && copy[y][x] && copy[y][x] != 'X')
		copy[y][x] = '1';
	else if (copy[y] && copy[y][x] && copy[y][x] == 'X')
	{
		return_value = EXIT_FAILURE;
		return (return_value);
	}
	else if (!copy[y] ||copy[y][x] == '\0')
		return (EXIT_SUCCESS);
	if (copy[y] && copy[y][x] && copy[y - 1][x] && copy[y - 1][x] != '1')
		flood_fill(copy, x, y - 1);
	if (copy[y] && copy[y][x] && copy[y + 1][x] && copy[y + 1][x] != '1')
		flood_fill(copy, x, y + 1);
	if (copy[y] && copy[y][x] && copy[y][x - 1] && copy[y][x - 1] != '1')
		flood_fill(copy, x - 1, y);
	if (copy[y] && copy[y][x] && copy[y][x + 1] && copy[y][x + 1] != '1')
		flood_fill(copy, x + 1, y);
	return (return_value);
}

// used to check if the map is surrounded by walls
int flood_fill_check(char **map_arr)
{
	char	**copy;
	int 	x;
	int 	y;

	x = 0;
	y = 0;
	copy = copy_array(map_arr);
	find_spawn(copy, &x, &y);
	if (flood_fill(copy, x, y) == EXIT_FAILURE)
		return (free_array_copy(copy), EXIT_FAILURE);
	free_array_copy(copy);
	return (EXIT_SUCCESS);
}
