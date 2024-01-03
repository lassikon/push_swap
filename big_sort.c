/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:18:41 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/03 18:25:12 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Move top of b to the bottom of stack b if it's smaller than median
static void	rotate_optimally(t_stacks *s, int chunk_roof, int median)
{
	if (s->a[s->a_top].rank >= chunk_roof )
	{
		if (s->b_elems > 0 && s->b[s->b_top].rank < median)
			rotate_ab(s);
		else
			rotate_a(s);
	}
	else if (s->b[s->b_top].rank > -1 && s->b[s->b_top].rank < median)
		rotate_b(s);
}

static void push_lower_chunks(t_stacks *s)
{
	int	chunk_roof;

	chunk_roof = s->max_elems / 2;
	while (s->b_elems < chunk_roof && s->a_elems > 3)
	{
		if (s->a[s->a_top].rank >= 0 && s->a[s->a_top].rank < chunk_roof)
			push_b(s);
		rotate_optimally(s, chunk_roof, chunk_roof / 2);
	}
}
static void push_upper_chunks(t_stacks *s)
{
	int	chunk_roof;

	chunk_roof = s->max_elems - 1;
	while (s->b_elems < chunk_roof && s->a_elems > 3)
	{
		if (s->a[s->a_top].rank >= 0 && s->a[s->a_top].rank < chunk_roof)
			push_b(s);
		rotate_optimally(s, chunk_roof, (chunk_roof / 4) * 3);
	}
}

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

void	find_cheapest(t_stacks *s)
{
	int i;
	int	cheapest;
	int index;

	i = 0;
	cheapest = 10000;
	while (i < s->max_elems)
	{
		if (s->b[i].rank > -1 && s->b[i].value < cheapest)
		{
			index = i;
			cheapest = s->b[i].value;
		}
		i++;
	}
	s->cheapest = s->b[index].rank;
}
// direction is -1 if reverse rotate both, 1 if rotate both
// -2 if reverse rotate a & rotate b, 2 if rotate a & reverse rotate b
void	push_a_cheapest (t_stacks *s)
{
	int	direction;
	int b_top_rank;

	direction = cost_analysis(s, s->cheapest);
	find_target(s, s->b[s->cheapest].rank);
	if (direction == 1)
	{
		while (s->a[s->a_top].rank != s->target_rank && s->b[s->b_top].value != s->cheapest)
			rotate_ab(s);
		while (s->a[s->a_top].rank != s->target_rank)
			rotate_a(s);
		while (s->b[s->b_top].rank != s->cheapest)
		{
			b_top_rank = s->b[s->b_top].rank;
			rotate_b(s);
		}
	}
	else if (direction == -1)
	{
		while (s->a[s->a_top].rank != s->target_rank && s->b[s->b_top].value != s->cheapest)
			rev_rotate_ab(s);
		while (s->a[s->a_top].rank != s->target_rank)
			rev_rotate_a(s);
		while (s->b[s->b_top].rank != s->cheapest)
			rev_rotate_b(s);
	}
	else if (direction == 2)
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
	push_a(s);
}

// max_elems 5 or 7 leaves 2 in a_stack
void	big_sort(t_stacks *s)
{
	push_lower_chunks(s);
	push_upper_chunks(s);
	sort_three(s);
	init_costs(s);
	while (s->b_elems > 1)
	{
		calc_costs(s);
		find_cheapest(s);
		push_a_cheapest(s);
	}
	push_a(s);
}
