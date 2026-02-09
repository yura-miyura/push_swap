/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:17:00 by yartym            #+#    #+#             */
/*   Updated: 2026/02/08 16:22:15 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*node_new(int number, int index)
{
	t_stack	*node;

	node = malloc(sizeof (t_stack));
	if (!node)
		return (NULL);
	node->number = number;
	node->index = index;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

void	node_add_back(t_stack **lst, t_stack *new)
{
	t_stack *node;
	t_stack *previous;

	if (*lst == NULL)
		*lst = new;
	else
	{
		node = node_last(*lst);
		node->next = new;
		previous = node;
		node = node->next;
		node->previous = previous;
	}
}

t_stack	*node_last(t_stack	*lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

