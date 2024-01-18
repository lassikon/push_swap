/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:58:31 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/18 12:01:28 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	allocate_stacks(t_stacks *s, int argc, char **argv)
{
	int	i;

	if (argc == 2)
		count_elems(s, argv[1]);
	else
		s->max_elems = argc - 1;
	s->a = (t_elem *)malloc(sizeof(t_elem) * s->max_elems);
	s->b = (t_elem *)malloc(sizeof(t_elem) * s->max_elems);
	if (s->a == NULL || s->b == NULL)
		clean_exit(s, 1);
	s->b_elems = 0;
	s->b_top = 0;
	i = 0;
	while (i < s->max_elems)
	{
		s->a[i].rank = -1;
		s->b[i].rank = -1;
		i++;
	}
	s->error = 0;
}

void	count_elems(t_stacks *s, char *argv)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*argv)
	{
		if (*argv == ' ' || (*argv >= 9 && *argv <= 13))
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		argv++;
	}
	s->max_elems = count;
}

void	fill_stack_a(t_stacks *s, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 2)
		split_string(s, argv[1]);
	while (argc != 2 && argv[i])
	{
		validate_multi_arg(s, argv[i]);
		s->a[i - 1].value = ps_atoi(s, argv[i]);
		i++;
	}
	s->a_top = 0;
	s->a_elems = s->max_elems;
	check_validity(s);
}

void	check_validity(t_stacks *s)
{
	int	i;
	int	last;
	int	size;

	size = s->max_elems;
	if (size < 2 && !s->checker)
		clean_exit(s, 0);
	while (size > 0)
	{
		i = size - 1;
		last = s->a[i].value;
		i--;
		while (i >= 0)
		{
			if (s->a[i].value == last)
				clean_exit(s, 1);
			i--;
		}
		size--;
	}
	s->stack_valid = 1;
}

void	rank_values(t_stacks *s)
{
	int	i;
	int	rank;
	int	min;
	int	min_loc;

	rank = 0;
	while (rank < s->max_elems)
	{
		min = INT_MAX;
		i = 0;
		while (i < s->max_elems)
		{
			if (s->a[i].value <= min && s->a[i].rank < 0)
			{
				min = s->a[i].value;
				min_loc = i;
			}
			i++;
		}
		s->a[min_loc].rank = rank;
		rank++;
	}
}
