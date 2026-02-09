/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:40:12 by yartym            #+#    #+#             */
/*   Updated: 2026/02/08 15:11:27 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	int	*numbers;
	t_stack *tmp;
	int		i;

	numbers = malloc(sizeof (int) * (ac - 1));
	stack_a = malloc(sizeof(t_stack));
	if (!numbers || !stack_a)
		return (NULL);
	i = 1;
	*stack_a = NULL;
	while (i < ac)
	{
		node_add_back(stack_a, node_new(ft_atoi(av[i]), i));
		i++;
	}
	while (*stack_a)
	{
		printf("%d\n", (*stack_a)->number);
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
	}
	free (stack_a);
}
