/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:19:49 by candrese          #+#    #+#             */
/*   Updated: 2025/04/11 19:12:39 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "includes/MLX42/include/MLX42/MLX42.h"
# include "includes/eugenelibft/libft.h"

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef WIDTH
#  define WIDTH 1000
# endif

typedef struct s_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	char			*no_texture_path;
	char			*so_texture_path;
	char			*we_texture_path;
	char			*ea_texture_path;
	uint32_t		*n_pixels;
	uint32_t		*s_pixels;
	uint32_t		*e_pixels;
	uint32_t		*w_pixels;
	uint32_t		f;
	uint32_t		c;
	int				tex_width;
	int				tex_height;
}	t_texture;


typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	char	spawn_dir;

	// direction vextor
	double	dir_x;
	double	dir_y;

	// camera plane
	double	plane_x;
	double	plane_y;
	double	speed;
	double	r_speed;
}	t_player;


typedef struct s_ray
{
	// ray direction
	double	dir_x;
	double	dir_y;
	
	// current map coordinate
	int		map_x;
	int		map_y;

	// for general direction 1/-1
	int		step_x;
	int		step_y;
	
	// distance to next grid
	double	side_dist_x;
	double	side_dist_y;
	
	// deltas
	double	delta_dist_x;
	double	delta_dist_y;
	
	// for wall hit
	int		side; // example (0 = x, 1 = y)
	double	wall_dist;

	// walls
	int		line_height;  // hight of wall line
	int		draw_start;   // y start coordinate
	int		draw_end;     // y end coordinate
}	t_ray;

typedef struct s_cub3d
{
	mlx_t			*mlx;
	mlx_image_t		*img;

	// map
	char			**test_map;
	int				map_height;
	int				map_width;
	
	// general
	int				line_pos;
	int				direction;
	int				line_length;
	
	t_player		player;
	t_ray			ray;
	t_texture		texture;
}	t_cub3d;

void	main_loop(void *param);

// cleanup
void	clean_exit(t_cub3d *c);
void	clean_textures(t_cub3d *c);

// key input
void	key_input(t_cub3d *c);

// digital differential algorithm and calculations
void	perform_dda(t_cub3d *c, double ray_dir_x, double ray_dir_y);
void	calculate_wall_height(t_cub3d *c);
void	calculate_ray_direction(t_cub3d *c, int x, double *ray_dir_x, double *ray_dir_y);

// textures and vertical drawing
void	load_textures(t_cub3d *c);
void	draw_textured_column(t_cub3d *c, int x);
void	draw_vertical_line(t_cub3d *c, int x, mlx_texture_t *texture, int tex_x);
void	draw_3d_rays(t_cub3d *c);

// for building, might use if we implement minimap bonus
char	**test_map(void);
void	draw_rays(t_cub3d *c, int square_size);
void	draw_minimap(t_cub3d *c);
void	draw_line(t_cub3d *c, int x1, int y1, int x2, int y2, uint32_t color);
void	draw_rectangle(t_cub3d *c, int x, int y, int width, int height, uint32_t color);

#endif
