/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 09:13:37 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/20 11:57:43 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/**
 * @brief Pop integer from stack
 *
 * @param stack: stack to operate on
 * @return int: popped integer
 */
int	ft_stack_pop(t_stack *stack)
{
	int				popped_num;
	t_double_list	*popped_frame;

	popped_frame = stack->stack_ptr;
	popped_num = *((int *) popped_frame->content);
	stack->stack_ptr = stack->stack_ptr->next;
	ft_doublelst_delone(popped_frame, &free);
	if (stack->stack_ptr != NULL)
		stack->stack_ptr->prev = NULL;
	else
		stack->base_ptr = NULL;
	--(stack->size);
	return (popped_num);
}
