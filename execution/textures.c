/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 05:10:05 by christian         #+#    #+#             */
/*   Updated: 2025/04/01 09:10:49 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_textures(t_cub3d *c)
{
	c->texture.north = mlx_load_png(c->texture.no_texture_path);
	c->texture.south = mlx_load_png(c->texture.so_texture_path);
	c->texture.east = mlx_load_png(c->texture.ea_texture_path);
	c->texture.west = mlx_load_png(c->texture.we_texture_path);
	if (!c->texture.north || !c->texture.south || 
		!c->texture.east || !c->texture.west)
	{
		ft_putstr_fd("Error: Failed to load textures\n", STDERR_FILENO);
		clean_exit(c);
	}
	c->texture.tex_width = c->texture.north->width;
	c->texture.tex_height = c->texture.north->height;
}

static mlx_texture_t *select_wall_texture(t_cub3d *c)
{
	// x-side wall
	if (c->ray.side == 0)
	{
		// if ray moving east = west facing
		if (c->ray.step_x > 0)
			return (c->texture.east);
		// if ray moving west = east facing
		else
			return (c->texture.west);
	}
	// y-side wall
	{
		// if ray moving south = north facing
		if (c->ray.step_y > 0)
			return (c->texture.south);
		// if ray moving north = south facing
		else
			return (c->texture.north);
	}
}

// x coordinate where ray hits wall
static double wall_xx(t_cub3d *c)
{
	double wall_x;
	
	if (c->ray.side == 0)
		wall_x = c->player.pos_y + c->ray.wall_dist * c->ray.dir_y;
	else
		wall_x = c->player.pos_x + c->ray.wall_dist * c->ray.dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

// x coordinate of texture
static int texture_x(t_cub3d *c, double wall_x, mlx_texture_t *texture)
{
	int tex_x;
	
	tex_x = (int)(wall_x * texture->width);
	// flip x coordinate if needed
	if ((c->ray.side == 0 && c->ray.dir_x > 0) || 
		(c->ray.side == 1 && c->ray.dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

void draw_textured_column(t_cub3d *c, int x)
{
	mlx_texture_t *texture;
	double wall_x;
	int tex_x;
	
	texture = select_wall_texture(c);
	wall_x = wall_xx(c);
	tex_x = texture_x(c, wall_x, texture);
	draw_vertical_line(c, x, texture, tex_x);
}
