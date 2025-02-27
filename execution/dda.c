/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 05:26:42 by candrese          #+#    #+#             */
/*   Updated: 2025/02/27 07:17:42 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_dda_variables(t_cub3d *c, double ray_dir_x, double ray_dir_y, 
			int *map_x, int *map_y, double *delta_dist_x, double *delta_dist_y)
{
	*map_x = (int)c->player.pos_x;
	*map_y = (int)c->player.pos_y;
	
	// calculate deltas (distance to next x or y grid)
	if (ray_dir_x == 0) // in case devision by 0
		*delta_dist_x = INFINITY;
	else
		*delta_dist_x = fabs(1 / ray_dir_x);
		
	if (ray_dir_y == 0)
		*delta_dist_y = INFINITY;
	else
		*delta_dist_y = fabs(1 / ray_dir_y);
}

void calculate_step_and_side_dist(t_cub3d *c, double ray_dir_x, double ray_dir_y,
				 int map_x, int map_y, double delta_dist_x, double delta_dist_y,
				 int *step_x, int *step_y, double *side_dist_x, double *side_dist_y)
{
	// step and side distance for x
	if (ray_dir_x < 0)
	{
		*step_x = -1;
		*side_dist_x = (c->player.pos_x - map_x) * delta_dist_x;
	}
	else
	{
		*step_x = 1;
		*side_dist_x = (map_x + 1.0 - c->player.pos_x) * delta_dist_x;
	}
	
	// same for y
	if (ray_dir_y < 0)
	{
		*step_y = -1;
		*side_dist_y = (c->player.pos_y - map_y) * delta_dist_y;
	}
	else
	{
		*step_y = 1;
		*side_dist_y = (map_y + 1.0 - c->player.pos_y) * delta_dist_y;
	}
}

void perform_dda_algorithm(t_cub3d *c, 
			 int *map_x, int *map_y, int step_x, int step_y,
			 double *side_dist_x, double *side_dist_y,
			 double delta_dist_x, double delta_dist_y, int *side)
{
	int hit = 0;
	
	while (hit == 0)
	{
		// for jumping to next map square
		if (*side_dist_x < *side_dist_y)
		{
			*side_dist_x += delta_dist_x;
			*map_x += step_x;
			*side = 0; // x-side hit
		}
		else
		{
			*side_dist_y += delta_dist_y;
			*map_y += step_y;
			*side = 1; // y-side hit
		}
		// check if ray hit wall
		if (*map_y >= 0 && *map_x >= 0 && c->test_map[*map_y] &&
			*map_x < (int)ft_strlen(c->test_map[*map_y]) &&
			c->test_map[*map_y][*map_x] == '1')
			hit = 1;
	}
}

double calculate_wall_dist(t_cub3d *c, int map_x, int map_y, 
			double ray_dir_x, double ray_dir_y,
			int step_x, int step_y, int side)
{
	if (side == 0)
		return ((map_x - c->player.pos_x + (1 - step_x) / 2) / ray_dir_x);
	else
		return ((map_y - c->player.pos_y + (1 - step_y) / 2) / ray_dir_y);
}

// main dda function
double perform_dda(t_cub3d *c, double ray_dir_x, double ray_dir_y, int *side)
{
	int map_x, map_y;
	int step_x, step_y;
	double side_dist_x, side_dist_y;
	double delta_dist_x, delta_dist_y;
	init_dda_variables(c, ray_dir_x, ray_dir_y, &map_x, &map_y, 
		&delta_dist_x, &delta_dist_y);
	calculate_step_and_side_dist(c, ray_dir_x, ray_dir_y, map_x, map_y,
			delta_dist_x, delta_dist_y, &step_x, &step_y,
			&side_dist_x, &side_dist_y);
	perform_dda_algorithm(c, &map_x, &map_y, step_x, step_y,
			&side_dist_x, &side_dist_y, delta_dist_x, delta_dist_y, side);
	return (calculate_wall_dist(c, map_x, map_y, ray_dir_x, ray_dir_y,
			step_x, step_y, *side));
}
