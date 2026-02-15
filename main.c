/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:40:12 by yartym            #+#    #+#             */
/*   Updated: 2026/02/15 08:48:37 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int moves_to_get(t_number *stack, int size, int i)
{
	int	reverse;
	int	rotate;

	reverse = size - 1;
	rotate = 0;
	if (stack[0].index == i)
		return (0);
	while (stack[rotate].index != i)
		rotate++;
	while (stack[reverse].index != i)
		reverse--;
	if (rotate < size - reverse)
		return (rotate);
	else
	 	return ((size  - reverse) * (-1));
}

int	main(int ac, char **av)
{
	t_number	*stack_a;
	t_number	*stack_b;
	int	size_a;
	int size_b;

	size_a = ac - 1;
	size_b = 0;
	stack_a = init_stack(ac, av);
	stack_b = malloc(sizeof(t_number) * ac -1);
	sort_lis(stack_a, stack_b, &size_a, &size_b);
	put_b_in_a(stack_a, stack_b, &size_a, &size_b);
	// int j = moves_to_get(stack_a, size_a, 0);
	// if (j > 0)
	// 	while (j-- > 0)
	// 		ra(stack_a, size_a);
	// if (j < 0)
	// 	while (j++ < 0)
	// 		rra(stack_a, size_a);
	for(int i = 0; i < size_a; i++)
		printf("%d - %d\n", stack_a[i].index, stack_a[i].lis);
	return(free(stack_a), free(stack_b), 0);
}
