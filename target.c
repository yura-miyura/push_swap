/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:46:43 by yartym            #+#    #+#             */
/*   Updated: 2026/02/14 20:09:51 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_number(t_number *stack, int size)
{
	int s_i;
	int	i;

	i = 0;
	s_i = 0;
	while (++i < size)
		if (stack[i].number < stack[s_i].number)
			s_i = i;
	return (s_i);
}

int	target_position(t_number *stack, int size, int number)
{
	int	i;
	int	count;
	int min;

	count = -1;
	min = smallest_number(stack, size);
	i = min;
	while (++count < size)
	{
		if (stack[i].number > number)
			return (i);
		i++;
		if (i == size)
			i = 0;
	}
	return (min);
}

int moves_target(t_number *stack, int size, int number)
{
	int	target;

	target = target_position(stack, size, number);
	if (target <= size / 2)
		return (target);
	return (target - size);
}

void	recalc_stack(t_number *stack_a, t_number *stack_b, int size_a, int size_b)
{
	int	i;

	i = 0;
	while (i < size_b)
	{
		stack_b[i].moves_a = moves_target(stack_a, size_a, stack_b[i].number);
		if (i <= size_b / 2)
			stack_b[i].moves_b = i;
		else
			stack_b[i].moves_b = i - size_b;
		i++;
	}
}

void	best_target(t_number *stack, int size)
{
	int	i;
	int best_i;
	int	best;
	int	moves;

	i = 0;
	best_i = 0;
	best = count_moves(stack[i].moves_a, stack[i].moves_b);
	while (++i < size)
	{
		moves = count_moves(stack[i].moves_a, stack[i].moves_b);
		if (moves < best)
		{
			best = moves;
			best_i = i;
		}
	}
	stack[best_i].target = 1;
}
