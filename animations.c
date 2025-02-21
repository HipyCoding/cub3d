/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:32:15 by candrese          #+#    #+#             */
/*   Updated: 2025/02/21 08:41:30 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_cub3d(t_cub3d *c)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;

	if (c->img)
		mlx_delete_image(c->mlx, c->img);
	c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	if (!c->img)
		exit(EXIT_FAILURE);
	mlx_image_to_window(c->mlx, c->img, 0, 0);
	start_x = c->line_pos;
	start_y = HEIGHT / 2;
	end_x = c->line_pos + c->line_length;
	end_y = HEIGHT / 2;
	draw_line(c, start_x, start_y, end_x, end_y, RED);
	draw_line(c, start_x, start_y - 50, end_x, start_y + 50, RED);
}

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