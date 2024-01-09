/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:18:33 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/09 19:26:23 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct	element
{
	int	value;
	int	rank;
}	t_elem;

typedef struct	stacks
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
}	t_stacks;

int		ft_atoi(t_stacks *s, char *str);
void	prep_stacks(t_stacks *s, int argc, char **argv);
void	fill_stack_a(t_stacks *s, int argc, char **argv);
void	split_string(t_stacks *s, char *argv);
void	check_validity(t_stacks *s);
void	clean_exit(t_stacks *s, int error);
void	sort_stack(t_stacks *s);
void	sort_three(t_stacks *s);
void	ft_putstr_fd(char *s, int fd);
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
int		cost_analysis(t_stacks *s, int index);
void	init_costs(t_stacks *s);
void	find_target(t_stacks *s, int rank);
void	put_smallest_on_top(t_stacks *s);

//DEBUG
void	print_stack(t_stacks *s);

#endif