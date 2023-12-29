/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:54:59 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/29 16:09:44 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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