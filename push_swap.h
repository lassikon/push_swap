/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:18:33 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/29 20:12:21 by lkonttin         ###   ########.fr       */
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
	int		error;
}	t_stacks;

int		ft_atoi(const char *str);
void	create_stack(t_stacks *stacks, char **argv, int argc);
void	print_stack(t_stacks *stacks);
void	invalid_stack(t_stacks *stacks);
void	clean_exit(t_stacks *stacks);
void	sort_stack(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	print_out(char *str);
void	rank_values(t_stacks *stacks);

#endif