/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:33:38 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 12:36:12 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_a_elem(t_stacks *stacks)
{
	int	i;

	i = stacks->a_top + 1;
	if (i >= stacks->max_elems)
		i = 0;
	while (stacks->a[i].rank == -1)
	{
		i++;
		if (i >= stacks->max_elems)
			i = 0;
	}
	return (i);
}

int	next_b_elem(t_stacks *stacks)
{
	int	i;

	i = stacks->b_top + 1;
	if (i >= stacks->max_elems)
		i = 0;
	while (stacks->b[i].rank == -1)
	{
		i++;
		if (i >= stacks->max_elems)
			i = 0;
	}
	return (i);
}

void	rotate_a(t_stacks *stacks, int rr)
{
	stacks->a_top = next_a_elem(stacks);
	if (!rr)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stacks *stacks, int rr)
{
	stacks->b_top = next_b_elem(stacks);
	if (!rr)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_stacks *stacks)
{
	rotate_a(stacks, 1);
	rotate_b(stacks, 1);
	ft_putstr_fd("rr\n", 1);
}