/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:22:50 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/28 14:55:50 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

/**
 * @brief Check for duplicate strings
 * (Helper function for ft_check_args)
 *
 * @param args: string array to operate on
 * @return t_bool: TRUE if duplicates were found, FALSE otherwise
 */
static t_bool	ft_check_duplicates(const char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i] != NULL)
	{
		j = i + 1;
		while (args[j] != NULL)
		{
			if (ft_strcmp(args[i], args[j]) == 0)
				return (TRUE);
			++j;
		}
		++i;
	}
	return (FALSE);
}

/**
 * @brief Check if string is a valid number.
 * Valid numbers may start with a single sign (+/-) and contain only digits
 * afterwards.
 * (Helper function for ft_check_numbers)
 *
 * @param str: string to operate on
 * @return t_bool: TRUE for valid number, FALSE for non
 */
static t_bool	ft_check_number(const char *str)
{
	int	i;

	i = 0;
	if (ft_strcmp(str, "+") == 0 || ft_strcmp(str, "-") == 0)
		return (FALSE);
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

/**
 * @brief Check if all string array contains valid numbers
 * (Helper function for ft_check_args)
 *
 * @param args: string array to operate on
 * @return t_bool: TRUE if all string array contains valid numbers,
 * FALSE otherwise
 */
static t_bool	ft_check_numbers(const char **args)
{
	int		i;
	long	num;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_check_number(args[i]) == FALSE)
			return (FALSE);
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

/**
 * @brief Check if arguments are valid.
 * Valid arguments must not have duplicates and must be valid integers
 *
 * @param args: string array to operate on
 * @return t_bool: TRUE for valid arguments, FALSE otherwise
 */
t_bool	ft_check_args(const char **args)
{
	return (ft_check_duplicates(args) == FALSE \
		&& ft_check_numbers(args) == TRUE);
}
