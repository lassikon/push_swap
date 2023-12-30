/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:26:24 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 13:25:10 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_empty_a(t_stacks *stacks)
{
	int	i;

	i = stacks->a_top + 1;
	if (i >= stacks->max_elems)
		i = 0;
	while (stacks->a[i].rank != -1)
	{
		i++;
		if (i >= stacks->max_elems)
			i = 0;
	}
	return (i);
}

void	push_a_array(t_stacks *stacks)
{
	int	i;
	int	shifts;

	i = next_empty_a(stacks);
	if (i > stacks->a_top)
		shifts = i - stacks->a_top;
	else
		shifts = stacks->max_elems - stacks->a_top + i;
	while(shifts > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
		shifts--;
	}

}

void	push_a(t_stacks *stacks)
{
	push_a_array(stacks);
	stacks->a[stacks->a_top] = stacks->b[stacks->b_top];
	stacks->b[stacks->b_top].rank = -1;
	stacks->b_top = next_b_elem(stacks);
	ft_putstr_fd("pa\n", 1);
}
