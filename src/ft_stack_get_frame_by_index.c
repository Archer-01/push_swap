/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_get_frame_by_index.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 07:57:09 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/22 08:00:46 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/**
 * @brief Get stack frame by index
 *
 * @param stack: stack to operate on
 * @param index: frame index to retrieve
 * @return t_double_list*: frame with appropriate index, NULL otherwise
 */
t_double_list	*ft_stack_get_frame_by_index(t_stack *stack, int index)
{
	int				i;
	t_double_list	*iter;

	if (index < 0 || stack == NULL || stack->size == 0)
		return (NULL);
	iter = stack->stack_ptr;
	i = 0;
	while (i < index && iter != NULL)
	{
		iter = iter->next;
		++i;
	}
	if (iter == NULL)
		return (NULL);
	return (iter);
}
