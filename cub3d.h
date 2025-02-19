/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:19:49 by candrese          #+#    #+#             */
/*   Updated: 2025/02/19 13:41:40 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef WIDTH
#  define WIDTH 1000
# endif

typedef struct s_cub3d
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				x;
	int				y;
	int				r;
	int				g;
	int				b;
}	t_cub3d;

void put_cub3d(t_cub3d *c);

#endif
