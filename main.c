/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:40:12 by yartym            #+#    #+#             */
/*   Updated: 2026/02/12 08:57:21 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	printf("%d\n", ac);
	t_number	*stack_a;
	t_number	*stack_b;

	stack_a = init_stack(ac, av);
	stack_b = search_push(stack_a, ac - 1);

	// sort them and return char ** of operationsd
		//look for the clothest number in range reverse or rotate
			//go in a direction
			//push to stack_b
		//
	// combine operations
	// print operations
	for (int i = 0; i < ac - 1; i++)
		printf("%d\n", stack_b[i].number);
	return(free(stack_a), free(stack_b), 0);
}
