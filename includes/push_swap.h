/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:12:46 by yartym            #+#    #+#             */
/*   Updated: 2026/02/17 15:23:06 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_number
{
	int	number;
	int	lis;
	int	moves_a;
	int	moves_b;
	int	target;
}				t_number;

void		get_smallest_first(t_number *stack, int size);
void		sort_three(t_number *stack, int size);
void		sort_four_five(t_number *st_a, t_number *st_b, int *s_a, int *s_b);

int			is_sorted(t_number *stack, int size);
int			no_dublicates(int *number, int size);
int			*put_nbr_in_array(int ac, char **av);
int			valid_arg(char *arg, int (*f)(int));
t_number	*init_stack(int ac, char **av);

void		search_push_to_a(t_number *stack_a, t_number *stack_b, int size);

int			swap(t_number *stack, int size);
int			push(t_number *from, t_number *to, int *s_from, int *s_to);
int			rotate(t_number	*stack, int size);
int			reverse_rotate(t_number *stack, int size);

void		pb(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b);
void		pa(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b);
void		rr(t_number *stack_a, t_number *stack_b, int size_a, int size_b);
void		rrr(t_number *stack_a, t_number *stack_b, int size_a, int size_b);
void		rotate_or_reverse(t_number *stack, int size, char *move);

// lis
void		sort_lis(t_number *stack_a, t_number *stack_b, int *s_a, int *s_b);
int			longest_increasing_subsequence(t_number *stack, int size);
int			*init_lis(int size);

// count
int			smallest_number(t_number *stack, int size);
int			target_position(t_number *stack, int size, int number);
void		recalc(t_number *stack_a, t_number *stack_b, int s_a, int s_b);
int			moves_target(t_number *stack, int size, int number);
void		best_target(t_number *stack, int size);

void		move_stacks(t_number *st_a, t_number *st_b, int s_a, int s_b);

int			count_moves(int a, int b);
void		put_b_in_a(t_number *st_a, t_number *st_b, int *s_a, int *s_b);
void		sort_stack(t_number *st_a, t_number *st_b, int *s_a, int *s_b);
#endif
