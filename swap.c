/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:00:01 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 21:43:44 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *s)
{
	t_elem temp;

	if (s->a_elems < 2)
		return ;
	temp = s->a[s->a_top];
	s->a[s->a_top] = s->a[next_a_elem(s)];
	s->a[next_a_elem(s)] = temp;
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stacks *s)
{
	t_elem temp;

	if (s->b_elems < 2)
		return ;
	temp = s->b[s->b_top];
	s->b[s->b_top] = s->b[next_b_elem(s)];
	s->b[next_b_elem(s)] = temp;
	ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_stacks *s)
{
	t_elem temp;

	if (s->a_elems < 2 || s->b_elems < 2)
		return ;
	temp = s->a[s->a_top];
	s->a[s->a_top] = s->a[next_a_elem(s)];
	s->a[next_a_elem(s)] = temp;
	temp = s->b[s->b_top];
	s->b[s->b_top] = s->b[next_b_elem(s)];
	s->b[next_b_elem(s)] = temp;
	ft_putstr_fd("ss\n", 1);
}