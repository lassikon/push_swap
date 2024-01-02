/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:18:41 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/02 17:17:59 by lkonttin         ###   ########.fr       */
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
void	find_cheapest(t_stacks *s)
{
	int i;
	int	cheapest;
	int index;

	i = 0;
	cheapest = 10000;
	while (i < s->max_elems)
	{
		if (s->b[i].value > -1 && s->b[i].value < cheapest)
		{
			index = i;
			cheapest = s->b[i].value;
		}
		i++;
	}
	s->cheapest = index;
}
// Need to add target mechanic
void	push_b_cheapest (t_stacks *s)
{
	int	direction;

	direction = cost_analysis(s, s->cheapest);
	if (direction = 1)
	{
		while ()
	}

}


// max_elems 5 or 7 leaves 2 in a_stack
void	big_sort(t_stacks *s)
{
	push_lower_chunks(s);
	push_upper_chunks(s);
	sort_three(s);
	init_costs(s);
	while (s->b_elems > 0)
	{
		calc_costs(s);
		find_cheapest(s);
		push_b_cheapest(s);
	}
}
