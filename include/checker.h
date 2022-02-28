/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:24:22 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/28 08:58:03 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "ft_parser.h"
# include "push_swap_operations.h"

t_bool	ft_run_instructions(t_stack *stack_a, t_stack *stack_b);
t_bool	ft_check_if_ok(t_stack *stack_a, t_stack *stack_b);

#endif