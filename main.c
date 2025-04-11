/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:19:46 by candrese          #+#    #+#             */
/*   Updated: 2025/04/11 22:24:34 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parsing/parse.h"

void	init_player_direction(t_player *player)
{
	if (player->spawn_dir == 'N')
	{
		player->dir_y = -1.0;
		player->plane_x = 0.66;
	}
	else if (player->spawn_dir == 'S')
	{
		player->dir_y = 1.0;
		player->plane_x = -0.66;
	}
	else if (player->spawn_dir == 'E')
	{
		player->dir_x = 1.0;
		player->plane_y = 0.66;
	}
	else if (player->spawn_dir == 'W')
	{
		player->dir_x = -1.0;
		player->plane_y = -0.66;
	}
}

void	init_player(t_player *player)
{
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->speed = 0.03;
	player->r_speed = 0.05;
	init_player_direction(player);
}

void	init_map(t_cub3d *c)
{
	int	i;
	int	row_len;

	c->map_height = 0;
	while (c->test_map[c->map_height])
		c->map_height++;
	c->map_width = 0;
	i = 0;
	while (i < c->map_height)
	{
		row_len = ft_strlen(c->test_map[i]);
		if (row_len > c->map_width)
			c->map_width = row_len;
		i++;
	}
}

void	init_to_winit(t_cub3d *c)
{
	c->line_pos = 100;
	c->direction = 1;
	c->line_length = 200;
	c->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	c->map_height = 0;
	if (!c->mlx || !c->img || !c->test_map)
		exit(EXIT_FAILURE);
	init_player(&c->player);
	init_map(c);
	load_textures(c);
}

int	main(int argc, char **argv)
{
	t_cub3d	c;

	c.test_map = parse(argc, argv, &c);
	init_to_winit(&c);
	mlx_loop_hook(c.mlx, &main_loop, &c);
	mlx_loop(c.mlx);
	clean_exit(&c);
	return (EXIT_SUCCESS);
}

// atexit(leaks);
