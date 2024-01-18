/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:03:12 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/18 15:28:47 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_rotations(t_rotations *rotas)
{
	int	cost;
	int	next_cost;

	if (rotas->rb >= rotas->ra)
		cost = rotas->rb;
	else
		cost = rotas->ra;
	if (rotas->rrb >= rotas->rra)
		next_cost = rotas->rrb;
	else
		next_cost = rotas->rra;
	if (next_cost < cost)
		cost = next_cost;
	next_cost = rotas->rb + rotas->rra;
	if (next_cost < cost)
		cost = next_cost;
	next_cost = rotas->rrb + rotas->ra;
	if (next_cost < cost)
		cost = next_cost;
	return (cost);
}

// returns -1 if reverse rotate direction, 1 if rotate
// -2 if reverse a & rotate b, 2 if rotate a & reverse b
int	find_direction(t_rotations *rotas)
{
	int	cost;
	int	next_cost;
	int	direction;

	direction = 1;
	cost = rotas->ra;
	if (rotas->rb > rotas->ra)
		cost = rotas->rb;
	next_cost = rotas->rra;
	if (rotas->rrb > rotas->rra)
		next_cost = rotas->rrb;
	if (next_cost < cost)
	{
		cost = next_cost;
		direction = -1;
	}
	if (rotas->rb + rotas->rra < cost)
	{
		cost = rotas->rb + rotas->rra;
		direction = -2;
	}
	if (rotas->rrb + rotas->ra < cost)
		direction = 2;
	return (direction);
}

void	calc_costs(t_stacks *s)
{
	int	i;
	int	count;
	int	cheapest;
	int	cheapest_index;

	i = s->b_top;
	count = 0;
	cheapest = INT_MAX;
	cheapest_index = i;
	while (count < s->b_elems)
	{
		if (s->b[i].rank > s->b_highest - 20)
		{
			(void)analyze_cost(s, i);
			if (s->b[i].value < cheapest)
			{
				cheapest = s->b[i].value;
				cheapest_index = i;
			}
		}
		i = next_b_elem(s, i);
		count++;
	}
	s->cheapest = cheapest_index;
}
