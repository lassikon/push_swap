/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:54:59 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/12 17:39:44 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_validity(t_stacks *s)
{
	int	i;
	int	last;
	int	size;

	size = s->max_elems;
	if (size < 2)
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
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_atoi(t_stacks *s, char *str)
{
	int		sign;
	long	nbr;

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
		clean_exit(s, 1);
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	if (nbr * sign > INT_MAX || nbr * sign < INT_MIN || (*str != '\0' && *str != ' '))
		clean_exit(s, 1);
	return ((int)nbr * sign);
}
//  || (*str != '\0' || *str != ' ')