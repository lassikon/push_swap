/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:33:40 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/16 12:54:04 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_push_a(t_stacks *s)
{
	int	i;

	if (s->b_elems < 1)
		return ;
	push_a_array(s);
	s->a[s->a_top] = s->b[s->b_top];
	s->b[s->b_top].rank = -1;
	s->b_elems--;
	s->a_elems++;
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

void	checker_push_b(t_stacks *s)
{
	if (s->a_elems < 1)
		return ;
	push_b_array(s);
	s->b[s->b_top] = s->a[s->a_top];
	s->a[s->a_top].rank = -1;
	s->a_top = next_a_elem(s, s->a_top);
	s->a_elems--;
	s->b_elems++;
}