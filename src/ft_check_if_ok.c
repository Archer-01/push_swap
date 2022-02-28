/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_ok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 08:54:46 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/28 08:57:30 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * @brief Check if stack A is sorted and stack B is empty, print OK if so or
 * print KO otherwise
 *
 * @param stack_a: stack A
 * @param stack_b: stack B
 * @return t_bool: TRUE if stack A is sorted and stack B is empty, FALSE
 * otherwise
 */
t_bool	ft_check_if_ok(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return (FALSE);
	else if (ft_stack_is_sorted(stack_a) && stack_b->size == 0)
	{
		ft_putendl_fd("OK", STDOUT_FILENO);
		return (TRUE);
	}
	else
	{
		ft_putendl_fd("KO", STDOUT_FILENO);
		return (FALSE);
	}
}
