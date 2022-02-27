/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_get_smallest_num_index.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:20:52 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/27 12:22:05 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/**
 * @brief Get smallest number index on stack
 *
 * @param stack: stack a to operate on
 * @return int: smallest number index, -1 on NULL or empty stack
 */
int	ft_stack_get_smallest_num_index(t_stack *stack)
{
	int				smallest_index;
	int				smallest_num;
	int				current_num;
	int				i;
	t_double_list	*iter;

	if (stack == NULL || stack->size == 0)
		return (-1);
	iter = stack->stack_ptr;
	smallest_index = 0;
	smallest_num = *((int *) iter->content);
	i = 1;
	iter = iter->next;
	while (iter != NULL)
	{
		current_num = *((int *) iter->content);
		if (current_num < smallest_num)
		{
			smallest_num = current_num;
			smallest_index = i;
		}
		++i;
		iter = iter->next;
	}
	return (smallest_index);
}
