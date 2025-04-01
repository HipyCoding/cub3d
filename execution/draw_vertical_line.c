/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:02:00 by christian         #+#    #+#             */
/*   Updated: 2025/04/01 09:07:46 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void draw_ceiling(t_cub3d *c, int x, int draw_start)
{
	int y;

	y = 0;
	while (y < draw_start)
	{
		mlx_put_pixel(c->img, x, y, 0x808080FF);
		y++;
	}
}

static void draw_floor(t_cub3d *c, int x, int draw_end)
{
	int y;

	y = draw_end;
	while (y < HEIGHT)
	{
		mlx_put_pixel(c->img, x, y, 0x404040FF);
		y++;
	}
}

// coordinate specific texture color
static uint32_t get_texture_color(mlx_texture_t *texture, int tex_x, int tex_y)
{
	uint8_t *pixel;
	uint32_t color;

	pixel = &texture->pixels[(tex_y * texture->width + tex_x) * 4];
	color = (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
	
	return (color);
}

// vertical collumn
static void draw_textured_wall(t_cub3d *c, int x, mlx_texture_t *texture, 
						int tex_x, int draw_start, int draw_end, int line_height)
{
	int y;
	int tex_y;
	double step;
	double tex_pos;
	uint32_t color;

	step = (double)texture->height / line_height;
	tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)tex_pos % texture->height;
		color = get_texture_color(texture, tex_x, tex_y);
		mlx_put_pixel(c->img, x, y, color);
		tex_pos += step;
		y++;
	}
}

void draw_vertical_line(t_cub3d *c, int x, mlx_texture_t *texture, int tex_x)
{
	draw_ceiling(c, x, c->ray.draw_start);
	draw_textured_wall(c, x, texture, tex_x, c->ray.draw_start, 
					c->ray.draw_end, c->ray.line_height);
	draw_floor(c, x, c->ray.draw_end);
}
