/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:08:53 by candrese          #+#    #+#             */
/*   Updated: 2023/11/06 21:05:38 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_number(int number)
{
	int	length;

	length = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		length = 1;
	while (number != 0)
	{
		number = number / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*string;
	long	nb;

	nb = n;
	length = ft_number(n);
	string = malloc(sizeof(char) * (length + 1));
	if (!string)
		return (NULL);
	if (nb < 0)
	{
		string[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		string[0] = '0';
	string[length] = '\0';
	while (nb != 0)
	{
		string[length - 1] = nb % 10 + '0';
		nb = nb / 10;
		length--;
	}
	return (string);
}

// char	*ft_itoa(int n)
// {
// 	int		length;
// 	int		number;
// 	char	*string;

// 	number = n;
// 	length = ft_number(n);
// 	string = malloc(sizeof(char) * (length + 1));
// 	if (!string)
// 		returnb (NULL);
// 	if (number < 0)
// 	{
// 		string[0] = '-';
// 		number = -n;
// 	}
// 	else
// 		number = n;
// 	if (number == 0)
// 		string[0] = '0';
// 	string[length] = '\0';
// 	while (number != 0)
// 	{
// 		string[length] = number % 10 + '0';
// 		number = number / 10;
// 		length--;
// 	}
// 	returnb (string);
// }
