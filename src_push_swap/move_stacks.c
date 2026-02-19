/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:58:09 by yartym            #+#    #+#             */
/*   Updated: 2026/02/17 09:07:07 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_a_only(t_number *stack, int size, t_number *target)
{
	int	moves;

	moves = target->moves_a;
	if (moves > 0)
	{
		rotate_or_reverse(stack, size, "ra\n");
		moves--;
	}
	else if (moves < 0)
	{
		rotate_or_reverse(stack, size, "rra\n");
		moves++;
	}
	target->moves_a = moves;
}

static void	stack_b_only(t_number *stack, int size, t_number *target)
{
	int	moves;

	moves = target->moves_b;
	if (moves > 0)
	{
		rotate_or_reverse(stack, size, "rb\n");
		moves--;
	}
	else if (moves < 0)
	{
		rotate_or_reverse(stack, size, "rrb\n");
		moves++;
	}
	target->moves_b = moves;
}

static int	target_index(t_number *stack, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (stack[i].target)
			return (i);
	return (-1);
}

void	move_stacks(t_number *st_a, t_number *st_b, int s_a, int s_b)
{
	t_number	target;
	int			i;

	i = target_index(st_b, s_b);
	target = st_b[i];
	while (target.moves_a != 0 || target.moves_b != 0)
	{
		if (target.moves_a < 0 && target.moves_b < 0)
		{
			rrr(st_a, st_b, s_a, s_b);
			target.moves_a++;
			target.moves_b++;
		}
		else if (target.moves_a > 0 && target.moves_b > 0)
		{
			rr(st_a, st_b, s_a, s_b);
			target.moves_a--;
			target.moves_b--;
		}
		else
		{
			stack_a_only(st_a, s_a, &target);
			stack_b_only(st_b, s_b, &target);
		}
	}
}
