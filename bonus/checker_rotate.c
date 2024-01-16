/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:53:54 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/16 12:29:33 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_rotate_a(t_stacks *s)
{
	s->a_top = next_a_elem(s, s->a_top);
}

void	checker_rotate_b(t_stacks *s)
{
	s->b_top = next_b_elem(s, s->b_top);
}

void	checker_rotate_ab(t_stacks *s)
{
	s->a_top = next_a_elem(s, s->a_top);
	s->b_top = next_b_elem(s, s->b_top);
}