/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:52:04 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/20 11:32:13 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_operations.h"

/**
 * @brief Shift up all elements of stack by 1.
 * The first element becomes the last one
 * (Helper function for ra, rb & rr)
 *
 * @param stack: stack to operate on
 */
static void	ps_rotate(t_stack *stack)
{
	t_double_list	*tmp;

	if (stack == NULL || stack->size <= 1)
		return ;
	tmp = stack->stack_ptr;
	stack->stack_ptr = stack->stack_ptr->next;
	stack->base_ptr->next = tmp;
	tmp->next = NULL;
	tmp->prev = stack->base_ptr;
	stack->base_ptr = stack->base_ptr->next;
	stack->base_ptr->next = NULL;
	stack->stack_ptr->prev = NULL;
}

/**
 * @brief Rotate A.
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 *
 * @param stack_a: stack a to operate on
 */
void	ra(t_stack *stack_a)
{
	ps_rotate(stack_a);
}

/**
 * @brief Rotate B.
 * Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 *
 * @param stack_b: stack b to operate on
 */
void	rb(t_stack *stack_b)
{
	ps_rotate(stack_b);
}

/**
 * @brief Shorthand for ra & rb at the same time
 *
 * @param stack_a: stack a to operate on
 * @param stack_b: stack b to operate on
 */
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
