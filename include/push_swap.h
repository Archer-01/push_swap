/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:45:42 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/27 12:26:42 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_stack.h"
# include "libft.h"
# include "push_swap_operations.h"
# include "ft_utils.h"

typedef void	(*t_operation)();

typedef struct s_movecount {
	int	a_moves;
	int	b_moves;
}	t_movecount;

// Pre-sort functions

t_stack		*ft_place_smallest_num_first(t_stack *stack_a);
int			*ft_get_lis_lengths(t_stack *tmp);
int			ft_max_index(int *arr, size_t len);
int			*ft_get_lis_subsequence(t_stack *tmp, int *lengths);
int			*ft_longest_increasing_subsequence(t_stack *tmp, int *lis_length);

// Utils

void		ft_run(t_operation operation, t_stack *stack_a, t_stack *stack_b);

// Sorting functions

void		ft_push_to_stack_b(t_stack *stack_a, t_stack *stack_b, int *lis, \
	int lis_length);
t_movecount	*ft_calculate_moves(t_stack *stack_a, t_stack *stack_b);
t_movecount	*ft_find_best_move(t_movecount *moves, size_t size);
int			ft_optimize_move(t_movecount move);
void		ft_apply_moves(t_movecount moves, t_stack *stack_a, \
	t_stack *stack_b);
void		ft_push_to_stack_a(t_stack *stack_a, t_stack *stack_b);
void		ft_rotate_stack_a(t_stack *stack_a, t_stack *stack_b);
t_bool		ft_sort(t_stack *stack_a, t_stack *stack_b);

#endif