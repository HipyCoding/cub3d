/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:19:46 by candrese          #+#    #+#             */
/*   Updated: 2025/04/01 17:43:30 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parsing/parse.h"

// int args(int ac, char **av, t_cub3d	*c)
// {
// 	// here we will check for arguments
// 	return 0;
// }


// only to build execution, i will delete later
// char **test_map(void)
// {
// 	char **map;

// 	map = malloc(sizeof(char *) * 9);
// 	if (!map)
// 		return (NULL);
// 	map[0] = ft_strdup("11111111");
// 	map[1] = ft_strdup("10000001");
// 	map[2] = ft_strdup("10001001");
// 	map[3] = ft_strdup("10001001");
// 	map[4] = ft_strdup("11000001");
// 	map[5] = ft_strdup("11111111");
// 	map[6] = NULL;
// 	return (map);
// }

void	init_player_direction(t_player *player)
{
	if (player->spawn_dir == 'N')
	{
		player->dir_y = -1.0;
		player->plane_x = 0.66;
	}
	else if (player->spawn_dir == 'S')
	{
		player->dir_y = 1.0;
		player->plane_x = -0.66;
	}
	else if (player->spawn_dir == 'E')
	{
		player->dir_x = 1.0;
		player->plane_y = 0.66;
	}
	else if (player->spawn_dir == 'W')
	{
		player->dir_x = -1.0;
		player->plane_y = -0.66;
	}
}

void	init_player(t_player *player)
{
	player->dir_x = 0.0;
	player->dir_y = 0.0;

	// for fov
	player->plane_x =  0.0;
	player->plane_y = 0.0;
	
	player->speed = 0.03;
	player->r_speed = 0.05;
	init_player_direction(player);
	
}

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

void	init_map(t_cub3d *c)
{
	int	i;

	c->map_height = 0;
	while (c->test_map[c->map_height])
		c->map_height++;
	c->map_width = 0;
	i = 0;
	while (i < c->map_height)
	{
		int row_len = ft_strlen(c->test_map[i]);
		if (row_len > c->map_width)
			c->map_width = row_len;
		i++;
	}
}

void	init_to_winit(t_cub3d *c)
{
	c->line_pos = 100;
	c->direction = 1;
	c->line_length = 200;
	c->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	c->map_height = 0;
	if (!c->mlx || !c->img || !c->test_map)
		exit(EXIT_FAILURE);
	init_player(&c->player);
	init_map(c);
	load_textures(c);
}

void print_texture_info(t_texture *texture)
{
    // Print floor color if available
    if (texture->f)
        printf("Floor color (RGBA): 0x%08X\n", texture->f);
    else
        printf("Floor color: Not set\n");
        
    // Print ceiling color if available
    if (texture->c)
        printf("Ceiling color (RGBA): 0x%08X\n", texture->c);
    else
        printf("Ceiling color: Not set\n");
    
    // Print the RGB components of the floor color
    if (texture->f)
    {
        uint32_t color = texture->f;
        int r = (color >> 24) & 0xFF;
        int g = (color >> 16) & 0xFF;
        int b = (color >> 8) & 0xFF;
        int a = color & 0xFF;
        printf("Floor RGB: (%d, %d, %d, %d)\n", r, g, b, a);
    }
    
    // Print the RGB components of the ceiling color
    if (texture->c)
    {
        uint32_t color = texture->c;
        int r = (color >> 24) & 0xFF;
        int g = (color >> 16) & 0xFF;
        int b = (color >> 8) & 0xFF;
        int a = color & 0xFF;
        printf("Ceiling RGB: (%d, %d, %d, %d)\n", r, g, b, a);
    }
    
    // Print texture paths
    printf("North texture path: %s\n", 
           texture->no_texture_path ? texture->no_texture_path : "Not set");
    printf("South texture path: %s\n", 
           texture->so_texture_path ? texture->so_texture_path : "Not set");
    printf("West texture path: %s\n", 
           texture->we_texture_path ? texture->we_texture_path : "Not set");
    printf("East texture path: %s\n", 
           texture->ea_texture_path ? texture->ea_texture_path : "Not set");
}

int	main(int argc, char **argv)
{
	t_cub3d	c;

	//   t_cub3d	c;
// 	char	**map;

// 	// atexit(leaks);
	c.test_map = parse(argc, argv, &c);
	init_to_winit(&c);
	print_texture_info(&c.texture);
	mlx_loop_hook(c.mlx, &main_loop, &c);
	mlx_loop(c.mlx);
	// Clean up
	clean_exit(&c);
	return (EXIT_SUCCESS);
}


// // // only to build execution, i will delete later
// // char **test_map(void)
// // {
// // 	char **map;

// void	init_player(t_player *player)
// {
// 	player->pos_x = 2.0;
// 	player->pos_y = 3.5;
// 	player->dir_x = 0.0;
// 	player->dir_y = -1.0;

// 	// for fov
// 	player->plane_x = 0.66;
// 	player->plane_y = 0.0;
	
// 	player->speed = 0.03;
// 	player->r_speed = 0.05;
// }

// // void	init_map(t_cub3d *c)
// // {
// // 	int	i;
	
// // 	c->test_map = test_map();
// // 	if (!c->test_map)
// // 		exit(EXIT_FAILURE);
// // 	c->map_height = 0;
// // 	while (c->test_map[c->map_height])
// // 		c->map_height++;
// // 	c->map_width = 0;
// // 	i = 0;
// // 	while (i < c->map_height)
// // 	{
// // 		int row_len = ft_strlen(c->test_map[i]);
// // 		if (row_len > c->map_width)
// // 			c->map_width = row_len;
// // 		i++;
// // 	}
// // }

// void	init_to_winit(t_cub3d *c)
// {
// 	c->line_pos = 100;
// 	c->direction = 1;
// 	c->line_length = 200;
// 	init_player(&c->player);
// 	c->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
// 	c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
// 	//init_map(c);
// 	if (!c->mlx || !c->img || !c->test_map)
// 		exit(EXIT_FAILURE);
// 	load_textures(c);
// }

// int	main(int argc, char **argv)
// {
//   t_cub3d	c;
// 	char	**map;

// 	// atexit(leaks);
// 	map = parse(argc, argv);
// 	if (!map)
// 		return (EXIT_FAILURE);
// 	init_to_winit(&c);
// 	mlx_loop_hook(c.mlx, &main_loop, &c);
// 	mlx_loop(c.mlx);
// 	// Clean up
// 	clean_exit(&c);
// 	return (EXIT_SUCCESS);
// }
