/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:49:21 by yartym            #+#    #+#             */
/*   Updated: 2026/02/17 15:23:33 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_val(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	count_moves(int a, int b)
{
	if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
		return (max_val(abs_val(a), abs_val(b)));
	return (abs_val(a) + abs_val(b));
}

void	put_b_in_a(t_number *st_a, t_number *st_b, int *s_a, int *s_b)
{
	while (*s_b != 0)
	{
		recalc(st_a, st_b, *s_a, *s_b);
		best_target(st_b, *s_b);
		move_stacks(st_a, st_b, *s_a, *s_b);
		pa(st_a, st_b, s_a, s_b);
	}
}

void	sort_stack(t_number *st_a, t_number *st_b, int *s_a, int *s_b)
{
	sort_lis(st_a, st_b, s_a, s_b);
	put_b_in_a(st_a, st_b, s_a, s_b);
	get_smallest_first(st_a, *s_a);
}
