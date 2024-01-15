/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:58:22 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/15 13:03:03 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_string(t_stacks *s, char *argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		s->a[i].value = ps_atoi(s, argv);
		while (*argv == ' ' || (*argv >= 9 && *argv <= 13))
			argv++;
		if (*argv == '-' || *argv == '+')
		{
			argv++;
			if (!*argv || (*argv < '0' && *argv > '9'))
				clean_exit(s, 1);
		}
		while (*argv >= '0' && *argv <= '9')
			argv++;
		if (*argv && *argv != ' ' && (*argv < 9 && *argv > 13))
			clean_exit(s, 1);
		i++;
	}
}

int	ps_atoi(t_stacks *s, char *str)
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
	if (*str != '\0' && *str != ' ')
		clean_exit(s, 1);
	if (nbr * sign > INT_MAX || nbr * sign < INT_MIN)
		clean_exit(s, 1);
	return ((int)nbr * sign);
}

void	validate_multi_arg(t_stacks *s, char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str < '0' || *str > '9')
		clean_exit(s, 1);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str)
		clean_exit(s, 1);
}
