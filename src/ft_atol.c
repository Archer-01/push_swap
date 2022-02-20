/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:18:32 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/20 14:53:15 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

/**
 * @brief Convert string to long
 *
 * @param str: string to operate on
 * @return long: converted long
 */
long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		i;

	sign = 1;
	num = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while (str[i] != '\0')
	{
		num = (num * 10) + (str[i] - '0');
		++i;
	}
	return (sign * num);
}
