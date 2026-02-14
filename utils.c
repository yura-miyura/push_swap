/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:32:08 by yartym            #+#    #+#             */
/*   Updated: 2026/02/13 19:40:07 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	**init_stack(void)
{
	t_node **stack;

	stack = malloc(sizeof (t_node));
	if (!stack)
		return (NULL);
	*stack = NULL;
	return (stack);
}

void	put_input_in_stack(t_node	**stack, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
		node_add_back(stack, node_new(ft_atoi(av[i])));
}

void	iter_put_nb_free(t_node **stack)
{
	t_node *tmp;

	while (*stack)
	{
		printf("%d\n", (*stack)->nb);
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	free(stack);
}
