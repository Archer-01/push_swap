/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_lengths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:34:20 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/22 08:35:42 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Set len integers on memory to the given value.
 *
 * @param ptr; integer pointer to operate on
 * @param value: value to be set to each integer
 * @param len: count of integers to be set
 * @return int*: filled integer pointer, NULL otherwise
 */
static int	*ft_int_memset(int *ptr, int value, size_t len)
{
	size_t	i;

	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = value;
		++i;
	}
	return (ptr);
}

/**
 * @brief Fill LIS (Longest Increasing Subsequence) lengths array with
 * appropriate values based on stack
 * (Helper function for ft_get_lis_lengths)
 *
 * @param tmp: stack to operate on
 * @param lengths: length array to fill
 */
static void	ft_fill_lengths(t_stack *tmp, int *lengths)
{
	size_t			i;
	size_t			j;
	t_double_list	*i_iter;
	t_double_list	*j_iter;

	if (tmp == NULL || tmp->size == 1)
		return ;
	i = 1;
	i_iter = tmp->stack_ptr->next;
	while (i < tmp->size)
	{
		j_iter = tmp->stack_ptr;
		j = 0;
		while (j < i)
		{
			if (*((int *) j_iter->content) < *((int *) i_iter->content)
				&& lengths[i] + 1 > lengths[j])
				lengths[i] = lengths[j] + 1;
			j_iter = j_iter->next;
			++j;
		}
		i_iter = i_iter->next;
		++i;
	}
}

/**
 * @brief Get LIS (Longest Increasing Subsequence) lengths array from stack.
 *
 * @param tmp: stack to operate on
 * @return int*: newly created lengths array, NULL on failure
 */
int	*ft_get_lis_lengths(t_stack *tmp)
{
	int	*lengths;

	lengths = (int *) ft_calloc(tmp->size, sizeof(int));
	if (lengths == NULL)
		return (NULL);
	ft_int_memset(lengths, 1, tmp->size);
	ft_fill_lengths(tmp, lengths);
	return (lengths);
}
