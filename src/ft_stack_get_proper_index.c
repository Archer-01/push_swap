/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_get_proper_index.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:21:31 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/24 13:01:54 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/**
 * @brief Check if number is between current and next node of double linked list
 *
 * @param ptr: double linked list node to operate on
 * @param num: number to check
 * @return t_bool: TRUE if number is between current and next node, FALSE
 * otherwise
 */
static t_bool	ft_is_between_curr_and_next(t_double_list *ptr, int num)
{
	int	current;
	int	next;

	if (ptr == NULL)
		return (FALSE);
	current = *((int *) ptr->content);
	next = *((int *) ptr->next->content);
	return (current < num && num < next);
}

/**
 * @brief Check if number is between previous and current node of double linked
 * list
 *
 * @param ptr: double linked list node to operate on
 * @param num: number to check
 * @return t_bool: TRUE if number is between current and previous node, FALSE
 * otherwise
 */
static t_bool	ft_is_between_prev_and_curr(t_double_list *ptr, int num)
{
	int	previous;
	int	current;

	if (ptr == NULL)
		return (FALSE);
	previous = *((int *) ptr->prev->content);
	current = *((int *) ptr->content);
	return (previous < num && num < current);
}

/**
 * @brief Check if number is between last and first frame of stack
 *
 * @param stack:stack to operate on
 * @param num: number to check
 * @return t_bool: TRUE if number is between last and first frame of stack,
 * FALSE otherwise
 */
static t_bool	ft_is_between_last_and_first(t_stack *stack, int num)
{
	int	first;
	int	last;

	if (stack == NULL)
		return (FALSE);
	first = *((int *) stack->stack_ptr->content);
	last = *((int *) stack->base_ptr->content);
	return (last < num && num < first);
}

/**
 * @brief Get index of max value in stack
 *
 * @param stack: stack to operate on
 * @return int: index of max value, -1 on failure
 */
static int	ft_get_indexof_max_value(t_stack *stack)
{
	int				max_value;
	int				max_index;
	int				curr_value;
	int				i;
	t_double_list	*iter;

	if (stack == NULL || stack->size == 0)
		return (-1);
	iter = stack->stack_ptr;
	max_index = 0;
	max_value = *((int *) iter->content);
	iter = iter->next;
	i = 1;
	while (iter != NULL)
	{
		curr_value = *((int *) iter->content);
		if (curr_value > max_value)
		{
			max_value = curr_value;
			max_index = i;
		}
		++i;
		iter = iter->next;
	}
	return (max_index);
}

/**
 * @brief Get proper index of number in stack so that stack remains circularly
 * sorted.
 * Please note that this function does not add num to the stack but it gives
 * the proper index as if the number was truly added to stack
 *
 * @param stack: stack to operate on
 * @param num: number for which to get the index
 * @return int: appropriate index, -1 otherwise
 */
int	ft_stack_get_proper_index(t_stack *stack, int num)
{
	t_double_list	*top;
	t_double_list	*bottom;
	int				i;
	int				j;

	if (stack == NULL || stack->size == 0)
		return (-1);
	if (ft_is_between_last_and_first(stack, num))
		return (0);
	top = stack->stack_ptr;
	bottom = stack->base_ptr;
	i = 0;
	j = stack->size - 1;
	while (i < j)
	{
		if (ft_is_between_curr_and_next(top, num))
			return (i + 1);
		else if (ft_is_between_prev_and_curr(bottom, num))
			return (j);
		top = top->next;
		bottom = bottom->prev;
		++i;
		--j;
	}
	return (ft_get_indexof_max_value(stack) + 1);
}
