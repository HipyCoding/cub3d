/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 02:06:43 by candrese          #+#    #+#             */
/*   Updated: 2025/02/25 07:25:40 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	main_loop(void *param)
{
	t_cub3d	*c;

	c = (t_cub3d *)param;
	key_input(c);
	draw_minimap(c);
	//put_cub3d(c);
}
