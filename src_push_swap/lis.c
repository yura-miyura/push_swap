/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:00:14 by yartym            #+#    #+#             */
/*   Updated: 2026/02/17 15:19:09 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_lis(int size)
{
	int	*lis;
	int	i;

	lis = malloc(sizeof(int) * size);
	if (!lis)
		return (NULL);
	i = 0;
	while (i < size)
		lis[i++] = 1;
	return (lis);
}

static int	mark_lis(t_number *stack, int *lis, int size)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = 0;
	while (++i < size)
		if (lis[i] > j)
			j = lis[i];
	count = j;
	while (--i >= 0)
	{
		if (lis[i] == j)
		{
			stack[i].lis = 1;
			j--;
		}
	}
	return (free(lis), count);
}

int	longest_increasing_subsequence(t_number *stack, int size)
{
	int	*lis;
	int	i;
	int	j;

	lis = init_lis(size);
	if (!lis)
		return (-1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (stack[i].number > stack[j].number && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			j++;
		}
		i++;
	}
	return (mark_lis(stack, lis, size));
}

static int	next_number(t_number *stack, int size)
{
	int	reverse;
	int	rotate;
	int	i;

	rotate = 0;
	while (rotate < size && stack[rotate].lis)
		rotate++;
	reverse = size - 1;
	while (reverse > 0 && stack[reverse].lis)
		reverse--;
	if (rotate < (size - reverse))
		i = rotate;
	else
		i = reverse - size;
	return (i);
}

void	sort_lis(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b)
{
	int	lis;
	int	moves;

	lis = longest_increasing_subsequence(stack_a, *size_a);
	while (*size_a != lis)
	{
		moves = next_number(stack_a, *size_a);
		while (moves != 0)
		{
			if (moves > 0)
			{
				rotate_or_reverse(stack_a, *size_a, "ra\n");
				moves--;
			}
			else if (moves < 0)
			{
				rotate_or_reverse(stack_a, *size_a, "rra\n");
				moves++;
			}
		}
		pb(stack_a, stack_b, size_a, size_b);
	}
}
