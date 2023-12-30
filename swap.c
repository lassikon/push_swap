/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:00:01 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 12:37:04 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks, int ss)
{
	t_elem temp;

	temp = stacks->a[stacks->a_top];
	stacks->a[stacks->a_top] = stacks->a[next_a_elem(stacks)];
	stacks->a[next_a_elem(stacks)] = temp;
	if (!ss)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stacks *stacks, int ss)
{
	t_elem temp;

	temp = stacks->b[stacks->b_top];
	stacks->b[stacks->b_top] = stacks->b[next_b_elem(stacks)];
	stacks->b[next_b_elem(stacks)] = temp;
	if (!ss)
		ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_stacks *stacks)
{
	swap_a(stacks, 1);
	swap_b(stacks, 1);
	ft_putstr_fd("ss\n", 1);
}