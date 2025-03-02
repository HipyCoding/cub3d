/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:50:03 by candrese          #+#    #+#             */
/*   Updated: 2025/03/02 22:23:26 by candrese         ###   ########.fr       */
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

void	movement(t_cub3d *c, char s)
{
	if (s == 'w')
		c->player.pos_y -= c->player.pos_y * c->player.speed;
	else if (s == 'a')
		c->player.pos_x -= c->player.pos_x * c->player.speed;
	else if (s == 's')
		c->player.pos_y += c->player.pos_y * c->player.speed;
	else if (s == 'd')
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

