/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:26:24 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 21:47:34 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_empty_a(t_stacks *s)
{
	int	i;

	i = s->a_top + 1;
	if (i >= s->max_elems)
		i = 0;
	while (s->a[i].rank != -1)
	{
		i++;
		if (i >= s->max_elems)
			i = 0;
	}
	return (i);
}

void	push_a_array(t_stacks *s)
{
	int	i;
	int	shifts;

	i = next_empty_a(s);
	if (i > s->a_top)
		shifts = i - s->a_top;
	else
		shifts = s->max_elems - s->a_top + i;
	while(shifts > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
		shifts--;
	}
	return ;
}

void	push_a(t_stacks *s)
{
	if (s->b_elems < 1)
		return ;
	push_a_array(s);
	s->a[s->a_top] = s->b[s->b_top];
	s->b[s->b_top].rank = -1;
	s->b_top = next_b_elem(s);
	s->b_elems--;
	s->a_elems++;
	ft_putstr_fd("pa\n", 1);
}
