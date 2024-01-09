/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:03:12 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/09 12:02:01 by lkonttin         ###   ########.fr       */
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
		i = prev_b_elem(s, i);
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
		i = next_b_elem(s, i);
		rotations++;
	}
	return (rotations);
}

static int	calc_a_rotations(t_stacks *s, int target)
{
	int	i;
	int	rotations;

	i = s->a_top;
	rotations = 0;
	while (s->a[i].rank != target)
	{
		i = next_a_elem(s, i);
		rotations++;
	}
	return (rotations);
}

static int	calc_rev_a_rotations(t_stacks *s, int target)
{
	int	i;
	int	rotations;

	i = s->a_top;
	rotations = 0;
	while (s->a[i].rank != target)
	{
		i = prev_a_elem(s, i);
		rotations++;
	}
	return (rotations);
}

static int	find_min_rotations(int rb, int rrb, int ra, int rra)
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

static int	find_direction(int rb, int rrb, int ra, int rra)
{
	int	cost;
	int	next_cost;
	int	direction;

	direction = 1;
	if (rb >= ra)
		cost = rb;
	else
		cost = ra;
	if (rrb >= rra)
		next_cost = rrb;
	else
		next_cost = rra;
	if (next_cost < cost)
	{
		cost = next_cost;
		direction = -1;
	}
	next_cost = rb + rra;
	if (next_cost < cost)
	{
		cost = next_cost;
		direction = -2;
	}
	next_cost = rrb + ra;
	if (next_cost < cost)
	{
		cost = next_cost;
		direction = 2;
	}
	return (direction);
}

// returns -1 if reverse rotate direction, 1 if rotate
// -2 if reverse a & rotate b, 2 if rotate a & reverse b
int	cost_analysis(t_stacks *s, int index)
{
	int rb;
	int rrb;
	int	ra;
	int rra;
	
	rb = calc_b_rotations(s, index);
	rrb = calc_rev_b_rotations(s, index);
	find_target(s, s->b[index].rank);
	ra = calc_a_rotations(s, s->target_rank);
	rra = calc_rev_a_rotations(s, s->target_rank);
	s->b[index].value = find_min_rotations(rb, rrb, ra, rra);
	return (find_direction(rb, rrb, ra, rra));
}


/* void	calc_costs(t_stacks *s)
{
	int	i;
	int	count;

	s->cheapest = -1;
	i = s->b_top;
	(void)cost_analysis(s, i);
	count = 1;
	while((count < s->max_elems / 4 || count < 2) && count <= s->b_elems)
	{
		i = next_b_elem(s, i);
		(void)cost_analysis(s, i);
		count++;
	}
	i = s->b_top;
	count = 1;
	while((count < s->max_elems / 4 || count < 2) && count <= s->b_elems)
	{
		i = prev_b_elem(s, i);
		(void)cost_analysis(s, i);
		count++;
	}
} */

void	calc_costs(t_stacks *s)
{
	int	i;
	int	count;

	s->cheapest = -1;
	i = s->b_top;
	count = 0;
	while(count < s->b_elems)
	{
		if (s->b[i].rank > s->b_elems - (s->max_elems / 6))
			(void)cost_analysis(s, i);
		i = next_b_elem(s, i);
		count++;
	}
}
/* void	calc_costs(t_stacks *s)
{
	int	i;
	int	count;

	s->cheapest = -1;
	i = s->b_top;
	(void)cost_analysis(s, i);
	count = 1;
	while((count < s->max_elems / 4 || count < 2) && count <= s->b_elems)
	{
		i = next_b_elem(s, i);
		(void)cost_analysis(s, i);
		count++;
	}
	i = s->b_top;
	count = 1;
	while((count < s->max_elems / 4 || count < 2) && count <= s->b_elems)
	{
		i = prev_b_elem(s, i);
		(void)cost_analysis(s, i);
		count++;
	}
} */