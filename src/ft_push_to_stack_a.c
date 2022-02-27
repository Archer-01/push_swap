/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:45:32 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/27 12:54:14 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Push all elements of stack to stack A so that stack A remains 
 * circularly sorted
 *
 * @param stack_a: stack A
 * @param stack_b: stack B
 */
void	ft_push_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	t_movecount		*moves;
	t_movecount		*best_move;

	while (stack_b->size != 0)
	{
		moves = ft_calculate_moves(stack_a, stack_b);
		if (moves == NULL)
			return ;
		best_move = ft_find_best_move(moves, stack_b->size);
		if (best_move == NULL)
		{
			free(moves);
			return ;
		}
		ft_apply_moves(*best_move, stack_a, stack_b);
		free(moves);
	}
}
