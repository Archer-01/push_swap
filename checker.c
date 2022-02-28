/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:23:59 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/28 08:03:50 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_stack_print(t_stack *stack)
{
	t_double_list	*iter;

	ft_printf("[");
	iter = stack->stack_ptr;
	while (iter != NULL)
	{
		ft_printf("%i", *((int *) iter->content));
		if (iter->next != NULL)
			ft_printf(" ");
		iter = iter->next;
	}
	ft_printf("]\n");
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
		return (EXIT_FAILURE);
	ft_stack_print(stack_a);
	ft_printf("Checker is loading...\n");
	return (0);
}
