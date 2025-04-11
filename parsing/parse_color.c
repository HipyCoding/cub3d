/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 06:21:41 by candrese          #+#    #+#             */
/*   Updated: 2025/04/11 23:15:17 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../cub3d.h"

int	parse_rgb_value(char **map, int *value)
{
	*value = get_num(map);
	if (!(*value >= 0 && *value <= 255))
	{
		map[0] = NULL;
		return (0);
	}
	return (1);
}

int	skip_and_check_comma(char **map)
{
	while (map[0][0] == ' ' || map[0][0] == '\t' || map[0][0] == '\n')
		map[0]++;
	if (map[0][0] == ',')
	{
		map[0]++;
		return (1);
	}
	map[0] = NULL;
	return (0);
}

static int	check_color_format(char **map)
{
	while (map[0][0] && map[0][0] != '\n')
	{
		if (map[0][0] != ' ' && map[0][0] != '\t')
		{
			if (map[0][0] == ',' || (map[0][0] >= '0' && map[0][0] <= '9'))
			{
				map[0] = NULL;
				return (0);
			}
		}
		map[0]++;
	}
	return (1);
}

static int	store_color_value(t_texture *texture, uint32_t color, int instance)
{
	if (instance == F)
		texture->f = color;
	else if (instance == C)
		texture->c = color;
	return (1);
}

void	handle_color(char **map, t_texture *texture, int instance)
{
	int			r;
	int			g;
	int			b;
	uint32_t	color;

	if (!parse_rgb_value(map, &r))
		return ;
	if (!skip_and_check_comma(map) || !parse_rgb_value(map, &g))
		return ;
	if (!skip_and_check_comma(map) || !parse_rgb_value(map, &b))
		return ;
	if (!check_color_format(map))
		return ;
	color = create_rgba(r, g, b);
	if (!store_color_value(texture, color, instance))
		map[0] = NULL;
}
