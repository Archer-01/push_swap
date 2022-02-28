/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_nums.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:54:38 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/28 13:34:54 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
