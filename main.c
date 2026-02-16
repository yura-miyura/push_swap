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

void	sort_numbers(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b)
{
	int	j;
	int	n;

	sort_lis(stack_a, stack_b, size_a, size_b);
	put_b_in_a(stack_a, stack_b, size_a, size_b);
	n = stack_a[smallest_number(stack_a, *size_a)].number;
	j = target_position(stack_a, *size_a, n);
	if (j > 0)
		while (--j > 0)
			ra(stack_a, *size_a);
	else if (j < 0)
		while (--j < 0)
			rra(stack_a, *size_a);
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
	sort_numbers(stack_a, stack_b, &size_a, &size_b);
	for(int i = 0; i < size_a; i++)
		printf("%d - %d\n", stack_a[i].number, stack_a[i].lis);
	return(free(stack_a), free(stack_b), 0);
}
