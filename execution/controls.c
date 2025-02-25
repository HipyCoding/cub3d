/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:50:03 by candrese          #+#    #+#             */
/*   Updated: 2025/02/25 11:00:33 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	movement(t_cub3d *c, char s)
{
	if (s == 'w')
		c->pos_y -= c->pos_y * c->speed;
	else if (s == 'a')
		c->pos_x -= c->pos_x * c->speed;
	else if (s == 's')
		c->pos_y += c->pos_y * c->speed;
	else if (s == 'd')
		c->pos_x += c->pos_x * c->speed;
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
}

