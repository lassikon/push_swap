/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:26:21 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/29 16:09:16 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	invalid_stack(t_elem **stack, int size)
{
	int	i;
	int	last;

	while (size > 0)
	{
		i = size - 1;
		last = (*stack)[i].value;
		i--;
		while (i >= 0)
		{
			if ((*stack)[i].value == last)
				return (1);
			i--;
		}
		size--;
	}
	return (0);
}

int	create_stack(t_elem **stack, char **argv, int size)
{
	int	i;

	*stack = (t_elem *)malloc(sizeof(t_elem) * size);
	if (*stack == NULL)
		return (1);
	i = 1;
	while (argv[i])
	{
		(*stack)[i - 1].value = ft_atoi(argv[i]);
		(*stack)[i - 1].rank = -1;
		i++;
	}
	if (invalid_stack(stack, size))
		return (1);
	return (0);
}

void	rank_values(t_elem **stack, int size)
{
	int	i;
	int	rank;
	int	min;
	int	min_loc;

	rank = 0;
	while (rank < size)
	{
		min = INT_MAX;
		i = 0;
		while(i < size)
		{
			if ((*stack)[i].value <= min && (*stack)[i].rank < 0)
			{
				min = (*stack)[i].value;
				min_loc = i;
			}
			i++;
		}
		(*stack)[min_loc].rank = rank;
		rank++;
	}
}

void	clean_exit(t_elem **a_stack, t_elem **b_stack, int err)
{
	if (*a_stack)
		free(*a_stack);
	if (*b_stack)
		free(*b_stack);
	if (err)
	{
		printf("Error\n");
		exit(1);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	t_elem	*a_stack;
	t_elem	*b_stack;
	int		err;

	err = 0;
	argc = argc - 1;
	err = create_stack(&a_stack, argv, argc);
	err = create_stack(&b_stack, argv, argc);
	if (err)
		clean_exit(&a_stack, &b_stack, 1);
	rank_values(&a_stack, argc);
	sort_stack(&a_stack, &b_stack, argc);
	// print_stack(&a_stack, argc);
	clean_exit(&a_stack, &b_stack, 0);
}
