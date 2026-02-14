/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:39:11 by yartym            #+#    #+#             */
/*   Updated: 2026/02/13 19:38:58 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *node_new(int number)
{
	t_node *node;

	node = malloc(sizeof (t_list));
	if (!node)
		return (NULL);
	node->nb = number;
	node->i = -1;
	node->next = NULL;
	return (node);
}

t_node	*node_last(t_node *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

void	node_add_back(t_node **stack, t_node *new_node)
{
	t_node	*node;

	if (!*stack)
		*stack = new_node;
	else
	{
		node = node_last(*stack);
		node->next = new_node;
	}
}
