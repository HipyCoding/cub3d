/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:50:03 by candrese          #+#    #+#             */
/*   Updated: 2025/03/08 09:16:37 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#include <stdio.h>
void	print_wall_info(t_cub3d *c)
{
	int		x;
	double	ray_dir_x;
	double	ray_dir_y;
	
	printf("\n--- wall info ---\n");
	
	x = 0;
	while (x < WIDTH)
	{
		calculate_ray_direction(c, x, &ray_dir_x, &ray_dir_y);
		perform_dda(c, ray_dir_x, ray_dir_y);
		printf("ray %d: wall x/y (%d,%d), distance: %.2f, height: %d pixels (y: %d to %d)\n", 
			x, c->ray.map_x, c->ray.map_y, c->ray.wall_dist, 
			c->ray.line_height, c->ray.draw_start, c->ray.draw_end);
		
		x += WIDTH / 11;
	}
	printf("------------\n");
}

bool	wall_check(t_cub3d *c, double x, double y)
{
	int	map_x;
	int map_y;

	map_x = x;
	map_y = y;
	if (map_y < 0 || map_x < 0 || map_y >= c->map_height || 
		map_x >= (int)ft_strlen(c->test_map[map_y]))
		return (true);
	if (c->test_map[map_y][map_x] == '1')
		return (1);
	return (false);
}

void	movement(t_cub3d *c, char s)
{
	if (s == 'w' && !wall_check(c, c->player.pos_x,
		c->player.pos_y - c->player.speed))
		c->player.pos_y -= c->player.pos_y * c->player.speed;
	else if (s == 'a' && !wall_check(c,
		c->player.pos_x -  c->player.speed, c->player.pos_y))
		c->player.pos_x -= c->player.pos_x * c->player.speed;
	else if (s == 's' && !wall_check(c, c->player.pos_x,
		c->player.pos_y + c->player.speed))
		c->player.pos_y += c->player.pos_y * c->player.speed;
	else if (s == 'd' && !wall_check(c,
		c->player.pos_x + c->player.speed, c->player.pos_y))
	c->player.pos_x += c->player.pos_x * c->player.speed;
}

void	key_input(t_cub3d *c)
{
	if (mlx_is_key_down(c->mlx, MLX_KEY_ESCAPE))
		clean_exit(c);
	else if (mlx_is_key_down(c->mlx, MLX_KEY_W))
		movement(c, 'w');
	else if (mlx_is_key_down(c->mlx, MLX_KEY_A))
		movement(c, 'a');
	else if (mlx_is_key_down(c->mlx, MLX_KEY_S))
		movement(c, 's');
	else if (mlx_is_key_down(c->mlx, MLX_KEY_D))
		movement(c, 'd');	
	else if (mlx_is_key_down(c->mlx, MLX_KEY_F))
		print_wall_info(c);
}

