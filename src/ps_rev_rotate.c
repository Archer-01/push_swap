/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:19:16 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/27 17:42:09 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_operations.h"

/**
 * @brief Shift down all elements of stack by 1.
 * The last element becomes the first one.
 * (Helper function for rra, rrb, & rrr)
 *
 * @param stack: stack to operate on
 */
static void	ps_rev_rotate(t_stack *stack)
{
	t_double_list	*tmp;

	if (stack == NULL || stack->size <= 1)
		return ;
	tmp = stack->base_ptr->prev;
	tmp->next = NULL;
	stack->base_ptr->prev = NULL;
	stack->base_ptr->next = stack->stack_ptr;
	stack->stack_ptr->prev = stack->base_ptr;
	stack->stack_ptr = stack->base_ptr;
	stack->base_ptr = tmp;
}

/**
 * @brief Reverse Rotate A.
 * Shift down all elements of stack a by one.
 * The last element becomes the first one.
 *
 * @param stack_a: stack a to operate on
 */
void	rra(t_stack *stack_a)
{
	ps_rev_rotate(stack_a);
}

/**
 * @brief Reverse Rotate B.
 * Shift down all elements of stack b by one.
 * The last element becomes the first one.
 *
 * @param stack_b: stack b to operate on
 */
void	rrb(t_stack *stack_b)
{
	ps_rev_rotate(stack_b);
}

/**
 * @brief Shorthand for rra & rrb at the same time
 *
 * @param stack_a: stack a to operate on
 * @param stack_b: stack b to operate on
 */
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
