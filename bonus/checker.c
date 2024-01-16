/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:34:09 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/16 14:03:01 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	move(t_stacks *s, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		checker_swap_a(s);
	else if (!ft_strcmp(instruction, "sb\n"))
		checker_swap_b(s);
	else if (!ft_strcmp(instruction, "ss\n"))
		checker_swap_ab(s);
	else if (!ft_strcmp(instruction, "pa\n"))
		checker_push_a(s);
	else if (!ft_strcmp(instruction, "pb\n"))
		checker_push_b(s);
	else if (!ft_strcmp(instruction, "ra\n"))
		checker_rotate_a(s);
	else if (!ft_strcmp(instruction, "rb\n"))
		checker_rotate_b(s);
	else if (!ft_strcmp(instruction, "rr\n"))
		checker_rotate_ab(s);
	else if (!ft_strcmp(instruction, "rra\n"))
		checker_rev_rotate_a(s);
	else if (!ft_strcmp(instruction, "rrb\n"))
		checker_rev_rotate_b(s);
	else if (!ft_strcmp(instruction, "rrr\n"))
		checker_rev_rotate_ab(s);
	else
		clean_exit(s, 1);
}

static int	is_sorted(t_stacks *s)
{
	int	count;
	int	current;
	int	next;
	int	i;

	i = s->a_top;
	count = 0;
	while (count < s->a_elems)
	{
		current = s->a[i].rank;
		next = s->a[next_a_elem(s, i)].rank;
		i = next_a_elem(s, i);
		count++;
		if (current > next)
		{
			if (next == 0)
				continue ;
			else
				return (0);
		}
	}
	return (1);
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
	if (is_sorted(&s) && s.b_elems == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clean_exit(&s, 0);
}
