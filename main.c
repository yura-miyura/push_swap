/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:40:12 by yartym            #+#    #+#             */
/*   Updated: 2026/02/11 08:52:03 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	// int	*stack_a;
	// int	*stack_b;
	int		*tmp;

	tmp = buble_sort(put_nbr_in_array(ac, av), ac - 1);

	for (int i = 0; i < ac - 1; i++)
		printf("%d\n", tmp[i]);
	free(tmp);
}
