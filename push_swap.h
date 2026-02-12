/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:12:46 by yartym            #+#    #+#             */
/*   Updated: 2026/02/12 10:15:44 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/includes/libft.h"

# define RANGE_SIZE 5

typedef struct s_number
{
	int	number;
	int	index;
}				t_number;

int			*put_nbr_in_array(int ac, char **av);
int			*bubble_sort(int *array, int size);
int			valid_arg(char *arg, int (*f)(int));
int			value_to_index(int *tmp, int n, int size);
t_number	*init_stack(int ac, char **av);

int			number_in_range(int n, int index);
int			moves_to_next_number(t_number *stack, int size, int index);
t_number	*search_push(t_number	*stack_a, int size);

int			swap(t_number *stack, int size);
int			push(t_number *from, t_number *to, int *s_from, int *s_to);
int			rotate(t_number	*stack, int size);
int			reverse_rotate(t_number *stack, int size);

#endif
