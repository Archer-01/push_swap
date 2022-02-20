/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 08:59:52 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/20 09:09:57 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/**
 * @brief Create new stack
 *
 * @return t_stack*: newly created stack, NULL on failure
 */
t_stack	*ft_stack_new(void)
{
	t_stack	*stack;

	stack = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
	{
		ft_putendl_fd("Malloc error", STDERR_FILENO);
		return (NULL);
	}
	return (stack);
}
