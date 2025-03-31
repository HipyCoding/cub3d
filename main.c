/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:19:46 by candrese          #+#    #+#             */
/*   Updated: 2025/03/31 17:48:32 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"
#include "./parsing/parse.h"


// // only to build execution, i will delete later
// char **test_map(void)
// {
// 	char **map;

// 	map = malloc(sizeof(char *) * 7);
// 	if (!map)
// 		return (NULL);
// 	map[0] = ft_strdup("111111");
// 	map[1] = ft_strdup("100001");
// 	map[2] = ft_strdup("101001");
// 	map[3] = ft_strdup("100001");
// 	map[4] = ft_strdup("100001");
// 	map[5] = ft_strdup("111111");
// 	map[6] = NULL;
// 	return (map);
// }


// void	init_player(t_player *player)
// {
// 	player->pos_x = 2.0;
// 	player->pos_y = 3.5;
// 	player->dir_x = 1.0;
// 	player->dir_y = 0.0;

// 	// for fov
// 	player->plane_x = 0.0;
// 	player->plane_y = 0.66;
	
// 	player->speed = 0.01;
// }

// void	init_map(t_cub3d *c)
// {
// 	int	i;
	
// 	c->test_map = test_map();
// 	if (!c->test_map)
// 		exit(EXIT_FAILURE);
// 	c->map_height = 0;
// 	while (c->test_map[c->map_height])
// 		c->map_height++;
// 	c->map_width = 0;
// 	i = 0;
// 	while (i < c->map_height)
// 	{
// 		int row_len = ft_strlen(c->test_map[i]);
// 		if (row_len > c->map_width)
// 			c->map_width = row_len;
// 		i++;
// 	}
// }


// void	init_to_winit(t_cub3d *c)
// {
// 	c->line_pos = 100;
// 	c->direction = 1;
// 	c->line_length = 200;
// 	init_player(&c->player);
// 	c->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
// 	c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
// 	init_map(c);
// 	if (!c->mlx || !c->img || !c->test_map)
// 		exit(EXIT_FAILURE);
// }


// void leaks()
// {
// 	system("leaks cub3d");
// }

int	main(int argc, char **argv)
{
	// t_cub3d	c;
	char	**map;

	// atexit(leaks);
	map = parse(argc, argv);
	if (!map)
		return (EXIT_FAILURE);
	// init_to_winit(&c);
	// mlx_key_hook(c.mlx, &key_hook, &c);
	// ptrototype: mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param)
	// mlx_loop_hook(c.mlx, &main_loop, &c);
	// mlx_loop(c.mlx);
	// Clean up
	// mlx_terminate(c.mlx);
	return (write(1, "gut\n", 4), EXIT_SUCCESS);
}
