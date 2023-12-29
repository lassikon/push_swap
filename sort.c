/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:56:47 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/29 16:27:16 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(char *operation)
{
	printf("%s\n", operation);
}

static void	sort_two(t_elem **a_stack, int size)
{
	if ((*a_stack)[0].rank != 0)
		print_operation("sa");
}

void	sort_three(t_elem **a_stack, int size)
{
	if ((*a_stack)[2].rank != 2)
	{
		if ((*a_stack)[0].rank == 2)
		{
			print_operation("ra");
			if ((*a_stack)[1].rank != 0)
				print_operation("sa");
			return ;
		}
		if ((*a_stack)[1].rank == 2)
		{
			print_operation("rra");
			if ((*a_stack)[2].rank != 0)
				print_operation("sa");
			return ;
		}
	}
	if ((*a_stack)[0].rank != 0)
		print_operation("sa");
	return ;
}

void	sort_stack(t_elem **a_stack, t_elem **b_stack, int size)
{
	if (size == 2)
	{
		sort_two(a_stack, size);
	}
	else if (size == 3)
	{
		sort_three(a_stack, size);
	}
	else
	{
		//sort_many
	}
}