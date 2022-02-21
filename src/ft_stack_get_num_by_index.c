/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_get_num_by_index.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:50:56 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/21 11:09:54 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/**
 * @brief Get stack frame content by index
 *
 * @param stack: stack to operate on
 * @param index: index of frame content to retrieve
 * @return t_double_list*: frame content with appropriate index, NULL otherwise
 */
int	*ft_stack_get_frame_content_by_index(t_stack *stack, int index)
{
	t_double_list	*iter;
	int				i;

	if (index < 0 || stack == NULL || stack->size == 0)
		return (NULL);
	iter = stack->stack_ptr;
	i = 0;
	while (i < index)
	{
		iter = iter->next;
		++i;
	}
	return (iter->content);
}
