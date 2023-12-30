/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:18:41 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 17:09:31 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunk(t_stacks *stacks, int chunk_roof)
{
	int	i;

	i = 0;
	while (i < stacks->max_elems)
	{
		
		if (stacks->a[i].rank >= 0 && stacks->a[i].rank < chunk_roof)
		{
			push_b(stacks);
		}
		i++;
	}
	return ;
}

void	big_sort(t_stacks *stacks)
{
	int	chunks;
	int	chunk_roof;
	int	chunk_size;
	int	i;

	chunks = 2;
	if (stacks->max_elems >= 32)
		chunks = 4;
	chunk_size = (stacks->max_elems - 3) / chunks;
	i = 0;
	chunk_roof = 0;
	while(chunks > 0)
	{
		chunk_roof += chunk_size;
		if (chunk_roof > stacks->max_elems)
			chunk_roof > stacks->max_elems;
		push_chunk(stacks, chunk_roof);
		chunks--;
	}
	return ;
}
