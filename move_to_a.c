/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:49:21 by yartym            #+#    #+#             */
/*   Updated: 2026/02/16 23:38:19 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max_val(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

int abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	count_moves(int a, int b)
{
	if ((a >= 0 && b >=0) || (a < 0 && b < 0))
		return (max_val(abs_val(a), abs_val(b)));
	return (abs_val(a) + abs_val(b));
}

void	stack_a_only(t_number *stack, int size, t_number *target)
{
	int	moves;

	moves = target->moves_a;
	if (moves > 0)
	{
		ra(stack, size);
		moves--;
	}
	else if (moves < 0)
	{
		rra(stack, size);
		moves++;
	}
	target->moves_a = moves;
}

void	stack_b_only(t_number *stack, int size, t_number *target)
{
	int	moves;

	moves = target->moves_b;
	if (moves > 0)
	{
		rb(stack, size);
		moves--;
	}
	else if (moves < 0)
	{
		rrb(stack, size);
		moves++;
	}
	target->moves_b = moves;
}

int	target_index(t_number *stack, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (stack[i].target)
			return (i);
	return (-1);
}

void move_stacks(t_number *stack_a, t_number *stack_b, int size_a, int size_b)
{
	t_number	target;
	int			i;

	i = target_index(stack_b, size_b);
	target = stack_b[i];
	while (target.moves_a != 0 || target.moves_b != 0)
	{
		if (target.moves_a < 0 && target.moves_b < 0)
		{
			rrr(stack_a, stack_b, size_a, size_b);
			target.moves_a++;
			target.moves_b++;
		}
		else if (target.moves_a < 0 && target.moves_b < 0)
		{
			rr(stack_a, stack_b, size_a, size_b);
			target.moves_a--;
			target.moves_b--;
		}
		else
		{
			stack_a_only(stack_a, size_a, &target);
			stack_b_only(stack_b, size_b, &target);
		}
	}
}

void	put_b_in_a(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b)
{
	while (*size_b != 0)
	{
		recalc(stack_a, stack_b, *size_a, *size_b);
		best_target(stack_b, *size_b);
		move_stacks(stack_a, stack_b, *size_a, *size_b);
		pa(stack_a, stack_b, size_a, size_b);
	}
}
