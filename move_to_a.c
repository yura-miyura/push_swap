/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:49:21 by yartym            #+#    #+#             */
/*   Updated: 2026/02/15 08:32:35 by yartym           ###   ########.fr       */
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

void	put_b_in_a(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b)
{
	int	i;
	int a;
	int b;
	while (*size_b != 0)
	{
		recalc_stack_b(stack_a, stack_b, *size_a, *size_b);
		i = find_the_best_deal(stack_b, *size_b);
		a = stack_b[i].moves_a;
		b = stack_b[i].moves_b;
		while (a != 0 || b != 0)
		{
			if (a < 0 && b < 0)
			{
				rrr(stack_a, stack_b, *size_a, *size_b);
				a++;
				b++;
			}
			else if(a > 0 && b > 0)
			{
				rr(stack_a, stack_b, *size_a, *size_b);
				a--;
				b--;
			}
			else
			{
				if (a > 0)
				{
					ra(stack_a, *size_a);
					a--;
				}
				else if (a < 0)
				{
					rra(stack_a, *size_a);
					a++;
				}
				if (b > 0)
				{
					rb(stack_b, *size_b);
					b--;

				}
				else if (b < 0)
				{
					rrb(stack_b, *size_b);
					b++;
				}
			}
		}
		pa(stack_a, stack_b, size_a, size_b);
	}
}
