/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:19:49 by candrese          #+#    #+#             */
/*   Updated: 2025/02/25 09:59:04 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include "includes/MLX42/include/MLX42/MLX42.h"
# include "includes/libft/libft.h"

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef WIDTH
#  define WIDTH 1000
# endif

# define RED 0xFF0000FF

typedef struct s_cub3d
{
	// mlx
	mlx_t			*mlx;
	mlx_image_t		*img;

	// general
	int				x;
	int				y;
	int				line_pos;
	int				direction;
	int				line_length;
	char			**test_map;
	
	// player position and direction
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}	t_cub3d;

void	clean_exit(t_cub3d *c);

void	key_input(t_cub3d *c);

void	main_loop(void *param);
void	put_cub3d(t_cub3d *c);
void	draw_line(t_cub3d *c, int x1, int y1, int x2, int y2, uint32_t color);

char	**test_map(void);
void	calculate_ray_direction(t_cub3d *c, int x, double *ray_dir_x, double *ray_dir_y);
void	draw_minimap(t_cub3d *c);
void	draw_rectangle(t_cub3d *c, int x, int y, int width, int height, uint32_t color);

#endif
