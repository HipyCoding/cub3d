/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ainmation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:32:15 by candrese          #+#    #+#             */
/*   Updated: 2025/02/19 13:42:45 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_cub3d(t_cub3d *c)
{
	mlx_delete_image(c->mlx, c->img);
	c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(c->mlx, c->img, 0, 0);
}
