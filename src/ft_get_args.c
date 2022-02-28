/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:54:28 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/28 17:06:09 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

/**
 * @brief Add space to string
 * (Helper function for ft_join_argv)
 *
 * @param str: string to operate on
 * @return char*: newly created string, NULL on failure
 */
static char	*ft_add_space(char *str)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(str, " ");
	if (tmp != NULL)
		free(tmp);
	return (str);
}

/**
 * @brief Join command line arguments into a single string
 * (Helper function for ft_get_args)
 *
 * @param argc: argument count
 * @param argv: argument vector (array)
 * @return char*: newly created string, NULL on failure
 */
static char	*ft_join_argv(int argc, char **argv)
{
	char	*result;
	char	*tmp;
	int		i;

	result = NULL;
	i = 1;
	while (i < argc)
	{
		tmp = result;
		result = ft_strjoin(result, argv[i]);
		if (tmp != NULL)
			free(tmp);
		if (result == NULL)
			return (NULL);
		if (i != argc - 1)
			result = ft_add_space(result);
		if (result == NULL)
			return (NULL);
		++i;
	}
	return (result);
}

/**
 * @brief Get command line arguments split into words
 *
 * @param argc: argument count
 * @param argv: argument vector (array)
 * @return char**: newly created word array, NULL on failure
 */
char	**ft_get_args(int argc, char **argv)
{
	char	*joined;
	char	**args;

	joined = ft_join_argv(argc, argv);
	if (joined == NULL)
		return (NULL);
	args = ft_split(joined, ' ');
	if (args == NULL)
		return (NULL);
	if (joined != NULL)
		free(joined);
	return (args);
}
