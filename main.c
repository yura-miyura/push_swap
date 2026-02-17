/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:40:12 by yartym            #+#    #+#             */
/*   Updated: 2026/02/17 09:12:11 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
