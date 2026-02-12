/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:54:51 by yartym            #+#    #+#             */
/*   Updated: 2026/02/12 10:13:16 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_in_range(int n, int index)
{
	int	step;

	step = 0;
	while (index % RANGE_SIZE)
		index--;
	while (step < RANGE_SIZE - 1 && n != index + step)
		step++;
	return (n == index + step);
}

int moves_to_next_number(t_number *stack, int size, int index)
{
	int	reverse;
	int	rotate;

	reverse = size;
	rotate = -1;
	if (stack[0].index == index)
		return (0);
	while (++rotate < size)
		if(number_in_range(stack[rotate].index, index))
			break ;
	while (--reverse > 0)
		if(number_in_range(stack[reverse].index, index))
			break ;
	if (rotate < size - reverse)
		return (rotate);
	else
	 	return ((size  - reverse) * (-1));
}

t_number	*search_push(t_number	*stack_a, int size)
{
	int			i;
	int			a_size;
	int			b_size;
	int			moves;
	t_number	*stack_b;


	i = -1;
	a_size = size;
	b_size = 0;
	stack_b = malloc(sizeof (t_number) * size);
	while (++i < size)
	{
		moves = moves_to_next_number(stack_a, size, i);
		if (moves > 0)
			while (moves--)
				rotate(stack_a, a_size);
		else if (moves < 0)
		 	while (moves++ < 0)
				reverse_rotate(stack_a, a_size);
		push(stack_a, stack_b, &a_size, &b_size);
	}
	return (stack_b);
}
