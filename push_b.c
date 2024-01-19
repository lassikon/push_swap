/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:31:44 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/19 11:48:01 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_empty_b(t_stacks *s)
{
	int	i;

	i = s->b_top + 1;
	if (i >= s->max_elems)
		i = 0;
	while (s->b[i].rank != -1)
	{
		i++;
		if (i >= s->max_elems)
			i = 0;
	}
	return (i);
}

void	push_b_array(t_stacks *s)
{
	int	i;
	int	shifts;

	i = next_empty_b(s);
	if (i > s->b_top)
		shifts = i - s->b_top;
	else
		shifts = s->max_elems - s->b_top + i;
	while (shifts > 0)
	{
		if (i > 0)
		{
			s->b[i] = s->b[i - 1];
			i--;
		}
		else if (i == 0)
		{
			s->b[i] = s->b[s->max_elems - 1];
			i = s->max_elems - 1;
		}
		shifts--;
	}
}

void	push_b(t_stacks *s)
{
	if (s->a_elems < 1)
		return ;
	push_b_array(s);
	s->b[s->b_top] = s->a[s->a_top];
	s->a[s->a_top].rank = -1;
	if (s->a_elems > 1)
		s->a_top = next_a_elem(s, s->a_top);
	else
		s->a_top = 0;
	s->a_elems--;
	s->b_elems++;
	if (!s->checker)
		ft_putstr_fd("pb\n", 1);
}