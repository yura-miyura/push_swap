/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:06:26 by yartym            #+#    #+#             */
/*   Updated: 2026/02/17 15:24:31 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_smallest_first(t_number *stack, int size)
{
	int	moves;

	moves = smallest_number(stack, size);
	if (moves > size/ 2)
		moves = (moves - size);
	while (moves)
	{
		if (moves > 0)
		{
			rotate_or_reverse(stack, size, "ra");
			moves--;
		}
		else
		{
			rotate_or_reverse(stack, size, "rra");
			moves++;
		}
	}
}


void	sort_three(t_number *stack, int size)
{
	while (!(stack[0].number < stack[1].number
			&& stack[1].number < stack[2].number))
	{
		if (stack[0].number > stack[1].number
			&& stack[2].number > stack[0].number)
		{
			swap(stack, size);
			ft_putstr_fd("sa\n", 1);
		}
		else if (stack[0].number > stack[1].number)
			rotate_or_reverse(stack, size, "ra");
		else if (stack[0].number < stack[1].number)
			rotate_or_reverse(stack, size, "rra");
	}
}

void	sort_four_five(t_number *st_a, t_number *st_b, int *s_a, int *s_b)
{
	while (*s_a > 3)
	{
		get_smallest_first(st_a, *s_a);
		pb(st_a, st_b, s_a, s_b);
	}
	sort_three(st_a, *s_a);
	while (*s_b)
		pa(st_a, st_b, s_a, s_b);
}
