/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 02:06:43 by candrese          #+#    #+#             */
/*   Updated: 2025/03/31 05:52:51 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	main_loop(void *param)
{
	t_cub3d	*c;

	c = (t_cub3d *)param;
	key_input(c);
	if (c->img)
		mlx_delete_image(c->mlx, c->img);
	c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	if (!c->img)
		clean_exit(c);
	draw_3d_rays(c);
	mlx_image_to_window(c->mlx, c->img, 0, 0);
}

// draw_minimap(c);
// draw_rays(c, HEIGHT / 12);
