/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:47:51 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/22 14:59:33 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// static void	ft_stack_print(t_stack *stack)
// {
// 	t_double_list	*iter;

// 	if (stack == NULL)
// 		return ;
// 	if (stack->size == 0)
// 	{
// 		ft_putendl_fd("Empty stack", STDOUT_FILENO);
// 		return ;
// 	}
// 	iter = stack->stack_ptr;
// 	ft_printf("[");
// 	while (iter != NULL)
// 	{
// 		ft_printf("%i", *((int *) iter->content));
// 		if (iter->next != NULL)
// 			ft_putchar_fd(' ', STDOUT_FILENO);
// 		iter = iter->next;
// 	}
// 	ft_printf("]\n");
// }

t_bool	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	*lis;
	int	lis_length;

	lis = ft_longest_increasing_subsequence(stack_a, &lis_length);
	if (lis == NULL)
	{
		ft_stack_clear(&stack_a);
		ft_stack_clear(&stack_b);
		return (FALSE);
	}
	ft_print_lis(lis, lis_length);
	free(lis);
	return (TRUE);
}
