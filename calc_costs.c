/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:03:12 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/02 17:11:47 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Return the number of rotations needed to bring i to top
// positive number = rb, negative = rrb
static int	calc_b_rotations(t_stacks *s, int i)
{
	int	rotations;

	rotations = 0;
	while (i != s->b_top)
	{
		i = prev_b_elem;
		rotations++;
	}
	return (rotations);
}
static int	calc_rev_b_rotations(t_stacks *s, int i)
{
	int rotations;

	rotations = 0;
	while (i != s->b_top)
	{
		i = next_b_elem;
		rotations++;
	}
	return (rotations);
}

static int	calc_a_rotations(t_stacks *s, int rank)
{
	int	i;
	int	count;

	i = s->a_top;
	count = 0;
	while (s->a[i].rank != rank)
	{
		i = next_a_elem(s);
		count++;
	}
	return (count);
}

static int	calc_rev_a_rotations(t_stacks *s, int rank)
{
	int	i;
	int	count;

	i = s->a_top;
	count = 0;
	while (s->a[i].rank != rank)
	{
		i = prev_a_elem(s);
		count--;
	}
	return (count);
}
static int	find_min_rotations(int rb, int rrb, int ra, int rra)
{
	int	cost;
	int	next_cost;

	cost = rb - ra;
	if (cost < 0)
		cost = -cost;
	next_cost = rrb - rra;
	if (next_cost < 0)
		next_cost = -next_cost;
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

static int	find_direction(int rb, int rrb, int ra, int rra)
{
	int	cost;
	int	next_cost;
	int	direction;

	direction = 1;
	cost = rb - ra;
	if (cost < 0)
		cost = -cost;
	next_cost = rrb - rra;
	if (next_cost < 0)
		next_cost = -next_cost;
	if (next_cost < cost)
	{
		cost = next_cost;
		direction = -1;
	}
	next_cost = rb + rra;
	if (next_cost < cost)
	{
		cost = next_cost;
		direction = 0;
	}
	next_cost = rrb + ra;
	if (next_cost < cost)
	{
		cost = next_cost;
		direction = 0;
	}
	return (direction);
}

// returns -1 if reverse rotation direction, 0 if both, 1 if positive direction
int	cost_analysis(t_stacks *s, int index)
{
	int rb;
	int rrb;
	int	ra;
	int rra;

	rb = calc_b_rotations(s, index);
	rrb = calc_rev_b_rotations(s, index);
	ra = calc_a_rotations(s, s->b[index].rank);
	rra = calc_rev_a_rotations(s, s->b[index].rank);
	s->b[index].value = find_min_rotations(rb, rrb, ra, rra);
	return (find_direction(rb, rrb, ra, rra));
}

void	calc_cost(t_stacks *s)
{
	int	i;
	int	count;

	i = s->b_top;
	s->cheapest = -1;
	while(count < s->max_elems / 4 && count <= s->b_elems);
	{
		if (s->b[i].rank > -1)
		{
			(void)cost_analysis(s, i);
			count++;
		}
		i++;
		if (i >= s->max_elems)
			i = 0;
	}
	i = s->b_top;
	count = 0;
	while(count < s->max_elems / 4 && count <= s->b_elems);
	{
		if (s->b[i].rank > -1)
		{
			(void)cost_analysis(s, i);
			count++;
		}
		i--;
		if (i < 0)
			i = s->max_elems - 1;
	}
}
