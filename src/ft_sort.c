/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:47:51 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/23 11:35:43 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stack_print(t_stack *stack)
{
	t_double_list	*iter;

	if (stack == NULL)
		return ;
	if (stack->size == 0)
	{
		ft_putendl_fd("Empty stack", STDOUT_FILENO);
		return ;
	}
	iter = stack->stack_ptr;
	ft_printf("[");
	while (iter != NULL)
	{
		ft_printf("%i", *((int *) iter->content));
		if (iter->next != NULL)
			ft_putchar_fd(' ', STDOUT_FILENO);
		iter = iter->next;
	}
	ft_printf("]\n");
}

t_bool	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	*lis;
	int	lis_length;

	if (ft_stack_is_sorted(stack_a))
		return (TRUE);
	lis = ft_longest_increasing_subsequence(stack_a, &lis_length);
	if (lis == NULL)
	{
		ft_stack_clear(&stack_a);
		ft_stack_clear(&stack_b);
		return (FALSE);
	}
	ft_push_to_stack_b(stack_a, stack_b, lis, lis_length);
	ft_stack_print(stack_a);
	ft_stack_print(stack_b);
	free(lis);
	return (TRUE);
}
