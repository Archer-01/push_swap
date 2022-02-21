/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:08:10 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/21 10:13:07 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/**
 * @brief Duplicate stack
 *
 * @param stack: stack to duplicate
 * @return t_stack*: newly duplicated stack, NULL on failure
 */
t_stack	*ft_stack_duplicate(t_stack *stack)
{
	t_stack			*duplicate;
	t_double_list	*iter;
	int				current_num;

	if (stack == NULL)
		return (NULL);
	duplicate = ft_stack_new();
	if (duplicate == NULL)
		return (NULL);
	iter = stack->base_ptr;
	while (iter != NULL)
	{
		current_num = *((int *) iter->content);
		if (ft_stack_push(&duplicate, current_num) == FALSE)
		{
			ft_stack_clear(&duplicate);
			return (NULL);
		}
		iter = iter->prev;
	}
	return (duplicate);
}
