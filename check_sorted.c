/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:08:58 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/16 13:59:26 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	circularly_sorted(t_stacks *s, int i)
{
	int	count;
	int	current;
	int	next;

	count = 0;
	while (count < s->a_elems)
	{
		current = s->a[i].rank;
		next = s->a[next_a_elem(s, i)].rank;
		i = next_a_elem(s, i);
		count++;
		if (current > next)
		{
			if (next == 0)
				continue ;
			else
				return (0);
		}
	}
	return (1);
}

void	check_if_already_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->a_elems - 1)
	{
		if (s->a[i].rank > s->a[i + 1].rank)
		{
			if (circularly_sorted(s, i))
			{
				put_smallest_on_top(s);
				break ;
			}
			return ;
		}
		i++;
	}
	clean_exit(s, 0);
}
