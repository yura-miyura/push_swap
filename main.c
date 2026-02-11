/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:40:12 by yartym            #+#    #+#             */
/*   Updated: 2026/02/11 20:04:45 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_number	*stack_a;

	stack_a = init_stack(ac, av);
	// create stack_a with input values
		// create array with inputs and sort it to get index values +
		// create array of structs with number and it's index in input order
		// return

	// sort them and return char ** of operationsd
	// combine operations
	// print operations
	for (int i = 0; i < ac - 1; i++)
		printf("%d\n", stack_a[i].index);
	free(stack_a);
}
