/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:50:03 by candrese          #+#    #+#             */
/*   Updated: 2025/04/01 09:13:48 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	wall_check(t_cub3d *c, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = x;
	map_y = y;
	if (map_y < 0 || map_x < 0 || map_y >= c->map_height || 
		map_x >= (int)ft_strlen(c->test_map[map_y]))
		return (true);
	if (c->test_map[map_y][map_x] == '1')
		return (true);
	
	return (false);
}

void	rotation(t_cub3d *c, char a)
{
	double	temp_dir;
	double	temp_plane;
	double	rot;

	temp_dir = c->player.dir_x;
	temp_plane = c->player.plane_x;
	if(a == 'r')
		rot = 1.0;
	else
		rot = -1.0;
	
	// direction vector matrix
	c->player.dir_x = c->player.dir_x * cos(c->player.r_speed * rot)
	- c->player.dir_y * sin(c->player.r_speed * rot);
	c->player.dir_y = temp_dir * sin(c->player.r_speed * rot)
	+ c->player.dir_y * cos(c->player.r_speed * rot);
	
	// plane matrix
	c->player.plane_x = c->player.plane_x * cos(c->player.r_speed * rot)
	- c->player.plane_y * sin(c->player.r_speed * rot);
	c->player.plane_y = temp_plane * sin(c->player.r_speed * rot)
	+ c->player.plane_y * cos(c->player.r_speed * rot);
}

void	movement(t_cub3d *c, char s, double x, double y)
{
	if (s == 'w')
	{
		x = c->player.dir_x * c->player.speed;
		y = c->player.dir_y * c->player.speed;
	}
	else if (s == 's')
	{
		x = -c->player.dir_x * c->player.speed;
		y = -c->player.dir_y * c->player.speed;
	}
	else if (s == 'a')
	{
		x = -c->player.plane_x * c->player.speed;
		y = -c->player.plane_y * c->player.speed;
	}
	else
	{
		x = c->player.plane_x * c->player.speed;
		y = c->player.plane_y * c->player.speed;
	}
	if (!wall_check(c, c->player.pos_x + x, c->player.pos_y))
		c->player.pos_x += x;
	if (!wall_check(c, c->player.pos_x, c->player.pos_y + y))
		c->player.pos_y += y;
}

void	key_input(t_cub3d *c)
{
	if (mlx_is_key_down(c->mlx, MLX_KEY_ESCAPE))
		clean_exit(c);
	else if (mlx_is_key_down(c->mlx, MLX_KEY_W))
		movement(c, 'w', 0, 0);
	else if (mlx_is_key_down(c->mlx, MLX_KEY_A))
		movement(c, 'a', 0, 0);
	else if (mlx_is_key_down(c->mlx, MLX_KEY_S))
		movement(c, 's', 0, 0);
	else if (mlx_is_key_down(c->mlx, MLX_KEY_D))
		movement(c, 'd', 0, 0);	
	else if (mlx_is_key_down(c->mlx, MLX_KEY_LEFT))
		rotation(c, 'l');
	else if (mlx_is_key_down(c->mlx, MLX_KEY_RIGHT))
		rotation(c, 'r');
}

// --------for debugging---------

// 	else if (mlx_is_key_down(c->mlx, MLX_KEY_F))
// 		print_wall_info(c);
//
// #include <stdio.h>
// void	print_wall_info(t_cub3d *c)
// {
// 	int		x;
// 	double	ray_dir_x;
// 	double	ray_dir_y;
	
// 	printf("\n--- wall info ---\n");
	
// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		calculate_ray_direction(c, x, &ray_dir_x, &ray_dir_y);
// 		perform_dda(c, ray_dir_x, ray_dir_y);
// 		printf("ray %d: wall x/y (%d,%d), distance: %.2f, height: %d pixels (y: %d to %d)\n", 
// 			x, c->ray.map_x, c->ray.map_y, c->ray.wall_dist, 
// 			c->ray.line_height, c->ray.draw_start, c->ray.draw_end);
//	
// 		x += WIDTH / 11;
// 	}
// 	printf("------------\n");
// }
