/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:12:16 by jidrizi           #+#    #+#             */
/*   Updated: 2025/03/31 00:30:58 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_and_flag(char **copy, int x, int y, int return_value)
{
	if (copy[y] && copy[y][x] && copy[y][x] == '0')
	{
		copy[y][x] = '1';
		return (EXIT_SUCCESS);
	}
	else if (copy[y] && copy[y][x] && copy[y][x] == '1')
		return (1);
	else
		return_value = EXIT_FAILURE;
	return (EXIT_FAILURE);
}