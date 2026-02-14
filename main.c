/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:40:12 by yartym            #+#    #+#             */
/*   Updated: 2026/02/13 19:24:30 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	**stack_a;

	stack_a = init_stack();
	put_input_in_stack(stack_a, ac, av);
	iter_put_nb_free(stack_a);
}
