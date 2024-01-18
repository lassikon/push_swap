/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:18:41 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/18 13:44:12 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_costs(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->max_elems)
	{
		s->a[i].value = -1;
		s->b[i].value = -1;
		i++;
	}
}

void	put_smallest_on_top(t_stacks *s)
{
	int	median;
	int	i;
	int	count;

	i = s->a_top;
	median = s->max_elems / 2;
	count = 0;
	while (count < median)
	{
		if (s->a[i].rank == 0)
		{
			while (s->a[s->a_top].rank != 0)
				rotate_a(s);
			return ;
		}
		i = next_a_elem(s, i);
		count++;
	}
	while (s->a[s->a_top].rank != 0)
		rev_rotate_a(s);
}

void	big_sort(t_stacks *s)
{
	push_chunks(s);
	sort_three(s);
	init_costs(s);
	b_highest(s);
	while (s->b_elems > 0)
	{
		calc_costs(s);
		push_a_cheapest(s);
	}
	put_smallest_on_top(s);
}
