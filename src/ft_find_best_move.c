/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:06:30 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/27 12:11:34 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Find best move possible to push number from stack B to stack A in a
 * way that keeps the stack A circularly sorted
 *
 * @param moves: list of all possible moves
 * @param size: move list size
 * @return t_movecount*: pointer on best move data (t_movecount), NULL otherwise
 */
t_movecount	*ft_find_best_move(t_movecount *moves, size_t size)
{
	size_t	i;
	int		best_movecount;
	int		best_movecount_index;
	int		curr_movecount;

	if (moves == NULL || size == 0)
		return (NULL);
	best_movecount_index = 0;
	best_movecount = ft_optimize_move(moves[0]);
	i = 1;
	while (i < size)
	{
		curr_movecount = ft_optimize_move(moves[i]);
		if (curr_movecount < best_movecount)
		{
			best_movecount = curr_movecount;
			best_movecount_index = i;
		}
		++i;
	}
	return (&moves[best_movecount_index]);
}
