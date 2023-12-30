/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:31:44 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 15:32:30 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_empty_b(t_stacks *stacks)
{
	int	i;

	i = stacks->b_top + 1;
	if (i >= stacks->max_elems)
		i = 0;
	while (stacks->b[i].rank != -1)
	{
		i++;
		if (i >= stacks->max_elems)
			i = 0;
	}
	return (i);
}

void	push_b_array(t_stacks *stacks)
{
	int	i;
	int	shifts;

	i = next_empty_b(stacks);
	if (i > stacks->b_top)
		shifts = i - stacks->b_top;
	else
		shifts = stacks->max_elems - stacks->b_top + i;
	while(shifts > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
		shifts--;
	}

}

void	push_b(t_stacks *stacks)
{
	if (stacks->a_elems < 1)
		return ;
	push_b_array(stacks);
	stacks->b[stacks->b_top] = stacks->a[stacks->a_top];
	stacks->a[stacks->a_top].rank = -1;
	stacks->a_top = next_a_elem(stacks);
	stacks->a_elems--;
	stacks->b_elems++;
	ft_putstr_fd("pb\n", 1);
}