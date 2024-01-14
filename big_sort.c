/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:18:41 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/14 12:28:01 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Move top of b to the bottom of stack b if it's smaller than median
static int	rotate_optimally(t_stacks *s, int chunk_roof, int median)
{
	if (s->a[s->a_top].rank >= chunk_roof )
	{
		if (s->b_elems > 0 && s->b[s->b_top].rank < median)
			rotate_ab(s);
		else
			rotate_a(s);
		return (1);
	}
	else if (s->b[s->b_top].rank > -1 && s->b[s->b_top].rank < median)
		rotate_b(s);
	return (0);
}

static void	dynamic_chunks(t_stacks *s)
{
	int chunk_size;
	int	max;
	int	median;
	int	loops;
	
	chunk_size = s->max_elems / 2;
	if (chunk_size < 8)
		chunk_size = s->max_elems;
	max = 0;
	median = 0;
	while (s->a_elems > 3)
	{
		max += chunk_size;
		if (max >= s->max_elems)
			max = s->max_elems - 1;
		median = max - (chunk_size / 2);
		loops = s->a_elems;
		while (loops > 0 && s->a_elems > 3)
		{
			if (s->a[s->a_top].rank >= 0 && s->a[s->a_top].rank < max)
			{
				push_b(s);
				loops--;
			}
			if (rotate_optimally(s, max, median))
				loops--;
		}
		if (chunk_size >= 16)
			chunk_size /= 2;
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

static int	find_direction(t_stacks *s)
{
	int	i;
	int count;
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
	return cost_analysis(s, cheapest_index);
}

// direction is -1 if reverse rotate both, 1 if rotate both
// -2 if reverse rotate a & rotate b, 2 if rotate a & reverse rotate b
void	push_a_cheapest (t_stacks *s)
{
	int	direction;

	direction = find_direction(s);
	find_target(s, s->cheapest);
	if (direction == 1)
	{
		while (s->a[s->a_top].rank != s->target_rank && s->b[s->b_top].rank != s->cheapest)
			rotate_ab(s);
		while (s->a[s->a_top].rank != s->target_rank)
			rotate_a(s);
		while (s->b[s->b_top].rank != s->cheapest)
			rotate_b(s);
	}
	else if (direction == -1)
	{
		while (s->a[s->a_top].rank != s->target_rank && s->b[s->b_top].rank != s->cheapest)
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

void	b_highest(t_stacks *s)
{
	int	i;
	int	count;

	i = s->b_top;
	count = 0;
	s->b_highest = 0;
	while (count < s->b_elems)
	{
		if (s->b[i].rank > s->b_highest)
			s->b_highest = s->b[i].rank;
		i = next_b_elem(s, i);
		count++;
	}
}

void	big_sort(t_stacks *s)
{
	dynamic_chunks(s);
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
