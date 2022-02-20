/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 08:59:37 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/20 09:19:29 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/**
 * @brief Initialize integer pointer
 * (Helper function for ft_stack_push)
 *
 * @param num: integer to point to
 * @return int*: newly created integer pointer
 */
static int	*ft_init_numptr(int num)
{
	int	*numptr;

	numptr = (int *) ft_calloc(1, sizeof(int));
	if (numptr == NULL)
		return (NULL);
	*numptr = num;
	return (numptr);
}

/**
 * @brief Push integer to stack
 *
 * @param stack: stack to operate on
 * @param num: integer to push
 * @return t_bool: TRUE on success, FALSE on failure
 */
t_bool	ft_stack_push(t_stack **stack, int num)
{
	int				*numptr;
	t_double_list	*newframe;

	if (stack == NULL)
		return (FALSE);
	numptr = ft_init_numptr(num);
	if (numptr == NULL)
		return (FALSE);
	newframe = ft_doublelst_new(numptr);
	if (newframe == NULL)
		return (FALSE);
	if (*stack == NULL)
	{
		*stack = ft_stack_new();
		if (*stack == NULL)
			return (FALSE);
	}
	ft_doublelst_addfront(&(*stack)->stack_ptr, newframe);
	++((*stack)->size);
	if ((*stack)->size == 1)
		(*stack)->base_ptr = (*stack)->stack_ptr;
	return (TRUE);
}
