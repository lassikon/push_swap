/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:26:21 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/29 20:10:52 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_validity(t_stacks *stacks)
{
	int	i;
	int	last;
	int	size;

	size = stacks->max_elems;
	while (size > 0)
	{
		i = size - 1;
		last = stacks->a[i].value;
		i--;
		while (i >= 0)
		{
			if (stacks->a[i].value == last)
			{
				stacks->error = 1;
				clean_exit(stacks);
			}
			i--;
		}
		size--;
	}
}

void	create_stack(t_stacks *stacks, char **argv, int argc)
{
	int	i;

	stacks->max_elems = argc - 1;
	stacks->error = 0;
	stacks->a = (t_elem *)malloc(sizeof(t_elem) * stacks->max_elems);
	stacks->b = (t_elem *)malloc(sizeof(t_elem) * stacks->max_elems);
	if (stacks->a == NULL || stacks->b == NULL)
	{
		stacks->error = 1;
		clean_exit(stacks);
	}
	i = 1;
	while (argv[i])
	{
		stacks->a[i - 1].value = ft_atoi(argv[i]);
		stacks->a[i - 1].rank = -1;
		i++;
	}
	check_validity(stacks);
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

void	clean_exit(t_stacks *stacks)
{
	if (stacks->a)
		free(stacks->a);
	if (stacks->b)
		free(stacks->b);
	if (stacks->error)
	{
		print_out("Error");
		exit(1);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	create_stack(&stacks, argv, argc);
	rank_values(&stacks);
	sort_stack(&stacks);
	print_stack(&stacks);
	clean_exit(&stacks);
}
