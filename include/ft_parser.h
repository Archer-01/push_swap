/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:47:44 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/20 14:43:33 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "libft.h"
# include "ft_stack.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

// Argument retreival

char	**ft_get_args(int argc, char **argv);
void	ft_clear_args(char **args);

// Argument checking

long	ft_atol(const char *str);
t_bool	ft_check_args(const char **args);

// Parser

t_stack	*ft_parser(int argc, char **argv);

#endif