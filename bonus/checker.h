/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:50:28 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/16 12:48:41 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

void	checker_swap_a(t_stacks *s);
void	checker_swap_b(t_stacks *s);
void	checker_swap_ab(t_stacks *s);
void	checker_rotate_a(t_stacks *s);
void	checker_rotate_b(t_stacks *s);
void	checker_rotate_ab(t_stacks *s);
void	checker_rev_rotate_a(t_stacks *s);
void	checker_rev_rotate_b(t_stacks *s);
void	checker_rev_rotate_ab(t_stacks *s);
void	checker_push_a(t_stacks *s);
void	checker_push_b(t_stacks *s);

#endif
