/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:26:21 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/19 11:52:23 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	s;

	if (argc == 1)
		exit(0);
	if (*argv[1] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	s.checker = 0;
	allocate_stacks(&s, argc, argv);
	fill_stack_a(&s, argc, argv);
	rank_values(&s);
	check_if_already_sorted(&s);
	sort_stack(&s);
	clean_exit(&s, 0);
}
