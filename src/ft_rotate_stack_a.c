/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:18:20 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/27 12:54:49 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotate stack A so that the smallest number comes first
 *
 * @param stack_a: stack A
 * @param stack_b: stack B
 */
void	ft_rotate_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int			index;
	int			*smallest_num;
	t_operation	ft_rotate;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	index = ft_stack_get_smallest_num_index(stack_a);
	if (index == -1)
		return ;
	smallest_num = ft_stack_get_frame_content_by_index(stack_a, index);
	if (smallest_num == NULL)
		return ;
	if ((size_t) index <= stack_a->size / 2)
		ft_rotate = &ra;
	else
		ft_rotate = &rra;
	while (*((int *) stack_a->stack_ptr->content) != *smallest_num)
		ft_run(ft_rotate, stack_a, stack_b);
}
