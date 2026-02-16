/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:12:46 by yartym            #+#    #+#             */
/*   Updated: 2026/02/15 07:53:09 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/includes/libft.h"


typedef struct s_number
{
	int	number;
	int	lis;
	int	moves_a;
	int	moves_b;
}				t_number;

int			*put_nbr_in_array(int ac, char **av);
int			valid_arg(char *arg, int (*f)(int));
t_number	*init_stack(int ac, char **av);

void		search_push_to_a(t_number *stack_a, t_number *stack_b, int size);

int			swap(t_number *stack, int size);
int			push(t_number *from, t_number *to, int *s_from, int *s_to);
int			rotate(t_number	*stack, int size);
int			reverse_rotate(t_number *stack, int size);

void		ra(t_number *stack_a, int size_a);
void		rra(t_number *stack_a, int size_a);
void		pb(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b);
void		pa(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b);
void		rr(t_number *stack_a, t_number *stack_b, int size_a, int size_b);
void		rrr(t_number *stack_a, t_number *stack_b, int size_a, int size_b);
void		rrb(t_number *stack_b, int size_b);
void		rb(t_number *stack_b, int size_b);

// lis
void		sort_lis(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b);
int			longest_increasing_subsequence(t_number *stack, int size);
int			*init_lis(int	size);

// count
void		recalc_stack_b(t_number *stack_a, t_number *stack_b, int size_a, int size_b);
int			moves_to_position_in_a(t_number *stack, int size, int index);
int			find_the_best_deal(t_number *stack, int size);

int			max_val(int a, int b);
int			abs_val(int n);
int			count_moves(int a, int b);
void		put_b_in_a(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b);

int			smallest_number(t_number *stack, int size);
int			target_position(t_number *stack, int size, int number);

void		sort_numbers(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b);

#endif
