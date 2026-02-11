/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:16:59 by yartym            #+#    #+#             */
/*   Updated: 2026/02/11 09:11:22 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(int *stack, int size)
{
	int tmp;

	if (size > 1)
	{
		tmp = *stack;
		*stack = *(stack + 1);
		*(stack + 1) = tmp;
		return (1);
	}
	return (0);
}

int	push(int *from, int *to, int *s_from, int *s_to)
{
	if (*s_from && from && to)
	{
		ft_memmove(to + 1, to, sizeof (int) * (*s_to)++);
		*to = *from;
		ft_memmove(from, from + 1, sizeof (int) * --(*s_from));
		return (1);
	}
	return (0);
}

int	rotate(int *stack, int size)
{
	int	tmp;

	if (stack && size > 1)
	{
		tmp = *(stack + size - 1);
		ft_memmove(stack + 1, stack, sizeof (int) * (size - 1));
		*stack = tmp;
		return (1);
	}
	return (0);
}
