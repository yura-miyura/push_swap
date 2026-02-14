/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:00:14 by yartym            #+#    #+#             */
/*   Updated: 2026/02/14 15:18:20 by yartym           ###   ########.fr       */
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
