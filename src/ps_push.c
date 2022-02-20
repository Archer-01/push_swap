/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:22:00 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/20 11:32:06 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_operations.h"

/**
 * @brief Take the first element at the top of the 2nd stack and put it at the
 * top of the 1st stack
 * (Do nothing if the 2nd stack is empty)
 * (Helper function for pa & pb)
 *
 * @param first_stack: first stack to operate on
 * @param second_stack: second stack to operate on
 */
static void	ps_push(t_stack **first_stack, t_stack **second_stack)
{
	int	popped_num;

	if (first_stack == NULL || second_stack == NULL)
		return ;
	if (*second_stack == NULL || (*second_stack)->size == 0)
		return ;
	popped_num = ft_stack_pop(*second_stack);
	ft_stack_push(first_stack, popped_num);
}

/**
 * @brief Push A.
 * Take the first element at the top of stack b and put it at
 * the top of stack a
 * (Do nothing if stack b is empty)
 *
 * @param stack_a: stack a to operate on
 * @param stack_b: stack b to operate on
 */
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	ps_push(stack_a, stack_b);
}

/**
 * @brief Push B.
 * Take the first element at the top of stack a and put it at
 * the top of stack b
 * (Do nothing if stack a is empty)
 *
 * @param stack_a: stack a to operate on
 * @param stack_b: stack b to operate on
 */
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	ps_push(stack_b, stack_a);
}
