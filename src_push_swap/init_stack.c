/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:08:30 by yartym            #+#    #+#             */
/*   Updated: 2026/02/18 12:37:49 by yartym           ###   ########.fr       */
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

int	no_dublicates(int *number, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (++j < size)
			if (number[j] == number[i])
				return (0);
		i++;
	}
	return (1);
}

int	valid_arg(char *arg, int (*f)(int))
{
	if (!*arg)
		return (0);
	if (*arg == '-')
		arg++;
	while (*arg)
		if (!(*f)(*(arg++)))
			return (0);
	return (1);
}

t_number	*init_stack(int ac, char **av)
{
	int			*stack;
	t_number	*numbers;
	int			i;

	stack = put_nbr_in_array(ac, av);
	if (!no_dublicates(stack, ac - 1))
	{
		free(stack);
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	numbers = malloc(sizeof (t_number) * ac - 1);
	if (!stack || !numbers)
		return (NULL);
	i = -1;
	while (++i < ac - 1)
	{
		numbers[i].number = stack[i];
		numbers[i].lis = 0;
		numbers[i].target = 0;
	}
	return (free(stack), numbers);
}
