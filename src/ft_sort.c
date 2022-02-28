/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:47:51 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/28 13:37:57 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sort stack A
 *
 * @param stack_a: Stack A
 * @param stack_b: Stack B
 * @return t_bool: TRUE if stack A gets sorted, FALSE otherwise
 */
t_bool	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	*lis;
	int	lis_length;

	if (ft_stack_is_sorted(stack_a))
		return (TRUE);
	else if (stack_a->size == 3)
		return (ft_sort_three_nums(stack_a, stack_b));
	else if (stack_a->size == 5)
		return (ft_sort_five_nums(stack_a, stack_b));
	lis = ft_longest_increasing_subsequence(stack_a, &lis_length);
	if (lis == NULL)
	{
		ft_stack_clear(&stack_a);
		ft_stack_clear(&stack_b);
		return (FALSE);
	}
	ft_push_to_stack_b(stack_a, stack_b, lis, lis_length);
	ft_push_to_stack_a(stack_a, stack_b);
	ft_rotate_stack_a(stack_a, stack_b);
	free(lis);
	return (TRUE);
}
