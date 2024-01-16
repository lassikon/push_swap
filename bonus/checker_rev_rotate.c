/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rev_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:27:57 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/16 12:29:20 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_rev_rotate_a(t_stacks *s)
{
	s->a_top = prev_a_elem(s, s->a_top);
}

void	checker_rev_rotate_b(t_stacks *s)
{
	s->b_top = prev_b_elem(s, s->b_top);
}

void	checker_rev_rotate_ab(t_stacks *s)
{
	s->a_top = prev_a_elem(s, s->a_top);
	s->b_top = prev_b_elem(s, s->b_top);
}