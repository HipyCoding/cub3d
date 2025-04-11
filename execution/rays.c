/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 05:10:07 by candrese          #+#    #+#             */
/*   Updated: 2025/04/11 21:14:44 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_3d_rays(t_cub3d *c)
{
	int		x;
	double	ray_dir_x;
	double	ray_dir_y;

	x = 0;
	while (x < WIDTH)
	{
		calculate_ray_direction(c, x, &ray_dir_x, &ray_dir_y);
		perform_dda(c, ray_dir_x, ray_dir_y);
		draw_textured_column(c, x);
		x++;
	}
}

// for every x coordinate we draw a collumn, starting from ceiling
// void	draw_collumn(t_cub3d *c, int x, uint32_t color)
// {
// 	int	y;

// 	// for ceiling
// 	y = 0;
// 	while (y < c->ray.draw_start)
// 	{
// 		mlx_put_pixel(c->img, x, y, 0x808080FF); // grey = ceiling
// 		y++;
// 	}
// 	// wall
// 	while (y < c->ray.draw_end)
// 	{
// 		mlx_put_pixel(c->img, x, y, color);
// 		y++;
// 	}
//	
// 	// floor
// 	while (y < HEIGHT)
// 	{
// 		mlx_put_pixel(c->img, x, y, 0x404040FF); // darker tone = floor
// 		y++;
// 	}
// }
