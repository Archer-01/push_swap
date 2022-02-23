/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:42:27 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/23 09:37:57 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

/**
 * @brief Count arguments.
 * (Helper function for ft_parser)
 *
 * @param args: string array to operate on
 * @return int: argument count
 */
static int	ft_count_args(const char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		++i;
	return (i);
}

/**
 * @brief Get number from arguments string array
 * (Helper function for ft_parser)
 *
 * @param args: string array to operate on
 * @param args_count: string array argument count
 * @return int*: newly created integer array, NULL on failure
 */
static int	*ft_get_nums(const char **args, int args_count)
{
	int	*nums;
	int	i;

	nums = (int *) ft_calloc(args_count, sizeof(int));
	if (nums == NULL)
		return (NULL);
	i = 0;
	while (args[i] != NULL)
	{
		nums[i] = ft_atol(args[i]);
		++i;
	}
	return (nums);
}

/**
 * @brief Initialize stack a.
 * Initialize stack a number integer array
 * (Helper function for ft_parser)
 *
 * @param nums: integer array to operate on
 * @param nums_count: integer count in array
 * @return t_stack*: newly created stack a, NULL on failure
 */
static t_stack	*ft_init_stack_a(int *nums, int nums_count)
{
	t_stack	*stack_a;
	int		i;

	stack_a = ft_stack_new();
	if (stack_a == NULL)
		return (NULL);
	i = nums_count - 1;
	while (i >= 0)
	{
		if (ft_stack_push(&stack_a, nums[i]) == FALSE)
		{
			ft_stack_clear(&stack_a);
			return (NULL);
		}
		--i;
	}
	return (stack_a);
}

/**
 * @brief Parse command line arguments.
 * Get and split command line arguments by word.
 * Check for argument validity (see ft_check_args)
 * Create stack that contains arguments as integers.
 *
 * @param argc: argument
 * @param argv: argument vector (array)
 * @return t_stack*: newly created stack, NULL on failure
 */
t_stack	*ft_parser(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**args;
	int		args_count;
	int		*nums;

	args = ft_get_args(argc, argv);
	if (args == NULL || *args == NULL
		|| ft_check_args((const char **) args) == FALSE)
	{
		ft_clear_args(args);
		if (*args == NULL)
			exit(EXIT_FAILURE);
		return (NULL);
	}
	args_count = ft_count_args((const char **) args);
	nums = ft_get_nums((const char **) args, args_count);
	if (nums == NULL)
	{
		ft_clear_args(args);
		return (NULL);
	}
	stack_a = ft_init_stack_a(nums, args_count);
	ft_clear_args(args);
	free(nums);
	return (stack_a);
}
