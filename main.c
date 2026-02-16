/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:40:12 by yartym            #+#    #+#             */
/*   Updated: 2026/02/16 23:48:39 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_number *st_a, t_number *st_b, int *s_a, int *s_b)
{
	int	n;

	sort_lis(st_a, st_b, s_a, s_b);
	put_b_in_a(st_a, st_b, s_a, s_b);
	n = smallest_number(st_a, *s_a);
	if (n <= (*s_a) / 2)
		while (n-- > 0)
			ra(st_a, *s_a);
	else
		while (n++ - *s_a != 0)
			rra(st_a, *s_a);
}

int	main(int ac, char **av)
{
	t_number	*stack_a;
	t_number	*stack_b;
	int			size_a;
	int			size_b;
	int			size;

	size = ac - 1;
	size_a = size;
	size_b = 0;
	stack_a = init_stack(ac, av);
	stack_b = malloc(sizeof(t_number) * size);
	if (!stack_a || !stack_b)
		return (1);
	sort_stack(stack_a, stack_b, &size_a, &size_b);
	// for(int i = 0; i < size_a; i++)
	// 	printf("%d - %d\n", stack_a[i].number, stack_a[i].lis);
	return (free(stack_a), free(stack_b), 0);
}
