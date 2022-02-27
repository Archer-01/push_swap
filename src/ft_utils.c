/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 08:50:06 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/27 10:14:07 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

/**
 * @brief Check if a & b have the same sign (positive or negative)
 *
 * @param a: first number to check
 * @param b: second number to check
 * @return t_bool: TRUE on equal sign, FALSE otherwise
 */
t_bool	ft_is_same_sign(int a, int b)
{
	return ((a >= 0 && b >= 0) || (a < 0 && b < 0));
}

/**
 * @brief Calculate absolute value of number
 *
 * @param n: number to operate on
 * @return unsigned int: absolute value of n
 */
unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((unsigned int) n * -1);
	else
		return ((unsigned int) n);
}

/**
 * @brief Get max absolute value of two numbers
 *
 * @param a: first number
 * @param b: second number
 * @return int: max absolute value of two numbers
 */
int	ft_abs_max(int a, int b)
{
	int	a_abs;
	int	b_abs;

	a_abs = ft_abs(a);
	b_abs = ft_abs(b);
	if (a_abs >= b_abs)
		return (a_abs);
	else
		return (b_abs);
}
