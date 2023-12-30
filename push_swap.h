/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:18:33 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/30 13:41:21 by lkonttin         ###   ########.fr       */
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
	int	real_index;
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
	int		error;
}	t_stacks;

int		ft_atoi(const char *str);
void	prep_stacks(t_stacks *stacks, int argc, char **argv);
void	fill_stack_a(t_stacks *stacks, int argc, char **argv);
void	split_string(t_stacks *stacks, char *argv);
void	print_stack(t_stacks *stacks);
void	check_validity(t_stacks *stacks);
void	clean_exit(t_stacks *stacks);
void	sort_stack(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	ft_putstr_fd(char *s, int fd);
void	rank_values(t_stacks *stacks);
void	swap_a(t_stacks *stacks, int ss);
void	swap_b(t_stacks *stacks, int ss);
void	swap_ab(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	rotate_a(t_stacks *stacks, int rr);
void	rotate_b(t_stacks *stacks, int rr);
void	rotate_ab(t_stacks *stacks);
void	rev_rotate_a(t_stacks *stacks, int rrr);
void	rev_rotate_b(t_stacks *stacks, int rrr);
void	rev_rotate_ab(t_stacks *stacks);

#endif