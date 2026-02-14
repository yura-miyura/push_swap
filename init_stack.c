/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:08:30 by yartym            #+#    #+#             */
/*   Updated: 2026/02/14 13:56:54 by yartym           ###   ########.fr       */
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

int *bubble_sort(int *array, int size)
{
	int	i;
	int	swapped;
	int	tmp;

	i = 0;
	swapped = 0;
	if (!array)
		return (NULL);
	while(i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			swapped = 1;
		}
		if (++i == size - 1 && swapped)
		{
			i = 0;
			swapped = 0;
		}
	}
	return (array);
}

// Converts value to it's index in sorted array. Returns -1 on Error
int	value_to_index(int *tmp, int n, int size)
{
	int	i;

	i = -1;
	while(tmp && ++i < size)
		if (n == tmp[i])
			return (i);
	return (-1);
}

t_number *init_stack(int ac, char **av)
{
	int			*stack;
	int			*tmp;
	t_number	*numbers;
	int			i;


	tmp = bubble_sort(put_nbr_in_array(ac, av), ac -1);
	stack = put_nbr_in_array(ac, av);
	numbers = malloc(sizeof (t_number) * ac - 1);
	if (!stack || !numbers || !tmp)
		return (NULL);
	i = -1;
	while (++i < ac - 1)
	{
		numbers[i].number = stack[i];
		numbers[i].index = value_to_index(tmp, stack[i], ac - 1);
		numbers[i].lin = 0;
	}
	return (free(stack), free(tmp), numbers);
}
	int	moves;

