/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:19:46 by candrese          #+#    #+#             */
/*   Updated: 2025/02/25 09:53:04 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int args(int ac, char **av, t_cub3d	*c)
// {
// 	// here we will check for arguments
// 	return 0;
// }


// only to build execution, i will delete later
char **test_map(void)
{
	char **map;

	map = malloc(sizeof(char *) * 7);
	if (!map)
		return (NULL);
	map[0] = ft_strdup("111111");
	map[1] = ft_strdup("100001");
	map[2] = ft_strdup("101001");
	map[3] = ft_strdup("100001");
	map[4] = ft_strdup("100001");
	map[5] = ft_strdup("111111");
	map[6] = NULL;
	return (map);
}


void	init_to_winit(t_cub3d *c)
{
	// basic variables
	c->x = 0;
	c->y = 0;
	c->line_pos = 100;
	c->direction = 1;
	c->line_length = 200;

	// player variables
	c->pos_x = 2.0;
	c->pos_y = 3.5;
	c->dir_x = 1.0;
	c->dir_y = 0.0;
	c->plane_x = 0.0;
	c->plane_y = 0.66;

	c->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	c->test_map = test_map();
	if (!c->mlx || !c->img || !c->test_map)
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
