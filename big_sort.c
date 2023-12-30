/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:18:41 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 22:03:24 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_done(t_stacks *s, int chunk_roof)
{
	int	i;

	i = 0;
	while (i < s->max_elems)
	{
		if (s->a[i].rank >= 0 && s->a[i].rank < chunk_roof)
			return (0);
		i++;
	}
	return (1);
}

static void	rotate_optimally(t_stacks *s, int chunk_roof, int up)
{
	if (up)
	{
		if (s->a[s->a_top].rank < chunk_roof && s->b_elems > 0)
			rotate_b(s);
		else if (s->b_elems > 0)
			rotate_ab(s);
		else
			rotate_a(s);
	}
	else if (s->a[s->a_top].rank >= chunk_roof)
		rotate_a(s);
}

static void	push_odd_chunk(t_stacks *s, int chunk_roof)
{
	int	i;

	i = 0;
	while (s->b_elems < chunk_roof - 1 && s->a_elems > 3)
	{
		if (s->a[s->a_top].rank >= 0 && s->a[s->a_top].rank < chunk_roof)
			push_b(s);
		rotate_optimally(s, chunk_roof, 0);
		i++;
	}
}

static void	push_even_chunk(t_stacks *s, int chunk_roof)
{
	int	i;

	i = 0;
	while (s->b_elems < chunk_roof - 1 && s->a_elems > 3)
	{
		if (s->a[s->a_top].rank >= 0 && s->a[s->a_top].rank < chunk_roof)
			push_b(s);
		rotate_optimally(s, chunk_roof, 1);
		i++;
	}
}

static void	push_chunks(t_stacks *s)
{
	int	chunks;
	int	chunk_roof;
	int	chunk_size;
	int	i;
	int	count;

	chunks = 2;
	if (s->max_elems >= 32)
		chunks = 4;
	chunk_size = (s->max_elems - 3) / chunks;
	chunk_roof = 0;
	while(chunks > 0 && s->a_elems > 3)
	{
		i = 0;
		chunk_roof += chunk_size;
		printf("chunks: %d\n", chunks);
		if (chunks == 1)
			chunk_roof = s->max_elems;
		printf("chunk_roof: %d\n", chunk_roof);
		if (chunks % 2 == 0)
			push_even_chunk(s, chunk_roof);
		if (chunks % 2 != 0)
			push_odd_chunk(s, chunk_roof);
		chunks--;
	}
}
// max_elems 5 or 7 leaves 2 in a_stack
void	big_sort(t_stacks *s)
{
	push_chunks(s);
	sort_three(s);
	
}
