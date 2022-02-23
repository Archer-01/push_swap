/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_is_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:30:37 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/23 11:34:28 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/**
 * @brief Check if stack is sorted in ascending order
 *
 * @param stack: stack to operate on
 * @return t_bool: TRUE on NULL, empty or sorted stack, FALSE otherwise
 */
t_bool	ft_stack_is_sorted(t_stack *stack)
{
	t_double_list	*iter;
	int				curr_num;
	int				prev_num;

	if (stack == NULL || stack->size == 0)
		return (TRUE);
	iter = stack->stack_ptr;
	prev_num = *((int *) iter->content);
	iter = iter->next;
	while (iter != NULL)
	{
		curr_num = *((int *) iter->content);
		if (curr_num > prev_num)
			return (FALSE);
		prev_num = curr_num;
		iter = iter->next;
	}
	return (TRUE);
}
