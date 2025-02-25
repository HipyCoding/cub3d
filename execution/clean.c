/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:57:33 by candrese          #+#    #+#             */
/*   Updated: 2025/02/25 02:07:28 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_exit(t_cub3d *c)
{
	if (c->img)
		mlx_delete_image(c->mlx, c->img);
	if (c->mlx)
		mlx_terminate(c->mlx);
	exit(EXIT_SUCCESS);
}

