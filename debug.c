/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:58:30 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/08 15:17:52 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->max_elems)
	{
		printf("a_stack.rank:	%d		value:	%d", s->a[i].rank, s->a[i].value);
		if (i == s->a_top)
			printf("	<- top");
		i++;
		printf("\n");
	}
	printf("\na_elems: %d\n", s->a_elems);
	printf("b_elems: %d\n", s->b_elems);
	printf("a_top; %d\n", s->a_top);
	printf("b_top; %d\n", s->b_top);
	printf("max_elems: %d\n\n", s->max_elems);
	i = 0;
	while (i < s->max_elems)
	{
		printf("b_stack.rank:	%d		value:	%d", s->b[i].rank, s->b[i].value);
		if (i == s->b_top)
			printf("	<- top");
		i++;
		printf("\n");
	}
	printf("\n\n");
/* 	rank = 0;
	while (rank < s->max_elems)
	{
		i = 0;
		while(i < s->max_elems)
		{
			if (s->a[i].rank == rank)
				printf("a_stack.rank:	%d		value:	%d\n", s->a[i].rank, s->a[i].value);
			i++;
		}
		rank++;
	} */
}