/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:56:47 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/03 12:43:14 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stacks *s)
{
	if (s->a[s->a_top].rank != 0)
		swap_a(s);
}

void	sort_three(t_stacks *s)
{
	int	top;
	int	middle;
	int	bottom;

	top = s->a[s->a_top].rank;
	middle = s->a[next_a_elem(s, s->a_top)].rank;
	bottom = s->a[prev_a_elem(s, s->a_top)].rank;
	if (top > bottom && top > middle)
		rotate_a(s);
	else if (middle > bottom && middle > top)
		rev_rotate_a(s);
	top = s->a[s->a_top].rank;
	middle = s->a[next_a_elem(s, s->a_top)].rank;
	if (top > middle)
		swap_a(s);
}

void	sort_stack(t_stacks *s)
{
	if (s->max_elems == 2)
		sort_two(s);
	else if (s->max_elems == 3)
		sort_three(s);
	else
		big_sort(s);
}