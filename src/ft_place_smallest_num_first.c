/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_smallest_num_first.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:13:23 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/27 12:20:39 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Create new temporary stack with smallest value at the top
 * (Helper function for ft_place_smallest_num_first)
 *
 * @param stack_a: stack to operate on
 * @param smallest_index: smallest value index on stack_a
 * @return t_stack*: newly created temporary stack, NULL on failure
 */
static t_stack	*ft_place_nums(t_stack *stack_a, int smallest_index)
{
	t_stack	*tmp;
	int		*smallest_num;
	void	(*ft_rotate)(t_stack *);

	if (stack_a == NULL || stack_a->size == 0)
		return (NULL);
	tmp = ft_stack_duplicate(stack_a);
	if (tmp == NULL)
		return (NULL);
	if ((size_t) smallest_index <= stack_a->size / 2)
		ft_rotate = &ra;
	else
		ft_rotate = &rra;
	smallest_num = ft_stack_get_frame_content_by_index(stack_a, smallest_index);
	if (smallest_num == NULL)
		return (NULL);
	while (*((int *) tmp->stack_ptr->content) != *smallest_num)
		ft_rotate(tmp);
	return (tmp);
}

/**
 * @brief Find smallest number and place it at the top of a temporary stack.
 *
 * @param stack_a: stack to operate on
 * @return t_stack*: newly created temporary stack, NULL on failure
 */
t_stack	*ft_place_smallest_num_first(t_stack *stack_a)
{
	t_stack	*tmp;
	int		smallest_index;

	if (stack_a == NULL || stack_a->size == 0)
		return (NULL);
	smallest_index = ft_stack_get_smallest_num_index(stack_a);
	if (smallest_index == -1)
		return (NULL);
	tmp = ft_place_nums(stack_a, smallest_index);
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}
