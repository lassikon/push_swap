/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:21:32 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 12:39:33 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prev_a_elem(t_stacks *stacks)
{
	int	i;

	i = stacks->a_top - 1;
	if (i < 0)
		i = stacks->max_elems - 1;
	while (stacks->a[i].rank == -1)
	{
		i--;
		if (i < 0)
			i = stacks->max_elems;
	}
	return (i);
}

int	prev_b_elem(t_stacks *stacks)
{
	int	i;

	i = stacks->b_top - 1;
	if (i < 0)
		i = stacks->max_elems - 1;
	while (stacks->b[i].rank == -1)
	{
		i--;
		if (i < 0)
			i = stacks->max_elems;
	}
	return (i);
}

void	rev_rotate_a(t_stacks *stacks, int rrr)
{
	stacks->a_top = prev_a_elem(stacks);
	if (!rrr)
		ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_b(t_stacks *stacks, int rrr)
{
	stacks->b_top = prev_b_elem(stacks);
	if (!rrr)
		ft_putstr_fd("rrb\n", 1);
}

void	rev_rotate_ab(t_stacks *stacks)
{
	rev_rotate_a(stacks, 1);
	rev_rotate_b(stacks, 1);
	ft_putstr_fd("rrr\n", 1);
}