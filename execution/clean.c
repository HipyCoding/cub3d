/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:57:33 by candrese          #+#    #+#             */
/*   Updated: 2025/03/08 01:29:54 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	exit(EXIT_SUCCESS);
}

