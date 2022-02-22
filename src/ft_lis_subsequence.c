/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_subsequence.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:39:00 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/22 11:07:30 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Get index of max value in integer array.
 *
 * @param arr: integer array to operate on
 * @param len: integer array length
 * @return int: index of max value, -1 otherwise
 */
int	ft_max_index(int *arr, size_t len)
{
	size_t	i;
	int		max_index;

	if (len == 0)
		return (-1);
	max_index = 0;
	i = 1;
	while (i < len)
	{
		if (arr[i] >= arr[max_index])
			max_index = i;
		++i;
	}
	return (max_index);
}

/**
 * @brief Get index of max value in integer array that does not surpass the old
 * max value (which is arr[len])
 * (Helper function for ft_fill_subsequence)
 *
 * @param arr: integer array to operate on
 * @param len: integer array length
 * @return int: aprorpriate index, -1 otherwise
 */
static int	ft_get_next_max_index(int *arr, int len)
{
	int	i;
	int	max_index;

	if (arr == NULL || len == 0)
		return (-1);
	max_index = 0;
	i = 1;
	while (i < len)
	{
		if (arr[i] >= arr[max_index] && arr[i] < arr[len])
			max_index = i;
		++i;
	}
	return (max_index);
}

/**
 * @brief Fill LIS (Longest Increasing Subsequence) subsequence with appropriate
 * values based on stack
 * (Helper function fot ft_get_lis_subsequence)
 *
 * @param tmp: stack to operate on
 * @param lengths: LIS lengths array
 * @param subsequence: LIS subsequence array to fill
 * @return int*: filled LIS subsequence array, NULL on failure
 */
static void	ft_fill_subsequence(t_stack *tmp, int *lengths, int *subsequence)
{
	t_double_list	*stack_iter;
	int				lengths_iter;
	int				subsequence_iter;
	int				max_index;

	if (tmp == NULL || tmp->size == 0 || lengths == NULL || subsequence == NULL)
		return ;
	max_index = ft_max_index(lengths, tmp->size);
	lengths_iter = max_index;
	subsequence_iter = lengths[max_index] - 1;
	while (subsequence_iter >= 0)
	{
		stack_iter = ft_stack_get_frame_by_index(tmp, lengths_iter);
		subsequence[subsequence_iter] = *((int *) stack_iter->content);
		lengths_iter = ft_get_next_max_index(lengths, lengths_iter);
		--subsequence_iter;
	}
}

/**
 * @brief Get LIS (Longest Increasing Subsequence) subsequence from stack.
 *
 * @param tmp: stack to operate on
 * @param lengths: LIS lengths array
 * @return int*: newly created LIS subsequence
 */
int	*ft_get_lis_subsequence(t_stack *tmp, int *lengths)
{
	int	*subsequence;
	int	max_index;
	int	subsequence_length;

	if (tmp == NULL || tmp->size == 0 || lengths == NULL)
		return (NULL);
	max_index = ft_max_index(lengths, tmp->size);
	if (max_index == -1)
		return (NULL);
	subsequence_length = lengths[max_index];
	subsequence = (int *) ft_calloc(subsequence_length, sizeof(int));
	if (subsequence == NULL)
		return (NULL);
	ft_fill_subsequence(tmp, lengths, subsequence);
	return (subsequence);
}
