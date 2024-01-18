/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:15:19 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/18 12:23:48 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Move top of b to the bottom of stack b if it's smaller than median
static int	rotate_optimally(t_stacks *s, int max, int median)
{
	if (s->a[s->a_top].rank >= max)
	{
		if (s->b_elems > 0 && s->b[s->b_top].rank < median)
			rotate_ab(s);
		else
			rotate_a(s);
		return (1);
	}
	else if (s->b_elems > 0 && s->b[s->b_top].rank < median)
		rotate_b(s);
	return (0);
}

static void	push_elems_in_range(t_stacks *s, int max, int median)
{
	int	loops;

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
}

void	push_chunks(t_stacks *s)
{
	int	chunk_size;
	int	max;
	int	median;

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
		push_elems_in_range(s, max, median);
		if (chunk_size >= 32)
			chunk_size /= 2;
	}
}
