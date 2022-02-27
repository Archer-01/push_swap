/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:16:58 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/27 12:16:07 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Apply moves if at least one move count is zero.
 * (Helper function for ft_apply_moves)
 *
 * @param moves: move data (t_movecount)
 * @param stack_a: stack A
 * @param stack_b: stack B
 */
static void	ft_apply_moves_if_zero_movecount(t_movecount moves,
	t_stack *stack_a, t_stack *stack_b)
{
	t_operation		ft_rotate;
	unsigned int	movecount;
	unsigned int	i;

	movecount = 0;
	if (moves.a_moves != 0 && moves.b_moves == 0)
	{
		if (moves.a_moves >= 0)
			ft_rotate = &ra;
		else
			ft_rotate = &rra;
		movecount = ft_abs(moves.a_moves);
	}
	else if (moves.a_moves == 0 && moves.b_moves != 0)
	{
		if (moves.b_moves >= 0)
			ft_rotate = &rb;
		else
			ft_rotate = &rrb;
		movecount = ft_abs(moves.b_moves);
	}
	i = -1;
	while (++i < movecount)
		ft_run(ft_rotate, stack_a, stack_b);
}

/**
 * @brief Apply moves if stack A moves and stack B moves are equal.
 * (Helper function for ft_apply_moves)
 *
 * @param moves: move data (t_movecount)
 * @param stack_a: stack A
 * @param stack_b: stack B
 */
static void	ft_apply_moves_if_equal(t_movecount moves, t_stack *stack_a,
	t_stack *stack_b)
{
	t_operation		ft_double_rotate;
	unsigned int	movecount;
	unsigned int	i;

	if (moves.a_moves >= 0)
		ft_double_rotate = &rr;
	else
		ft_double_rotate = &rrr;
	movecount = ft_abs(moves.a_moves);
	i = 0;
	while (i < movecount)
	{
		ft_run(ft_double_rotate, stack_a, stack_b);
		++i;
	}
}

/**
 * @brief Apply moves if stack A and stack B are different but have the same 
 * sign.
 * (Helper function for ft_apply_moves)
 *
 * @param moves: move data (t_movecount)
 * @param stack_a: stack A
 * @param stack_b: stack B
 */
static void	ft_apply_moves_if_diff_and_same_sign(t_movecount moves,
	t_stack *stack_a, t_stack *stack_b)
{
	t_operation	ft_double_rotate;

	if (moves.a_moves >= 0)
		ft_double_rotate = &rr;
	else
		ft_double_rotate = &rrr;
	while (moves.a_moves != 0 && moves.b_moves != 0)
	{
		ft_run(ft_double_rotate, stack_a, stack_b);
		if (moves.a_moves >= 0)
		{
			--moves.a_moves;
			--moves.b_moves;
		}
		else
		{
			++moves.a_moves;
			++moves.b_moves;
		}
	}
	ft_apply_moves_if_zero_movecount(moves, stack_a, stack_b);
}

/**
 * @brief Apply moves if stack A and stack B moves are different and have 
 * different signs.
 * (Helper function for ft_apply_moves)
 *
 * @param moves: move data (t_movecount)
 * @param stack_a: stack A
 * @param stack_b: stack B
 */
static void	ft_apply_moves_if_diff(t_movecount moves, t_stack *stack_a,
	t_stack *stack_b)
{
	int			tmp_movecount;

	tmp_movecount = moves.a_moves;
	moves.a_moves = 0;
	ft_apply_moves_if_zero_movecount(moves, stack_a, stack_b);
	moves.a_moves = tmp_movecount;
	moves.b_moves = 0;
	ft_apply_moves_if_zero_movecount(moves, stack_a, stack_b);
}

/**
 * @brief Apply provided move
 *
 * @param moves: move data (t_movecount)
 * @param stack_a: stack A
 * @param stack_b: stack B
 */
void	ft_apply_moves(t_movecount moves, t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (moves.a_moves == 0 || moves.b_moves == 0)
		ft_apply_moves_if_zero_movecount(moves, stack_a, stack_b);
	else if (moves.a_moves == moves.b_moves)
		ft_apply_moves_if_equal(moves, stack_a, stack_b);
	else if (moves.a_moves != moves.b_moves \
		&& ft_is_same_sign(moves.a_moves, moves.b_moves))
		ft_apply_moves_if_diff_and_same_sign(moves, stack_a, stack_b);
	else
		ft_apply_moves_if_diff(moves, stack_a, stack_b);
	ft_run(&pa, stack_a, stack_b);
}
