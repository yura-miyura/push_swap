/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:32:43 by yartym            #+#    #+#             */
/*   Updated: 2026/02/09 15:43:37 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int *put_nbr_in_array(int ac, char **av)
{
	int	*numbers;
	int	i;

	number = malloc(sizeof (int) * (ac - 1));
	if (!numbers)
		return (NULL);
	i = 0;
	while (++i < ac)
		numbers[i - 1] = ft_atoi(av[i])
	return (numbers);
}

// TODO
// sort numbers function
// check if argument is a number
