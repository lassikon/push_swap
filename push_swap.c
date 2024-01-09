/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:26:21 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/09 19:29:22 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(t_stacks *s, int error)
{
	if (s->a)
		free(s->a);
	if (s->b)
		free(s->b);
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	exit(0);
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
		while(i < s->max_elems)
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
// Splits single input string for ft_atoi and checks for forbidden chars (necessary?)
// ATM SEGFAULTS IF INVALID CHARS INSIDE NUMBER
void	split_string(t_stacks *s, char *argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		s->a[i].value = ft_atoi(s, argv);
		while (*argv == '-' || (*argv >= '0' && *argv <= '9'))
			argv++;
		if (*argv != '-' && *argv != ' ' && (*argv < '0' && *argv > '9'))
			clean_exit(s, 1);
		if (*argv == ' ')
			argv++;
		i++;
	}
}

void	fill_stack_a(t_stacks *s, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 2)
		split_string(s, argv[1]);
	while (argc != 2 && argv[i])
	{
		s->a[i - 1].value = ft_atoi(s, argv[i]);
		s->a[i - 1].rank = -1;
		i++;
	}
	s->a_top = 0;
	s->a_elems = s->max_elems;
	check_validity(s);
}
// If input was a single string, counts the number of elements inside it
void	count_elems(t_stacks *s, char *argv)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*argv)
	{
		if (*argv == ' ')
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

void	prep_stacks(t_stacks *s, int argc, char **argv)
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
	while(i < s->max_elems)
	{
		s->a[i].rank = -1;
		s->b[i].rank = -1;
		i++;
	}
	s->error = 0;
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	if (argc == 1)
		exit(0);
	prep_stacks(&s, argc, argv);
	fill_stack_a(&s, argc, argv);
	rank_values(&s);
	sort_stack(&s);
	// print_stack(&s);
	clean_exit(&s, 0);
}
