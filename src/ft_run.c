/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:20:28 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/23 09:33:25 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Print push_swap operation name
 * (Helper function for ft_run)
 *
 * @param operation: pointer on function whose name is to be printed
 */
static void	ft_print_operation_name(t_operation operation)
{
	if (operation == &sa)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (operation == &sb)
		ft_putendl_fd("sb", STDOUT_FILENO);
	else if (operation == &ss)
		ft_putendl_fd("ss", STDOUT_FILENO);
	else if (operation == &pa)
		ft_putendl_fd("pa", STDOUT_FILENO);
	else if (operation == &pb)
		ft_putendl_fd("pb", STDOUT_FILENO);
	else if (operation == &ra)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (operation == &rb)
		ft_putendl_fd("rb", STDOUT_FILENO);
	else if (operation == &rr)
		ft_putendl_fd("rr", STDOUT_FILENO);
	else if (operation == &rra)
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (operation == &rrb)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	else if (operation == &rrr)
		ft_putendl_fd("rrr", STDOUT_FILENO);
	else
		ft_putendl_fd("Error. Unknown push_swap operation", STDERR_FILENO);
}

/**
 * @brief Run push_swap operation and print its name
 *
 * @param operation: pointer on function to run
 * @param stack_a: stack A
 * @param stack_b: stack B
 */
void	ft_run(t_operation operation, t_stack *stack_a, t_stack *stack_b)
{
	if (operation == NULL || stack_a == NULL || stack_b == NULL)
		return ;
	if (operation == &sa || operation == &ra || operation == &rra)
		operation(stack_a);
	else if (operation == &sb || operation == &rb || operation == &rrb)
		operation(stack_b);
	else if (operation == &ss || operation == &rr || operation == &rrr)
		operation(stack_a, stack_b);
	else if (operation == &pa || operation == &pb)
		operation(&stack_a, &stack_b);
	ft_print_operation_name(operation);
}
