/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:19:48 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/22 14:56:07 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_stack.h"
#include "libft.h"
#include "push_swap.h"

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
	ft_printf("Sorting...\n");
	ft_sort(stack_a, stack_b);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (EXIT_SUCCESS);
}
