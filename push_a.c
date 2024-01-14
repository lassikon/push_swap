/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:26:24 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/14 11:59:09 by lkonttin         ###   ########.fr       */
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
		if (i > 0)
		{
			s->a[i] = s->a[i - 1];
			i--;
		}
		else if (i == 0)
		{
			s->a[i] = s->a[s->max_elems - 1];
			i = s->max_elems - 1;
		}
		shifts--;
	}
	return ;
}

void	push_a(t_stacks *s)
{
	int i;
	
	if (s->b_elems < 1)
		return ;
	push_a_array(s);
	s->a[s->a_top] = s->b[s->b_top];
	s->b[s->b_top].rank = -1;
	s->b_elems--;
	s->a_elems++;
	ft_putstr_fd("pa\n", 1);
	if (s->b_elems < 1)
		return ;
	i = s->b_top;
	while (s->b[i].rank == -1)
	{
		i++;
		if (i >= s->max_elems)
			i = 0;
	}
	s->b_top = i;
	if (s->a[s->a_top].rank == s->b_highest)
		b_highest(s);
}
