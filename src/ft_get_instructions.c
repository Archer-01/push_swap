/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 08:20:28 by hhamza            #+#    #+#             */
/*   Updated: 2022/02/28 08:51:27 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * @brief Check if instruction is a valid push_swap instruction.
 *
 * @param instruction: instruction name to check
 * @return t_bool: TRUE on valid instruction, FALSE otherwise
 */
static t_bool	ft_check_instruction(const char *instruction)
{
	if (instruction == NULL)
		return (FALSE);
	else if (ft_strcmp(instruction, "sa\n") == 0
		|| ft_strcmp(instruction, "sb\n") == 0
		|| ft_strcmp(instruction, "ss\n") == 0
		|| ft_strcmp(instruction, "pa\n") == 0
		|| ft_strcmp(instruction, "pb\n") == 0
		|| ft_strcmp(instruction, "ra\n") == 0
		|| ft_strcmp(instruction, "rb\n") == 0
		|| ft_strcmp(instruction, "rr\n") == 0
		|| ft_strcmp(instruction, "rra\n") == 0
		|| ft_strcmp(instruction, "rrb\n") == 0
		|| ft_strcmp(instruction, "rrr\n") == 0)
		return (TRUE);
	else
		return (FALSE);
}

/**
 * @brief Run proper push_swap instruction
 *
 * @param instruction: instruction name to run
 * @param stack_a: stack A
 * @param stack_b: stack B
 */
static void	ft_run(const char *instruction, t_stack *stack_a, t_stack *stack_b)
{
	if (instruction == NULL || stack_a == NULL || stack_b == NULL)
		return ;
	else if (ft_strcmp(instruction, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		pa(&stack_a, &stack_b);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		pb(&stack_a, &stack_b);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rrr(stack_a, stack_b);
}

/**
 * @brief Get push_swap instructions from standard input and run them properly.
 *
 * @param stack_a: stack A
 * @param stack_b: stack B
 * @return t_bool: TRUE if all instructions ran successfully, FALSE otherwise
 */
t_bool	ft_run_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	*instruction;

	if (stack_a == NULL || stack_b == NULL)
		return (FALSE);
	instruction = get_next_line(STDIN_FILENO);
	while (instruction != NULL)
	{
		if (ft_check_instruction(instruction) == FALSE)
		{
			ft_putendl_fd("KO", STDOUT_FILENO);
			free(instruction);
			return (FALSE);
		}
		ft_run(instruction, stack_a, stack_b);
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
	return (TRUE);
}
