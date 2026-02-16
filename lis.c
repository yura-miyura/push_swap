/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:00:14 by yartym            #+#    #+#             */
/*   Updated: 2026/02/15 08:53:38 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_lis(int	size)
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

// create 0 1 array of numbers, another function will take my array of numbers and my array of 01 and pushing all the numbers with coresponding 0 to stackb leaving lis numbers intackt in stacka:

void	longest_increasing_subsequence(t_number *stack, int size)
{
	int	*lis;
	int	i;
	int	j;

	lis = init_lis(size);
	if (!lis)
		return ;
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
	i = -1;
	j = 0;
	while (++i < size)
		if (lis[i] > j)
			j = lis[i];
	i = size - 1;
	while (i >= 0)
	{
		if (lis[i] == j)
		{
			stack[i].lis = 1;
			j--;
		}
		i--;
	}
	free(lis);
}

int	a_only_with_lis(t_number *stack_a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a)
		if (!stack_a[i++].lis)
			return (0);
	return (1);
}

int moves_to_none_lis(t_number *stack, int size)
{
	int	reverse;
	int	rotate;

	reverse = size - 1;
	rotate = 0;
	if (!stack[0].lis)
		return (0);
	while (stack[rotate].lis)
		rotate++;
	while (stack[reverse].lis)
		reverse--;
	if (rotate < size - reverse)
		return (rotate);
	else
	 	return ((size  - reverse) * (-1));
}

void	sort_lis(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b)
{
	longest_increasing_subsequence(stack_a, *size_a);
	int	moves;

	while (!a_only_with_lis(stack_a, *size_a))
	{
		moves = moves_to_none_lis(stack_a, *size_a);
		while (moves != 0)
		{
			if (moves > 0)
			{
				ra(stack_a, *size_a);
				moves--;
			}
			else if (moves < 0)
			{
				rra(stack_a, *size_a);
				moves++;
			}
		}
		pb(stack_a, stack_b, size_a, size_b);
	}
}


