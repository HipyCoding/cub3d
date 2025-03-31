/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:32:15 by candrese          #+#    #+#             */
/*   Updated: 2025/03/31 05:38:27 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_ray_direction(t_cub3d *c, int x, double *ray_dir_x, double *ray_dir_y)
{
	double	camera_x;

	camera_x = 2.0 * x / WIDTH - 1.0;
	*ray_dir_x = c->player.dir_x + c->player.plane_x * camera_x;
	*ray_dir_y = c->player.dir_y + c->player.plane_y * camera_x;
}


void	calculate_wall_height(t_cub3d *c)
{
	// height of the line
	c->ray.line_height = (int)(HEIGHT / c->ray.wall_dist);
	
	// lowest and highest pixel to fill
	c->ray.draw_start = -c->ray.line_height / 2 + HEIGHT / 2;
	if (c->ray.draw_start < 0)
		c->ray.draw_start = 0;
	
	c->ray.draw_end = c->ray.line_height / 2 + HEIGHT / 2;
	if (c->ray.draw_end >= HEIGHT)
		c->ray.draw_end = HEIGHT - 1;
}

// -------might use for minimapimplementation later on-------
//
// void	draw_line(t_cub3d *c, int x1, int y1, int x2, int y2, uint32_t color)
// {
// 	int	dx;
// 	int	dy;
// 	int	sx;
// 	int	sy;
// 	int	err;
// 	int	e2;

// 	dx = abs(x2 - x1);
// 	dy = -abs(y2 - y1);
// 	sx = (x1 < x2) ? 1 : -1;
// 	sy = (y1 < y2) ? 1 : -1;
// 	err = dx + dy;
// 	while (1)
// 	{
// 		if (x1 >= 0 && x1 < WIDTH && y1 >= 0 && y1 < HEIGHT)
// 			mlx_put_pixel(c->img, x1, y1, color);
// 		if (x1 == x2 && y1 == y2)
// 			break ;
// 		e2 = 2 * err;
// 		if (e2 >= dy)
// 		{
// 			if (x1 == x2)
// 				break ;
// 			err += dy;
// 			x1 += sx;
// 		}
// 		if (e2 <= dx)
// 		{
// 			if (y1 == y2)
// 				break ;
// 			err += dx;
// 			y1 += sy;
// 		}
// 	}
// }

// void	draw_rays(t_cub3d *c, int square_size)
// {
// 	int	x;
// 	double	ray_dir_x;
// 	double	ray_dir_y;
// 	double	wall_x;
// 	double	wall_y;

// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		calculate_ray_direction(c, x, &ray_dir_x, &ray_dir_y);
// 		perform_dda(c, ray_dir_x, ray_dir_y);
// 		// wall hit position
// 		wall_x = c->player.pos_x + ray_dir_x * c->ray.wall_dist;
// 		wall_y = c->player.pos_y + ray_dir_y * c->ray.wall_dist;

// 		// ray from player position
// 		draw_line(c, c->player.pos_x * square_size, c->player.pos_y * square_size,
// 			wall_x * square_size, wall_y * square_size,
// 			0x00FF00FF); // green for rays
// 		x += WIDTH / 11;
// 	}
// 	// direction vector
// 	draw_line(c, c->player.pos_x * square_size, c->player.pos_y * square_size,
// 		c->player.pos_x * square_size + c->player.dir_x * square_size * 3,
// 		c->player.pos_y * square_size + c->player.dir_y * square_size * 3, 
// 		0x0000FFFF); // blue for direction
// }

// // builds 2d map for testing purpusos and casts rays from player onto FOV
// void	draw_minimap(t_cub3d *c)
// {
// 	int		i;
// 	int		j;
// 	int		square_size;
	
// 	square_size = HEIGHT / 12;
// 	// map squares
// 	i = 0;
// 	while (c->test_map[i])
// 	{
// 		j = 0;
// 		while (c->test_map[i][j])
// 		{
// 			if (c->test_map[i][j] == '1')
// 				draw_rectangle(c, j * square_size, i * square_size, 
// 							square_size, square_size, 0x808080FF); // grey is walls
// 			else
// 				draw_rectangle(c, j * square_size, i * square_size, 
// 							square_size, square_size, 0xFFFFFFFF); // white is empty
// 			j++;
// 		}
// 		i++;
// 	}
// 	// player
// 	draw_rectangle(c, c->player.pos_x * square_size - 2, c->player.pos_y * square_size - 2, 
// 				5, 5, 0xFF0000FF); // red for player
// }

// void	draw_rectangle(t_cub3d *c, int x, int y, int width, int height, uint32_t color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < height)
// 	{
// 		j = 0;
// 		while (j < width)
// 		{
// 			if (x + j >= 0 && x + j < WIDTH && y + i >= 0 && y + i < HEIGHT)
// 				mlx_put_pixel(c->img, x + j, y + i, color);
// 			j++;
// 		}
// 		 i++;
// 	}
// }
