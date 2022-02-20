/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:06:40 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/20 11:31:57 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_operations.h"

/**
 * @brief Swap two integers
 * (Helper function for ps_swap)
 *
 * @param a: pointer on first integer
 * @param b: pointer on second integer
 */
static void	ft_int_swap(int *a, int *b)
{
	int	c;

	if (a == NULL || b == NULL)
		return ;
	c = *a;
	*a = *b;
	*b = c;
}

/**
 * @brief Swap the first two elements at the top of the stack
 * (Do nothing if there is only one or no elements in the stack)
 * (Helper function for sa, sb & ss)
 *
 * @param stack: stack to operate on
 */
static void	ps_swap(t_stack *stack)
{
	t_double_list	*tmp;

	if (stack == NULL || stack->size <= 1)
		return ;
	tmp = stack->stack_ptr->next;
	ft_int_swap(stack->stack_ptr->content, tmp->content);
}

/**
 * @brief Swap A.
 * Swap the first two elements at the top of stack a
 * (Do nothing if there is only one or no elements in the stack)
 *
 * @param stack_a: stack a to operate on
 */
void	sa(t_stack *stack_a)
{
	ps_swap(stack_a);
}

/**
 * @brief Swap B.
 * Swap the first two elements at the top of stack b
 * (Do nothing if there is only one or no elements in the stack)
 *
 * @param stack_b: stack b to operate on
 */
void	sb(t_stack *stack_b)
{
	ps_swap(stack_b);
}

/**
 * @brief Shorthand for sa & sb at the same time
 *
 * @param stack_a:stack a to operate on
 * @param stack_b: stack b to operate on
 */
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
