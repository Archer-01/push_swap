/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:23:59 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/28 09:07:48 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * @brief Clear stacks A and B
 *
 * @param stack_a: stack A
 * @param stack_b: stack B
 */
static void	ft_clear_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (EXIT_FAILURE);
	stack_a = ft_parser(argc, argv);
	if (stack_a == NULL)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	stack_b = ft_stack_new();
	if (stack_b == NULL)
	{
		ft_stack_clear(&stack_a);
		return (EXIT_FAILURE);
	}
	if (ft_run_instructions(stack_a, stack_b) == FALSE
		|| ft_check_if_ok(stack_a, stack_b) == FALSE)
	{
		ft_clear_stacks(stack_a, stack_b);
		return (EXIT_FAILURE);
	}
	ft_clear_stacks(stack_a, stack_b);
	return (EXIT_SUCCESS);
}
