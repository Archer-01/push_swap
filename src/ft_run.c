/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:20:28 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/23 08:19:07 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Print push_swap operation name
 * (Helper function for ft_run)
 *
 * @param f: pointer on function whose name is to be printed
 */
static void	ft_print_operation_name(void (*f)())
{
	if (f == &sa)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (f == &sb)
		ft_putendl_fd("sb", STDOUT_FILENO);
	else if (f == &ss)
		ft_putendl_fd("ss", STDOUT_FILENO);
	else if (f == &pa)
		ft_putendl_fd("pa", STDOUT_FILENO);
	else if (f == &pb)
		ft_putendl_fd("pb", STDOUT_FILENO);
	else if (f == &ra)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (f == &rb)
		ft_putendl_fd("rb", STDOUT_FILENO);
	else if (f == &rr)
		ft_putendl_fd("rr", STDOUT_FILENO);
	else if (f == &rra)
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (f == &rrb)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	else if (f == &rrr)
		ft_putendl_fd("rrr", STDOUT_FILENO);
	else
		ft_putendl_fd("Error. Unknown push_swap operation", STDERR_FILENO);
}

/**
 * @brief Run push_swap operation and print its name
 *
 * @param f: pointer on function to run
 * @param stack_a: stack A
 * @param stack_b: stack B
 */
void	ft_run(void (*f)(), t_stack *stack_a, t_stack *stack_b)
{
	if (f == NULL || stack_a == NULL || stack_b == NULL)
		return ;
	if (f == &sa || f == &ra || f == &rra)
		f(stack_a);
	else if (f == &sb || f == &rb || f == &rrb)
		f(stack_b);
	else if (f == &ss || f == &rr || f == &rrr)
		f(stack_a, stack_b);
	else if (f == &pa || f == &pb)
		f(&stack_a, &stack_b);
	ft_print_operation_name(f);
}
