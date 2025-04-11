/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:02:00 by christian         #+#    #+#             */
/*   Updated: 2025/04/11 22:31:42 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_ceiling(t_cub3d *c, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		mlx_put_pixel(c->img, x, y, (int)c->texture.c);
		y++;
	}
}

static void	draw_floor(t_cub3d *c, int x, int draw_end)
{
	int	y;

	y = draw_end;
	while (y < HEIGHT)
	{
		mlx_put_pixel(c->img, x, y, (int)c->texture.f);
		y++;
	}
}

// coordinate specific texture color
static uint32_t	get_texture_color(mlx_texture_t *texture, int tex_x, int tex_y)
{
	uint8_t		*pixel;
	uint32_t	color;

	pixel = &texture->pixels[(tex_y * texture->width + tex_x) * 4];
	color = (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
	return (color);
}

// vertical collumn
static void	draw_textured_wall(t_cub3d *c, int x,
				mlx_texture_t *texture, int tex_x)
{
	int			y;
	int			tex_y;
	double		step;
	double		tex_pos;
	uint32_t	color;

	step = (double)texture->height / c->ray.line_height;
	tex_pos = (c->ray.draw_start - HEIGHT / 2 + c->ray.line_height / 2) * step;
	y = c->ray.draw_start;
	while (y < c->ray.draw_end)
	{
		tex_y = (int)tex_pos % texture->height;
		color = get_texture_color(texture, tex_x, tex_y);
		mlx_put_pixel(c->img, x, y, color);
		tex_pos += step;
		y++;
	}
}

void	draw_vertical_line(t_cub3d *c, int x, mlx_texture_t *texture, int tex_x)
{
	draw_ceiling(c, x, c->ray.draw_start);
	draw_textured_wall(c, x, texture, tex_x);
	draw_floor(c, x, c->ray.draw_end);
}
