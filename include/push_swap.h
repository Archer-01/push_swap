/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:45:42 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/22 14:59:43 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_stack.h"
# include "libft.h"
# include "push_swap_operations.h"

// Pre-sort functions

t_stack	*ft_place_smallest_num_first(t_stack *stack_a);
int		*ft_get_lis_lengths(t_stack *tmp);
int		ft_max_index(int *arr, size_t len);
int		*ft_get_lis_subsequence(t_stack *tmp, int *lengths);
int		*ft_longest_increasing_subsequence(t_stack *tmp, int *lis_length);

void	ft_run(void (*f)(), t_stack *stack_a, t_stack *stack_b);

t_bool	ft_sort(t_stack *stack_a, t_stack *stack_b);

#endif