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

int moves_to_position_in_a(t_number *stack, int size, int index)
{
	int	reverse;
	int	rotate;

	reverse = size;
	rotate = 0;
	if (stack[0].index > index && stack[size - 1].index < index)
		return (0);
	while (++rotate < size)
		if(stack[rotate].index > index && stack[rotate - 1].index < index)
			break ;
	while (--reverse > 0)
		if(stack[reverse].index > index && stack[reverse - 1].index < index)
			break ;
	if (rotate < size - reverse)
		return (rotate);
	else
		return ((size  - reverse) * (-1));
}

void	recalc_stack_b(t_number *stack_a, t_number *stack_b, int size_a, int size_b)
{
	int	i;

	i = 0;
	while (i < size_b)
	{
		stack_b[i].moves_a = moves_to_position_in_a(stack_a, size_a, stack_b[i].index);
		// stack_b[i].moves_b = i;
		if (i < size_b / 2)
			stack_b[i].moves_b = i;
		else
			stack_b[i].moves_b = (size_b - i) * (-1);
		i++;
	}
}

int find_the_best_deal(t_number *stack, int size)
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
	return (best_i);
}
