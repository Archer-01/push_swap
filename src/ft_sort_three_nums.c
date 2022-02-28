/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_nums.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:54:38 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/28 13:23:54 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Place smallest number on top of stack A
 *
 * @param stack_a: stack A
 * @param stack_b: stack B
 */
static void	ft_place_smallest_first(t_stack *stack_a, t_stack *stack_b)
{
	int			smallest_num_index;
	t_operation	ft_rotate;

	smallest_num_index = ft_stack_get_smallest_num_index(stack_a);
	if (smallest_num_index == 0)
		return ;
	else if ((size_t) smallest_num_index <= stack_a->size / 2)
		ft_rotate = &ra;
	else
		ft_rotate = &rra;
	ft_run(ft_rotate, stack_a, stack_b);
}

/**
 * @brief push_swap sorting algorithm when stack A initially has only three
 * numbers
 *
 * @param stack_a: stack A
 * @param stack_b: stack B
 * @return t_bool: TRUE if sort is successful, FALSE otherwise
 */
t_bool	ft_sort_three_nums(t_stack *stack_a, t_stack *stack_b)
{
	int			second_num;
	int			third_num;

	if (stack_a == NULL || stack_b == NULL)
		return (FALSE);
	ft_place_smallest_first(stack_a, stack_b);
	second_num = *((int *) stack_a->stack_ptr->next->content);
	third_num = *((int *) stack_a->base_ptr->content);
	if (second_num > third_num)
		ft_run(&sa, stack_a, stack_b);
	ft_place_smallest_first(stack_a, stack_b);
	return (TRUE);
}
