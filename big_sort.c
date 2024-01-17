/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:18:41 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/17 11:58:27 by lkonttin         ###   ########.fr       */
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

void	find_cheapest(t_stacks *s)
{
	int	i;
	int	cheapest;
	int	index;
	int	count;

	if (s->b_elems == 1)
	{
		s->cheapest = s->b[s->b_top].rank;
		return ;
	}
	i = s->b_top;
	cheapest = 10000;
	count = 0;
	while (count < s->b_elems)
	{
		if (s->b[i].rank > -1 && s->b[i].value > -1 && s->b[i].value < cheapest)
		{
			index = i;
			cheapest = s->b[i].value;
		}
		i = next_b_elem(s, i);
		count++;
	}
	s->cheapest = s->b[index].rank;
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
		find_cheapest(s);
		push_a_cheapest(s);
	}
	put_smallest_on_top(s);
}
