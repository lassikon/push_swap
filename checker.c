/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:34:09 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/17 12:42:40 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(t_stacks *s, int error)
{
	if (s->a)
	{
		free(s->a);
		s->a = NULL;
	}
	if (s->b)
	{
		free(s->b);
		s->b = NULL;
	}
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	exit(0);
}

static void	move(t_stacks *s, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		swap_a(s);
	else if (!ft_strcmp(instruction, "sb\n"))
		swap_b(s);
	else if (!ft_strcmp(instruction, "ss\n"))
		swap_ab(s);
	else if (!ft_strcmp(instruction, "pa\n"))
		push_a(s);
	else if (!ft_strcmp(instruction, "pb\n"))
		push_b(s);
	else if (!ft_strcmp(instruction, "ra\n"))
		rotate_a(s);
	else if (!ft_strcmp(instruction, "rb\n"))
		rotate_b(s);
	else if (!ft_strcmp(instruction, "rr\n"))
		rotate_ab(s);
	else if (!ft_strcmp(instruction, "rra\n"))
		rev_rotate_a(s);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rev_rotate_b(s);
	else if (!ft_strcmp(instruction, "rrr\n"))
		rev_rotate_ab(s);
	else
		s->stack_valid = 0;
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
static void	init_stacks(t_stacks *s, int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	if (*argv[1] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	allocate_stacks(s, argc, argv);
	fill_stack_a(s, argc, argv);
	rank_values(s);
}

int	main(int argc, char **argv)
{
	t_stacks	s;
	char		*instruction;

	s.checker = 1;
	init_stacks(&s, argc, argv);
	instruction = get_next_line(0);
	while (instruction)
	{
		move(&s, instruction);
		free(instruction);
		if (!s.stack_valid)
			clean_exit(&s, 1);
		instruction = get_next_line(0);
	}
	if (is_sorted(&s) && s.b_elems == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clean_exit(&s, 0);
	exit(0);
}
