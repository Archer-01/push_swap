/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:48:27 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/22 11:52:28 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Get LIS (Longest Increasing Subsequence) from stack. Also save LIS
 * length in lis_length parameter.
 *
 * @param stack_a: stack A to operate on
 * @param lis_length: integer pointer to save LIS length in
 * @return int*: LIS subsequence, NULL on failure
 */
int	*ft_longest_increasing_subsequence(t_stack *stack_a, int *lis_length)
{
	int		*lengths;
	int		*subsequence;
	t_stack	*tmp;

	if (stack_a == NULL || stack_a->size == 0 || lis_length == NULL)
		return (NULL);
	tmp = ft_place_smallest_num_first(stack_a);
	if (tmp == NULL)
		return (NULL);
	lengths = ft_get_lis_lengths(tmp);
	if (lengths == NULL)
	{
		ft_stack_clear(&tmp);
		return (NULL);
	}
	*lis_length = lengths[ft_max_index(lengths, tmp->size)];
	subsequence = ft_get_lis_subsequence(tmp, lengths);
	if (subsequence == NULL)
	{
		free(lengths);
		ft_stack_clear(&tmp);
		return (NULL);
	}
	ft_stack_clear(&tmp);
	return (free(lengths), subsequence);
}
