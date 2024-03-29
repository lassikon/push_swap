/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:31:20 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/19 11:33:22 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	rotations;

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

int	analyze_cost(t_stacks *s, int index)
{
	t_rotations	rotas;

	rotas.rb = calc_b_rotations(s, index);
	rotas.rrb = calc_rev_b_rotations(s, index);
	find_target(s, s->b[index].rank);
	rotas.ra = calc_a_rotations(s, s->target_rank);
	rotas.rra = calc_rev_a_rotations(s, s->target_rank);
	s->b[index].value = find_min_rotations(&rotas);
	return (find_direction(&rotas));
}
