/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:54:59 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 17:29:57 by lkonttin         ###   ########.fr       */
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

void	print_stack(t_stacks *stacks)
{
	int	i;
	int	rank;

	i = 0;
	while (i < stacks->max_elems)
	{
		printf("a_stack.rank:	%d		value:	%d\n", stacks->a[i].rank, stacks->a[i].value);
		i++;
	}
	printf("\na_elems: %d\n", stacks->a_elems);
	printf("b_elems: %d\n", stacks->b_elems);
	printf("max_elems: %d\n\n", stacks->max_elems);
	i = 0;
	while (i < stacks->max_elems)
	{
		printf("b_stack.rank:	%d		value:	%d\n", stacks->b[i].rank, stacks->b[i].value);
		i++;
	}
/* 	rank = 0;
	while (rank < stacks->max_elems)
	{
		i = 0;
		while(i < stacks->max_elems)
		{
			if (stacks->a[i].rank == rank)
				printf("a_stack.rank:	%d		value:	%d\n", stacks->a[i].rank, stacks->a[i].value);
			i++;
		}
		rank++;
	} */
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

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