/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:19:48 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/22 11:56:07 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_stack.h"
#include "libft.h"
#include "push_swap.h"

static void	ft_print_lis(int *lis, int len)
{
	int	i;

	ft_printf("[");
	i = 0;
	while (i < len)
	{
		ft_printf("%d", lis[i]);
		if (i != len - 1)
			ft_printf(", ");
		++i;
	}
	ft_printf("]\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*lis;
	int		lis_length;

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
	lis = ft_longest_increasing_subsequence(stack_a, &lis_length);
	if (lis == NULL)
	{
		ft_stack_clear(&stack_a);
		ft_stack_clear(&stack_b);
		return (EXIT_FAILURE);
	}
	ft_print_lis(lis, lis_length);
	free(lis);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (EXIT_SUCCESS);
}
