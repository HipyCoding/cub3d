/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:32:15 by candrese          #+#    #+#             */
/*   Updated: 2025/02/25 09:35:55 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	put_cub3d(t_cub3d *c)
// {
// 	int	start_x;
// 	int	start_y;
// 	int	end_x;
// 	int	end_y;

// 	if (c->img)
// 		mlx_delete_image(c->mlx, c->img);
// 	c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
// 	if (!c->img)
// 		exit(EXIT_FAILURE);
// 	mlx_image_to_window(c->mlx, c->img, 0, 0);
// 	start_x = c->line_pos;
// 	start_y = HEIGHT / 2;
// 	end_x = c->line_pos + c->line_length;
// 	end_y = HEIGHT / 2;
// 	draw_line(c, start_x, start_y, end_x, end_y, RED);
// 	draw_line(c, start_x, start_y - 50, end_x, start_y + 50, RED);
// }

void	draw_line(t_cub3d *c, int x1, int y1, int x2, int y2, uint32_t color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x2 - x1);
	dy = -abs(y2 - y1);
	sx = (x1 < x2) ? 1 : -1;
	sy = (y1 < y2) ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		if (x1 >= 0 && x1 < WIDTH && y1 >= 0 && y1 < HEIGHT)
			mlx_put_pixel(c->img, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			if (x1 == x2)
				break ;
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx)
		{
			if (y1 == y2)
				break ;
			err += dx;
			y1 += sy;
		}
	}
}

void	calculate_ray_direction(t_cub3d *c, int x, double *ray_dir_x, double *ray_dir_y)
{
	double	camera_x;

	camera_x = 2.0 * x / WIDTH - 1.0;
	*ray_dir_x = c->dir_x + c->plane_x * camera_x;
	*ray_dir_y = c->dir_y + c->plane_y * camera_x;
}

// builds 2d map for testing purpusos
void	draw_minimap(t_cub3d *c)
{
	int		i;
	int		j;
	int		square_size;
	int		x = 0;
	double	ray_dir_x;
	double	ray_dir_y;
	
	square_size = HEIGHT / 12;
	if (c->img)
		mlx_delete_image(c->mlx, c->img);
	c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	if (!c->img)
		clean_exit(c);
	// map squares
	i = 0;
	while (c->test_map[i])
	{
		j = 0;
		while (c->test_map[i][j])
		{
			if (c->test_map[i][j] == '1')
				draw_rectangle(c, j * square_size, i * square_size, 
							square_size, square_size, 0x808080FF); // grey is walls
			else
				draw_rectangle(c, j * square_size, i * square_size, 
							square_size, square_size, 0xFFFFFFFF); // white is empty
			j++;
		}
		i++;
	}
	// player
	draw_rectangle(c, c->pos_x * square_size - 2, c->pos_y * square_size - 2, 
				5, 5, 0xFF0000FF); // red for player
	i = 0;
	// ray directions
	while (x < WIDTH)
	{
		calculate_ray_direction(c, x, &ray_dir_x, &ray_dir_y);
		draw_line(c, c->pos_x * square_size, c->pos_y * square_size,
			c->pos_x * square_size + ray_dir_x * square_size * 2,
			c->pos_y * square_size + ray_dir_y * square_size * 2,
			0x00FF00FF); // green for rays
		x += WIDTH / 10;
	}
	// direction vector
	draw_line(c, c->pos_x * square_size, c->pos_y * square_size,
		c->pos_x * square_size + c->dir_x * square_size * 3,
		c->pos_y * square_size + c->dir_y * square_size * 3, 0x0000FFFF); // blue for direction
	mlx_image_to_window(c->mlx, c->img, 0, 0);
}

void	draw_rectangle(t_cub3d *c, int x, int y, int width, int height, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (x + j >= 0 && x + j < WIDTH && y + i >= 0 && y + i < HEIGHT)
				mlx_put_pixel(c->img, x + j, y + i, color);
			j++;
		}
		 i++;
	}
}
