/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:56:47 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 13:44:46 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stacks *stacks)
{
	if (stacks->a[0].rank != 0)
		swap_a(stacks, 0);
}

void	sort_three(t_stacks *stacks)
{
	if (stacks->a[2].rank != 2)
	{
		if (stacks->a[0].rank == 2)
		{
			rotate_a(stacks, 0);
			if (stacks->a[1].rank != 0)
				swap_a(stacks, 0);
			return ;
		}
		if (stacks->a[1].rank == 2)
		{
			rev_rotate_a(stacks, 0);
			if (stacks->a[2].rank != 0)
				swap_a(stacks, 0);
			return ;
		}
	}
	if (stacks->a[0].rank != 0)
		swap_a(stacks, 0);
	return ;
}

void	sort_stack(t_stacks *stacks)
{
	if (stacks->max_elems == 2)
	{
		sort_two(stacks);
	}
	else if (stacks->max_elems == 3)
	{
		sort_three(stacks);
	}
	else
	{
		//sort_many
	}
}