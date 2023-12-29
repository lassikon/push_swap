/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:26:21 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/29 14:36:38 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_check(long nbr, long temp, int sign)
{
	if (nbr < temp)
	{
		if (sign > 0)
			return (-1);
		return (0);
	}
	return (1);
}
// Returns -1 if nbr goes over max long and was positive, or 0 if negative

int	ft_atoi(const char *str)
{
	int		sign;
	long	nbr;
	long	previous;

	sign = 1;
	nbr = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	if (*str < '0' && *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		previous = nbr;
		nbr = nbr * 10 + *str - '0';
		if (max_check(nbr, previous, sign) != 1)
			return (max_check(nbr, previous, sign));
		str++;
	}
	return ((int)nbr * sign);
}
void	create_stack(t_elem **stack, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		(*stack)[i - 1].value = ft_atoi(argv[i]);
		(*stack)[i - 1].rank = -1;
		i++;
	}
}
void	print_stack(t_elem **stack, int size)
{
	int	i;
	int	rank;

	i = 0;
	while (i < size)
	{
		printf("a_stack[%d].rank: %d	value: %d\n", i, (*stack)[i].rank, (*stack)[i].value);
		i++;
	}
	printf("\n\n");
	rank = 0;
	while (rank < size)
	{
		i = 0;
		while(i < size)
		{
			if ((*stack)[i].rank == rank)
				printf("a_stack[%d].rank: %d	value: %d\n", i, (*stack)[i].rank, (*stack)[i].value);
			i++;
		}
		rank++;
	}
}

/* int	find_smallest(t_elem **stack, int size)
{
	int	i;
	int	min_loc;
	int	smallest;
	
	i = 0;
	min_loc = -1;
	smallest = INT_MAX;
	while(i < size)
	{
		if ((*stack)[i].value <= smallest && (*stack)[i].rank < 0)
		{
			smallest = (*stack)[i].value;
			min_loc = i;
		}
		i++;
	}
	return (min_loc);
} */

void	rank_values(t_elem **stack, int size)
{
	int	i;
	int	rank;
	int	smallest;
	int	min_loc;

	rank = 0;
	while (rank < size)
	{
		smallest = INT_MAX;
		i = 0;
		while(i < size)
		{
			if ((*stack)[i].value <= smallest && (*stack)[i].rank < 0)
			{
				smallest = (*stack)[i].value;
				min_loc = i;
			}
			i++;
		}
		(*stack)[min_loc].rank = rank;
		rank++;
	}
}

void	sort_stack(t_elem **a_stack, t_elem **b_stack, int size)
{
	
}

int	main(int argc, char **argv)
{
	t_elem	*a_stack;
	t_elem	*b_stack;
	int			size;

	size = argc - 1;
	a_stack = (t_elem *)malloc(sizeof(t_elem) * size);
	b_stack = (t_elem *)malloc(sizeof(t_elem) * size);
	if (a_stack == NULL || b_stack == NULL)
	{
		if (a_stack)
			free(a_stack);
		if (b_stack)
			free(b_stack);
		return (0);
	}
	create_stack(&a_stack, argv);
	// create_stack(&b_stack, argv);
	rank_values(&a_stack, size);
	sort_stack(&a_stack, &b_stack, size);
	print_stack(&a_stack, size);
	free(a_stack);
	free(b_stack);
	return (0);
}
