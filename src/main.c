/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:40:12 by yartym            #+#    #+#             */
/*   Updated: 2026/02/17 15:25:51 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_number	*stack_a;
	t_number	*stack_b;
	int			size_a;
	int			size_b;

	stack_a = init_stack(ac, av);
	stack_b = malloc(sizeof(t_number) * ac - 1);
	size_a = ac - 1;
	size_b = 0;
	if (!stack_a || !stack_b)
		return (1);
	if (ac <= 4)
		sort_three(stack_a, size_a);
	else if (ac <= 6)
		sort_four_five(stack_a, stack_b, &size_a, &size_b);
	else
		sort_stack(stack_a, stack_b, &size_a, &size_b);
	return (free(stack_a), free(stack_b), 0);
}
