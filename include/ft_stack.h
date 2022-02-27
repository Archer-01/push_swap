/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:17:19 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/27 17:45:06 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"

typedef struct s_stack
{
	t_double_list	*stack_ptr;
	t_double_list	*base_ptr;
	size_t			size;
}	t_stack;

t_stack			*ft_stack_new(void);
t_bool			ft_stack_push(t_stack **stack, int num);
int				ft_stack_pop(t_stack *stack);
void			ft_stack_clear(t_stack **stack);
t_stack			*ft_stack_duplicate(t_stack *stack);
int				*ft_stack_get_frame_content_by_index(t_stack *stack, int index);
t_double_list	*ft_stack_get_frame_by_index(t_stack *stack, int index);
int				ft_stack_get_index_by_value(t_stack *stack, int value);
t_bool			ft_stack_is_sorted(t_stack *stack);
int				ft_stack_get_proper_index(t_stack *stack, int num);
int				ft_stack_get_smallest_num_index(t_stack *stack);

#endif