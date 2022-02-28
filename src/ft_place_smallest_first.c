/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_smallest_first.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:34:46 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/28 13:44:26 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Place smallest number on top of stack A
 *
 * @param stack_a: stack A
 * @param stack_b: stack B
 */
void	ft_place_smallest_first(t_stack *stack_a, t_stack *stack_b)
{
	int			*smallest_num;
	int			smallest_index;
	t_operation	ft_rotate;

	smallest_index = ft_stack_get_smallest_num_index(stack_a);
	if (smallest_index == 0)
		return ;
	else if ((size_t) smallest_index <= stack_a->size / 2)
		ft_rotate = &ra;
	else
		ft_rotate = &rra;
	smallest_num = ft_stack_get_frame_content_by_index(stack_a, smallest_index);
	while (*((int *) stack_a->stack_ptr->content) != *smallest_num)
		ft_run(ft_rotate, stack_a, stack_b);
}
