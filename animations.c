/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:32:15 by candrese          #+#    #+#             */
/*   Updated: 2025/02/19 16:50:27 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_cub3d(t_cub3d *c)
{
	int i;
	
	c->line_pos += c->direction * 5;

	if (c->img)
		mlx_delete_image(c->mlx, c->img);
	c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	if (!c->img)
		exit(EXIT_FAILURE);
	mlx_image_to_window(c->mlx, c->img, 0, 0);
	
	i = 0;
	while (i < c->line_length && c->line_pos + i < WIDTH)
	{
		if (c->line_pos + i >= 0 && c->line_pos + i < WIDTH)
			mlx_put_pixel(c->img, c->line_pos + i, HEIGHT / 2, 0xFF0000FF);
		i++;
	}
}
