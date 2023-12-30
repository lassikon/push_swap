/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:26:21 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 17:26:11 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(t_stacks *stacks)
{
	if (stacks->a)
		free(stacks->a);
	if (stacks->b)
		free(stacks->b);
	if (stacks->error)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	exit(0);
}

void	rank_values(t_stacks *stacks)
{
	int	i;
	int	rank;
	int	min;
	int	min_loc;

	rank = 0;
	while (rank < stacks->max_elems)
	{
		min = INT_MAX;
		i = 0;
		while(i < stacks->max_elems)
		{
			if (stacks->a[i].value <= min && stacks->a[i].rank < 0)
			{
				min = stacks->a[i].value;
				min_loc = i;
			}
			i++;
		}
		stacks->a[min_loc].rank = rank;
		rank++;
	}
}
// Splits single input string for ft_atoi and checks for forbidden chars (necessary?)
// ATM SEGFAULTS IF INVALID CHARS INSIDE NUMBER
void	split_string(t_stacks *stacks, char *argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		stacks->a[i].value = ft_atoi(argv);
		while (*argv == '-' || (*argv >= '0' && *argv <= '9'))
			argv++;
		if (*argv != '-' && *argv != ' ' && (*argv < '0' && *argv > '9'))
		{
			stacks->error = 1;
			clean_exit(stacks);
		}
		if (*argv == ' ')
			argv++;
		i++;
	}
}

void	fill_stack_a(t_stacks *stacks, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 2)
		split_string(stacks, argv[1]);
	while (argc != 2 && argv[i])
	{
		stacks->a[i - 1].value = ft_atoi(argv[i]);
		stacks->a[i - 1].rank = -1;
		i++;
	}
	stacks->a_top = 0;
	stacks->a_elems = stacks->max_elems;
	check_validity(stacks);
}
// If input was a single string, counts the number of elements inside it
void	count_elems(t_stacks *stacks, char *argv)
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
	stacks->max_elems = count;
}

void	prep_stacks(t_stacks *stacks, int argc, char **argv)
{
	int	i;

	if (argc == 2)
		count_elems(stacks, argv[1]);
	else
		stacks->max_elems = argc - 1;
	stacks->a = (t_elem *)malloc(sizeof(t_elem) * stacks->max_elems);
	stacks->b = (t_elem *)malloc(sizeof(t_elem) * stacks->max_elems);
	if (stacks->a == NULL || stacks->b == NULL)
	{
		stacks->error = 1;
		clean_exit(stacks);
	}
	stacks->b_elems = 0;
	stacks->b_top = 0;
	i = 0;
	while(i < stacks->max_elems)
	{
		stacks->a[i].rank = -1;
		stacks->b[i].rank = -1;
		i++;
	}
	stacks->error = 0;
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 1)
		exit(0);
	prep_stacks(&stacks, argc, argv);
	fill_stack_a(&stacks, argc, argv);
	rank_values(&stacks);
	sort_stack(&stacks);
	print_stack(&stacks);
	clean_exit(&stacks);
}
