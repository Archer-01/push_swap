/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_get_index_by_value.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:43:28 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/23 07:33:43 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/**
 * @brief Get stack frame index of frame with appropriate value
 *
 * @param stack: stack to operate on
 * @param value: value for wich to retrieve the index
 * @return int: appropriate index, -1 otherwise
 */
int	ft_stack_get_index_by_value(t_stack *stack, int value)
{
	t_double_list	*iter;
	int				i;
	int				curr_value;

	if (stack == NULL || stack->size == 0)
		return (-1);
	i = 0;
	iter = stack->stack_ptr;
	while (iter != NULL)
	{
		curr_value = *((int *) iter->content);
		if (curr_value == value)
			return (i);
		++i;
		iter = iter->next;
	}
	return (-1);
}
