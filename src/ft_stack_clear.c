/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 09:48:52 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/20 09:58:10 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/**
 * @brief Clear stack from memory
 *
 * @param stack: stack to operate on
 */
void	ft_stack_clear(t_stack **stack)
{
	if (stack == NULL)
		return ;
	ft_doublelst_clear(&((*stack)->stack_ptr), &free);
	free(*stack);
	*stack = NULL;
}
