/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:21:32 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/08 13:31:16 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prev_a_elem(t_stacks *s, int i)
{
	if (s->a_elems <= 1)
		return (i);
	i--;
	if (i < 0)
		i = s->max_elems - 1;
	while (s->a[i].rank == -1)
	{
		i--;
		if (i < 0)
			i = s->max_elems -1;
	}
	return (i);
}

int	prev_b_elem(t_stacks *s, int i)
{
	if (s->b_elems <= 1)
		return (i);
	i--;
	if (i < 0)
		i = s->max_elems - 1;
	while (s->b[i].rank == -1)
	{
		i--;
		if (i < 0)
			i = s->max_elems -1;
	}
	return (i);
}

void	rev_rotate_a(t_stacks *s)
{
	s->a_top = prev_a_elem(s, s->a_top);
	ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_b(t_stacks *s)
{
	s->b_top = prev_b_elem(s, s->b_top);
	ft_putstr_fd("rrb\n", 1);
}

void	rev_rotate_ab(t_stacks *s)
{
	s->a_top = prev_a_elem(s, s->a_top);
	s->b_top = prev_b_elem(s, s->b_top);
	ft_putstr_fd("rrr\n", 1);
}