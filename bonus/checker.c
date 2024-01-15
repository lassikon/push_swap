/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:34:09 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/15 17:03:20 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	move(t_stacks *s, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		sa(s);
	else if (!ft_strcmp(instruction, "sb\n"))
		sb(s);
	else if (!ft_strcmp(instruction, "ss\n"))
		ss(s);
	else if (!ft_strcmp(instruction, "pa\n"))
		pa(s);
	else if (!ft_strcmp(instruction, "pb\n"))
		pb(s);
	else if (!ft_strcmp(instruction, "ra\n"))
		ra(s);
	else if (!ft_strcmp(instruction, "rb\n"))
		rb(s);
	else if (!ft_strcmp(instruction, "rr\n"))
		rr(s);
	else if (!ft_strcmp(instruction, "rra\n"))
		rra(s);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrb(s);
	else if (!ft_strcmp(instruction, "rrr\n"))
		rrr(s);
}

int	checker(int argc, char **argv)
{
	t_stacks	s;
	char		*instruction;

	if (argc == 1)
		exit(0);
	if (*argv[1] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	allocate_stacks(&s, argc, argv);
	fill_stack_a(&s, argc, argv);
	rank_values(&s);
	instruction = get_next_line(0);
	while (instruction)
	{
		move(&s, instruction);
		free(instruction);
		instruction = get_next_line(0);
	}
	clean_exit(&s, 0);
}
