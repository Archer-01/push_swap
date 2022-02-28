/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five_nums.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:32:06 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/28 14:35:20 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* @brief push_swap sorting algorithm when stack A initially has only five
* numbers
*
* @param stack_a: stack A
* @param stack_b: stack B
* @return t_bool: TRUE if sort is successful, FALSE otherwise
*/
t_bool	ft_sort_five_nums(t_stack *stack_a, t_stack *stack_b)
{
	ft_place_smallest_first(stack_a, stack_b);
	ft_run(&pb, stack_a, stack_b);
	ft_place_smallest_first(stack_a, stack_b);
	ft_run(&pb, stack_a, stack_b);
	if (ft_sort_three_nums(stack_a, stack_b) == FALSE)
		return (FALSE);
	ft_run(&pa, stack_a, stack_b);
	ft_run(&pa, stack_a, stack_b);
	return (TRUE);
}
