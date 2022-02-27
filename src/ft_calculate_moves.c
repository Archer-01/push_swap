/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:48:40 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/27 10:12:09 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculate move count for a number to be placed on top of the stack
 * based on its index in the stack.
 *
 * @param stack: stack to operate on
 * @param index: number index
 * @return int: move count to be on top (positive count for "ra/rb", negative
 * for "rra/rrb")
 */
static int	ft_calc_moves_to_be_on_top(t_stack *stack, int index)
{
	if ((size_t) index < stack->size / 2)
		return (index);
	else
		return (index - stack->size);
}

/**
 * @brief Calculate number of necessary moves for each number on stack B to be
 * properly placed on stack A so that stack A remains circularly sorted.
 *
 * @param stack_a: stack A
 * @param stack_b: stack B
 * @return t_movecount*: array of structs containing move count for each number
 * on stack B (Please refer to t_movecount definition for details), NULL on
 * failure
 */
t_movecount	*ft_calculate_moves(t_stack *stack_a, t_stack *stack_b)
{
	t_double_list	*iter;
	t_movecount		*moves;
	int				i;
	int				curr_num;
	int				stack_a_index;

	if (stack_a == NULL || stack_b == NULL)
		return (NULL);
	moves = (t_movecount *) ft_calloc(stack_b->size, sizeof(t_movecount));
	if (moves == NULL)
		return (NULL);
	i = 0;
	iter = stack_b->stack_ptr;
	while (iter != NULL)
	{
		curr_num = *((int *) iter->content);
		stack_a_index = ft_stack_get_proper_index(stack_a, curr_num);
		moves[i].a_moves = ft_calc_moves_to_be_on_top(stack_a, stack_a_index);
		moves[i].b_moves = ft_calc_moves_to_be_on_top(stack_b, i);
		++i;
		iter = iter->next;
	}
	return (moves);
}
