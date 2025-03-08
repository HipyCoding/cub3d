/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 05:10:07 by candrese          #+#    #+#             */
/*   Updated: 2025/03/08 01:57:22 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


// for every x coordinate we draw a collumn, starting from ceiling
void	draw_collumn(t_cub3d *c, int x, uint32_t color)
{
	int	y;

	// for ceiling
	y = 0;
	while (y < c->ray.draw_start)
	{
		mlx_put_pixel(c->img, x, y, 0x808080FF); // grey = ceiling
		y++;
	}
	// wall
	while (y < c->ray.draw_end)
	{
		mlx_put_pixel(c->img, x, y, color);
		y++;
	}
	
	// floor
	while (y < HEIGHT)
	{
		mlx_put_pixel(c->img, x, y, 0x404040FF); // darker tone = floor
		y++;
	}
}

void	draw_3d_rays(t_cub3d *c)
{
	int			x;
	double		ray_dir_x;
	double		ray_dir_y;
	uint32_t	color;

	x = 0;
	while (x < WIDTH)
	{
		calculate_ray_direction(c, x, &ray_dir_x, &ray_dir_y);
		// memorizes all data in the struct
		perform_dda(c, ray_dir_x, ray_dir_y);
		
		// to differentiate where wall is facing
		if (c->ray.side == 0)
			color = 0x00FFFFFF; // cyan is x-side
		else
			color = 0x000080FF; // navy for y-side
		draw_collumn(c, x, color);
		x++;
	}
}
