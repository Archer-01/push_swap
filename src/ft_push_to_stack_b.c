/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:00:30 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/23 09:32:04 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Check if number belongs to LIS subsequence
 *
 * @param num: number to check
 * @param lis: LIS subsequence to operate on
 * @param lis_length: LIS subsequence length
 * @return t_bool: TRUE if number belongs to LIS subsequence, FALSE otherwise
 */
static t_bool	ft_does_belong_to_lis(int num, int *lis, int lis_length)
{
	int	i;

	if (lis == NULL)
	{
		ft_putendl_fd("NULL pointer error", STDERR_FILENO);
		return (FALSE);
	}
	i = 0;
	while (i < lis_length)
	{
		if (lis[i] == num)
			return (TRUE);
		++i;
	}
	return (FALSE);
}

/**
 * @brief Get proper rotate operation based on number's position in the stack.
 *
 * @param stack_a: stack a to operate on
 * @param index: index of number on stack
 * @return t_operation: appropriate operation function (ra/rra), NULL on failure
 */
static t_operation	ft_get_proper_rotate_operation(t_stack *stack_a, int index)
{
	if (stack_a == NULL || stack_a->size == 0)
		return (NULL);
	if ((size_t) index <= stack_a->size / 2)
		return (&ra);
	else
		return (&rra);
}

/**
 * @brief Do proper rotate operation.
 *
 * @param stack_a: stack A
 * @param stack_b: stack B
 * @param ft_rotate: rotation operation
 * @param num: integer meant to be at the top of stack A before performing 'pb'
 * @return t_bool: TRUE on success, FALSE on failure
 */
static t_bool	ft_do_rotate_operation(t_stack *stack_a, t_stack *stack_b,
	t_operation ft_rotate, int num)
{
	int	stack_ptr_value;

	if (stack_a == NULL || stack_a->size == 0 || stack_b == NULL \
		|| ft_rotate == NULL)
		return (FALSE);
	stack_ptr_value = *((int *) stack_a->stack_ptr->content);
	while (stack_ptr_value != num)
	{
		ft_run(ft_rotate, stack_a, stack_b);
		stack_ptr_value = *((int *) stack_a->stack_ptr->content);
	}
	return (TRUE);
}

void	ft_push_to_stack_b(t_stack *stack_a, t_stack *stack_b, int *lis,
	int lis_length)
{
	t_operation		ft_rotate;
	t_double_list	*iter;
	int				curr_num;
	int				index;

	if (stack_a == NULL || stack_a->size == 0 || stack_b == NULL || lis == NULL)
		return ;
	iter = stack_a->stack_ptr;
	while (iter != NULL)
	{
		curr_num = *((int *) iter->content);
		if (ft_does_belong_to_lis(curr_num, lis, lis_length) == TRUE)
		{
			iter = iter->next;
			continue ;
		}
		index = ft_stack_get_index_by_value(stack_a, curr_num);
		if (index > 0)
		{
			ft_rotate = ft_get_proper_rotate_operation(stack_a, index);
			ft_do_rotate_operation(stack_a, stack_b, ft_rotate, curr_num);
		}
		ft_run(&pb, stack_a, stack_b);
		iter = stack_a->stack_ptr;
	}
}
