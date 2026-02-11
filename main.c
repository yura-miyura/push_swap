/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:40:12 by yartym            #+#    #+#             */
/*   Updated: 2026/02/11 09:16:39 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	// t_stack	**stack_a;
	int	*numbers;
	int	*stack_b;
	// t_stack *tmp;
	// int		i;
	int size_a = ac - 1;
	int size_b = 0;
	stack_b = malloc(sizeof(int) * ac - 1);
	numbers = put_nbr_in_array(ac, av);
	push(numbers, stack_b, &size_a, &size_b);

	// numbers = buble_sort(put_nbr_in_array(ac, av), ac- 1);
	// stack_a = malloc(sizeof(t_stack));
	// if (!numbers || !stack_a)
	// 	return (NULL);
	// i = 1;
	// *stack_a = NULL;
	// while (i < ac)
	// {
	// 	node_add_back(stack_a, node_new(ft_atoi(av[i]), i));
	// 	i++;
	// }
	// while (*stack_a)
	// {
	// 	printf("%d\n", (*stack_a)->number);
	// 	tmp = (*stack_a)->next;
	// 	free(*stack_a);
	// 	*stack_a = tmp;
	// }
	// free (stack_a);
	for (int i = 0; i < size_b; i++)
		printf("%d\n", stack_b[i]);
	free(numbers);
}
