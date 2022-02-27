/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:07:18 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/27 10:14:07 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Optimize number of moves needed to push number from stack B to stack
 * A (Reduce "ra & rb" to "rr" or "rra & rrb" to "rrr" if possible)
 *
 * @param move: move count data to optimize (t_movecount)
 * @return int: optimized number of moves (always positive)
 */
int	ft_optimize_move(t_movecount move)
{
	int	a_moves;
	int	b_moves;

	a_moves = move.a_moves;
	b_moves = move.b_moves;
	if (a_moves == 0 && b_moves == 0)
		return (0);
	else if (a_moves == 0 && b_moves != 0)
		return (ft_abs(b_moves));
	else if (a_moves != 0 && b_moves == 0)
		return (ft_abs(a_moves));
	else if (a_moves == b_moves)
		return (ft_abs(a_moves));
	else if (a_moves != b_moves && ft_is_same_sign(a_moves, b_moves) == TRUE)
		return (ft_abs_max(a_moves, b_moves));
	else
		return (ft_abs(a_moves) + ft_abs(b_moves));
}
