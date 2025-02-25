/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:19:46 by candrese          #+#    #+#             */
/*   Updated: 2025/02/25 02:08:15 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int args(int ac, char **av, t_cub3d	*c)
// {
// 	// here we will check for arguments
// 	return 0;
// }

void	init_to_winit(t_cub3d *c)
{
	c->x = 0;
	c->y = 0;
	c->line_pos = 100;
	c->direction = 1;
	c->line_length = 200;   
	c->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	if (!c->mlx || !c->img)
		exit(EXIT_FAILURE);
}

int	main()
{
	t_cub3d	c;

	// if (args(ac, argv, &c))
	// {
	// 	return (EXIT_FAILURE);
	// }
	init_to_winit(&c);
	// mlx_key_hook(c.mlx, &key_hook, &c);
	// ptrototype: mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param)
	mlx_loop_hook(c.mlx, &main_loop, &c);
	mlx_loop(c.mlx);
	// Clean up
	mlx_terminate(c.mlx);
	return (EXIT_SUCCESS);
}
