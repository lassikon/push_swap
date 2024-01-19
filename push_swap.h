/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:18:33 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/19 12:16:06 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/include/libft.h"

typedef struct element
{
	int	value;
	int	rank;
}	t_elem;

typedef struct rotations
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_rotations;

typedef struct stacks
{
	t_elem	*a;
	t_elem	*b;
	int		a_top;
	int		b_top;
	int		max_elems;
	int		a_elems;
	int		b_elems;
	int		cheapest;
	int		target_rank;
	int		error;
	int		b_highest;
	int		checker;
	int		stack_valid;
}	t_stacks;

int		ps_atoi(t_stacks *s, char *str);
void	count_elems(t_stacks *s, char *argv);
void	allocate_stacks(t_stacks *s, int argc, char **argv);
void	fill_stack_a(t_stacks *s, int argc, char **argv);
void	split_string(t_stacks *s, char *argv);
void	validate_multi_arg(t_stacks *s, char *str);
void	check_validity(t_stacks *s);
void	clean_exit(t_stacks *s, int error);
void	sort_stack(t_stacks *s);
void	sort_three(t_stacks *s);
void	rank_values(t_stacks *s);
void	swap_a(t_stacks *s);
void	swap_b(t_stacks *s);
void	swap_ab(t_stacks *s);
void	push_a(t_stacks *s);
void	push_b(t_stacks *s);
void	rotate_a(t_stacks *s);
void	rotate_b(t_stacks *s);
void	rotate_ab(t_stacks *s);
void	rev_rotate_a(t_stacks *s);
void	rev_rotate_b(t_stacks *s);
void	rev_rotate_ab(t_stacks *s);
int		next_a_elem(t_stacks *s, int i);
int		next_b_elem(t_stacks *s, int i);
int		prev_a_elem(t_stacks *s, int i);
int		prev_b_elem(t_stacks *s, int i);
void	big_sort(t_stacks *s);
void	calc_costs(t_stacks *s);
int		analyze_cost(t_stacks *s, int index);
void	init_costs(t_stacks *s);
void	find_target(t_stacks *s, int rank);
void	put_smallest_on_top(t_stacks *s);
void	check_if_already_sorted(t_stacks *s);
void	b_highest(t_stacks *s);
void	push_chunks(t_stacks *s);
void	push_a_cheapest(t_stacks *s);
int		find_min_rotations(t_rotations *rotas);
int		find_direction(t_rotations *rotas);
void	push_a_array(t_stacks *s);
void	push_b_array(t_stacks *s);

#endif