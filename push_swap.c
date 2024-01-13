/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:26:21 by lkonttin          #+#    #+#             */
/*   Updated: 2024/01/13 19:03:13 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	clean_exit(t_stacks *s, int error)
{
	if (s->a)
	{
		// s->a = NULL;
		free(s->a);
	}
	if (s->b)
	{
		// s->b = NULL;
		free(s->b);
	}
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	if (argc == 1)
		exit(0);
	allocate_stacks(&s, argc, argv);
	fill_stack_a(&s, argc, argv);
	rank_values(&s);
	check_if_already_sorted(&s);
	sort_stack(&s);
	// print_stack(&s);
	// fscanf(stdin, "c");
	clean_exit(&s, 0);
}
