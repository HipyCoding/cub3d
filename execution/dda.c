/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 05:26:42 by candrese          #+#    #+#             */
/*   Updated: 2025/03/08 22:09:24 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_dda_variables(t_cub3d *c, double ray_dir_x, double ray_dir_y)
{

	c->ray.dir_x = ray_dir_x;
	c->ray.dir_y = ray_dir_y;
	c->ray.map_x = c->player.pos_x;
	c->ray.map_y = c->player.pos_y;
	
	// calculate deltas (distance to next x or y grid)
	if (ray_dir_x == 0) // in case devision by 0
		c->ray.delta_dist_x = INFINITY;
	else
		c->ray.delta_dist_x = fabs(1 / ray_dir_x);
		
	if (ray_dir_y == 0)
		c->ray.delta_dist_y = INFINITY;
	else
		c->ray.delta_dist_y = fabs(1 / ray_dir_y);
}

void calculate_step_and_side_dist(t_cub3d *c)
{

	if (c->ray.dir_x < 0)
	{
		c->ray.step_x = -1;
		c->ray.side_dist_x = (c->player.pos_x - c->ray.map_x) * c->ray.delta_dist_x;
	}
	else
	{
		c->ray.step_x = 1;
		c->ray.side_dist_x = (c->ray.map_x + 1.0 - c->player.pos_x) * c->ray.delta_dist_x;
	}
	if (c->ray.dir_y < 0)
	{
		c->ray.step_y = -1;
		c->ray.side_dist_y = (c->player.pos_y - c->ray.map_y) * c->ray.delta_dist_y;
	}
	else
	{
		c->ray.step_y = 1;
		c->ray.side_dist_y = (c->ray.map_y + 1.0 - c->player.pos_y) * c->ray.delta_dist_y;
	}
}

void perform_dda_algorithm(t_cub3d *c)
{
	int hit;
	
	hit = 0;
	while (hit == 0)
	{
		// for jumping to next map square
		if (c->ray.side_dist_x < c->ray.side_dist_y)
		{
			c->ray.side_dist_x += c->ray.delta_dist_x;
			c->ray.map_x += c->ray.step_x;
			c->ray.side = 0; // x-side hit
		}
		else
		{
			c->ray.side_dist_y += c->ray.delta_dist_y;
			c->ray.map_y += c->ray.step_y;
			c->ray.side = 1; // y-side hit
		}
		// check if ray hit wall
		if (c->ray.map_y >= 0 && c->ray.map_x >= 0 && c->test_map[c->ray.map_y] &&
			c->ray.map_x < (int)ft_strlen(c->test_map[c->ray.map_y]) &&
			c->test_map[c->ray.map_y][c->ray.map_x] == '1')
			hit = 1;
	}
}

void calculate_wall_dist(t_cub3d *c)
{
	if (c->ray.side == 0)
		c->ray.wall_dist = (c->ray.map_x - c->player.pos_x + 
			(1 - c->ray.step_x) / 2) / c->ray.dir_x;
	else
		c->ray.wall_dist = (c->ray.map_y - c->player.pos_y + 
			(1 - c->ray.step_y) / 2) / c->ray.dir_y;
}

// main dda function
void perform_dda(t_cub3d *c, double ray_dir_x, double ray_dir_y)
{

	init_dda_variables(c, ray_dir_x, ray_dir_y);
	calculate_step_and_side_dist(c);
	perform_dda_algorithm(c);
	calculate_wall_dist(c);
	calculate_wall_height(c);
}
