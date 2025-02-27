/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:50:03 by candrese          #+#    #+#             */
/*   Updated: 2025/02/27 06:39:40 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	movement(t_cub3d *c, char s)
{
	if (s == 'w')
		c->player.pos_y -= c->player.pos_y * c->player.speed;
	else if (s == 'a')
		c->player.pos_x -= c->player.pos_x * c->player.speed;
	else if (s == 's')
		c->player.pos_y += c->player.pos_y * c->player.speed;
	else if (s == 'd')
		c->player.pos_x += c->player.pos_x * c->player.speed;
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

