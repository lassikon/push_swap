/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_cheapest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:20:13 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/15 13:37:54 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_same_direction(t_stacks *s, int direction)
{
	int	target;
	int	cheap;

	target = s->target_rank;
	cheap = s->cheapest;
	if (direction == 1)
	{
		while (s->a[s->a_top].rank != target && s->b[s->b_top].rank != cheap)
			rotate_ab(s);
		while (s->a[s->a_top].rank != target)
			rotate_a(s);
		while (s->b[s->b_top].rank != cheap)
			rotate_b(s);
	}
	else if (direction == -1)
	{
		while (s->a[s->a_top].rank != target && s->b[s->b_top].rank != cheap)
			rev_rotate_ab(s);
		while (s->a[s->a_top].rank != target)
			rev_rotate_a(s);
		while (s->b[s->b_top].rank != cheap)
			rev_rotate_b(s);
	}
}

static void	rotate_diff_direction(t_stacks *s, int direction)
{
	if (direction == 2)
	{
		while (s->a[s->a_top].rank != s->target_rank)
			rotate_a(s);
		while (s->b[s->b_top].rank != s->cheapest)
			rev_rotate_b(s);
	}
	else if (direction == -2)
	{
		while (s->a[s->a_top].rank != s->target_rank)
			rev_rotate_a(s);
		while (s->b[s->b_top].rank != s->cheapest)
			rotate_b(s);
	}
}

void	find_target(t_stacks *s, int rank)
{
	int	i;
	int	best_match;

	i = 0;
	best_match = s->max_elems;
	while (i < s->max_elems)
	{
		if (s->a[i].rank > rank && s->a[i].rank < best_match)
			best_match = s->a[i].rank;
		i++;
	}
	s->target_rank = best_match;
}

static int	find_direction_for_cheapest(t_stacks *s)
{
	int	i;
	int	count;
	int	cheapest_index;

	i = s->b_top;
	count = 0;
	cheapest_index = i;
	while (count <= s->b_elems)
	{
		if (s->b[i].rank == s->cheapest)
			cheapest_index = i;
		i = next_b_elem(s, i);
		count++;
	}
	return (analyze_cost(s, cheapest_index));
}

// direction is -1 if reverse rotate both, 1 if rotate both
// -2 if reverse rotate a & rotate b, 2 if rotate a & reverse rotate b
void	push_a_cheapest(t_stacks *s)
{
	int	direction;

	direction = find_direction_for_cheapest(s);
	find_target(s, s->cheapest);
	if (direction == 1 || direction == -1)
		rotate_same_direction(s, direction);
	else if (direction == 2 || direction == -2)
		rotate_diff_direction(s, direction);
	push_a(s);
}
