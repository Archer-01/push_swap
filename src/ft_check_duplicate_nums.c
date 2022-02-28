/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_duplicate_nums.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:50:53 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/28 17:53:54 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

/**
 * @brief Check for duplicate numbers in array
 *
 * @param nums: number array
 * @param len: number array length
 * @return t_bool: TRUE if duplicate were found, FALSE otherwise
 */
t_bool	ft_check_duplicate_nums(int *nums, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nums[i] == nums[j])
				return (TRUE);
			++j;
		}
		++i;
	}
	return (FALSE);
}
