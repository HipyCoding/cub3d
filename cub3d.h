/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:19:49 by candrese          #+#    #+#             */
/*   Updated: 2025/02/25 02:10:42 by candrese         ###   ########.fr       */
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
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				x;
	int				y;
	int				line_pos;
	int				direction;
	int				line_length;
	int				r;
	int				g;
	int				b;
}	t_cub3d;

typedef struct s_pov
{
	int		x;
	int		y;

}	t_pov;

void	clean_exit(t_cub3d *c);

void	key_input(t_cub3d *c);

void	main_loop(void *param);

void	put_cub3d(t_cub3d *c);
void	draw_line(t_cub3d *c, int x1, int y1, int x2, int y2, uint32_t color);

#endif
