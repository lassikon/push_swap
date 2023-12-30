/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:33:38 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 21:44:14 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_a_elem(t_stacks *s)
{
	int	i;

	i = s->a_top + 1;
	if (i >= s->max_elems)
		i = 0;
	while (s->a[i].rank == -1)
	{
		i++;
		if (i >= s->max_elems)
			i = 0;
	}
	return (i);
}

int	next_b_elem(t_stacks *s)
{
	int	i;

	i = s->b_top + 1;
	if (i >= s->max_elems)
		i = 0;
	while (s->b[i].rank == -1)
	{
		i++;
		if (i >= s->max_elems)
			i = 0;
	}
	return (i);
}

void	rotate_a(t_stacks *s)
{
	s->a_top = next_a_elem(s);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stacks *s)
{
	s->b_top = next_b_elem(s);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_stacks *s)
{
	s->a_top = next_a_elem(s);
	s->b_top = next_b_elem(s);
	ft_putstr_fd("rr\n", 1);
}