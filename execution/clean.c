/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:57:33 by candrese          #+#    #+#             */
/*   Updated: 2025/04/11 21:08:10 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_textures(t_cub3d *c)
{
	if (c->texture.north)
		mlx_delete_texture(c->texture.north);
	if (c->texture.south)
		mlx_delete_texture(c->texture.south);
	if (c->texture.east)
		mlx_delete_texture(c->texture.east);
	if (c->texture.west)
		mlx_delete_texture(c->texture.west);
	c->texture.north = NULL;
	c->texture.south = NULL;
	c->texture.east = NULL;
	c->texture.west = NULL;
}

void	free_2d_string(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	clean_exit(t_cub3d *c)
{
	if (c->img)
		mlx_delete_image(c->mlx, c->img);
	if (c->mlx)
		mlx_terminate(c->mlx);
	free_2d_string(c->test_map);
	clean_textures(c);
	exit(EXIT_SUCCESS);
}
