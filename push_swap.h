/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:18:33 by lkonttin          #+#    #+#             */
/*   Updated: 2023/12/29 16:27:31 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct element
{
	int	value;
	int	rank;

}	t_elem;

int		ft_atoi(const char *str);
int		create_stack(t_elem **stack, char **argv, int argc);
void	print_stack(t_elem **stack, int size);
int		invalid_stack(t_elem **stack, int size);
void	clean_exit(t_elem **a_stack, t_elem **b_stack, int err);
void	sort_stack(t_elem **a_stack, t_elem **b_stack, int size);
void	sort_three(t_elem **a_stack, int size);
void	print_operation(char *operation);

#endif