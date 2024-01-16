/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:26:28 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/16 12:29:50 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_swap_a(t_stacks *s)
{
	t_elem	temp;

	if (s->a_elems < 2)
		return ;
	temp = s->a[s->a_top];
	s->a[s->a_top] = s->a[next_a_elem(s, s->a_top)];
	s->a[next_a_elem(s, s->a_top)] = temp;
}

void	checker_swap_b(t_stacks *s)
{
	t_elem	temp;

	if (s->b_elems < 2)
		return ;
	temp = s->b[s->b_top];
	s->b[s->b_top] = s->b[next_b_elem(s, s->b_top)];
	s->b[next_b_elem(s, s->b_top)] = temp;
}

void	checker_swap_ab(t_stacks *s)
{
	t_elem	temp;

	if (s->a_elems < 2 || s->b_elems < 2)
		return ;
	temp = s->a[s->a_top];
	s->a[s->a_top] = s->a[next_a_elem(s, s->a_top)];
	s->a[next_a_elem(s, s->a_top)] = temp;
	temp = s->b[s->b_top];
	s->b[s->b_top] = s->b[next_b_elem(s, s->b_top)];
	s->b[next_b_elem(s, s->b_top)] = temp;
}