/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:03:12 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/15 13:34:36 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_rotations(int rb, int rrb, int ra, int rra)
{
	int	cost;
	int	next_cost;

	if (rb >= ra)
		cost = rb;
	else
		cost = ra;
	if (rrb >= rra)
		next_cost = rrb;
	else
		next_cost = rra;
	if (next_cost < cost)
		cost = next_cost;
	next_cost = rb + rra;
	if (next_cost < cost)
		cost = next_cost;
	next_cost = rrb + ra;
	if (next_cost < cost)
		cost = next_cost;
	return (cost);
}

// returns -1 if reverse rotate direction, 1 if rotate
// -2 if reverse a & rotate b, 2 if rotate a & reverse b
int	find_direction(int rb, int rrb, int ra, int rra)
{
	int	cost;
	int	next_cost;
	int	direction;

	direction = 1;
	cost = ra;
	if (rb > ra)
		cost = rb;
	next_cost = rra;
	if (rrb > rra)
		next_cost = rrb;
	if (next_cost < cost)
	{
		cost = next_cost;
		direction = -1;
	}
	if (rb + rra < cost)
	{
		cost = rb + rra;
		direction = -2;
	}
	if (rrb + ra < cost)
		direction = 2;
	return (direction);
}

void	calc_costs(t_stacks *s)
{
	int	i;
	int	count;
	int	min_rank;

	s->cheapest = -1;
	i = s->b_top;
	count = 0;
	while (count < s->b_elems)
	{
		min_rank = s->b_highest - (s->max_elems / 8);
		if (min_rank < 8)
			min_rank = 8;
		if (s->b[i].rank > s->b_highest - min_rank)
			(void)analyze_cost(s, i);
		i = next_b_elem(s, i);
		count++;
	}
}
