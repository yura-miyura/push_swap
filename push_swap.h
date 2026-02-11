/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:12:46 by yartym            #+#    #+#             */
/*   Updated: 2026/02/11 20:09:07 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/includes/libft.h"

# define GROUP_SIZE 5

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

int			swap(t_number *stack, int size);
int		push(int *from, int *to, int *s_from, int *s_to);
int		rotate(int *stack, int size);
int		reverse_rotate(int *stack, int size);

#endif
