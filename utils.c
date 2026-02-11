/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:32:43 by yartym            #+#    #+#             */
/*   Updated: 2026/02/11 09:01:16 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*put_nbr_in_array(int ac, char **av)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof (int) * (ac - 1));
	if (!numbers)
		return (0);
	i = 0;
	while (++i < ac)
	{
		if (!valid_arg(av[i], ft_isdigit))
		{
			free(numbers);
			ft_putstr_fd("Error\n", 1);
			exit(1);
		}
		numbers[i - 1] = ft_atoi(av[i]);
	}
	return (numbers);
}

int	valid_arg(char *arg, int (*f)(int))
{
	while (*arg)
		if (!(*f)(*(arg++)))
			return (0);
	return (1);
}

int *buble_sort(int *array, int size)
{
	int	i;
	int	swapped;

	i = 0;
	swapped = 0;
	if (!array)
		return (NULL);
	while(i < size)
	{
		if (swap(array + i++, size))
			swapped = 1;
		else if (swapped && i == size)
		{
			i = 0;
			swapped = 0;
		}
	}
	return (array);
}
