/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:34:09 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/15 15:55:27 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move(t_stacks *s, char *instruction)
{
	return ;
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
