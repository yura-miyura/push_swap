/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:08:55 by yartym            #+#    #+#             */
/*   Updated: 2026/02/16 23:40:15 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_or_reverse(t_number *stack, int size, char *move);

void	rb(t_number *stack_b, int size_b)
{
	rotate(stack_b, size_b);
	ft_putstr_fd("rb\n", 1);
}

void	rrb(t_number *stack_b, int size_b)
{
	reverse_rotate(stack_b, size_b);
	ft_putstr_fd("rrb\n", 1);
}

void	ra(t_number *stack_a, int size_a)
{
	rotate(stack_a, size_a);
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_number *stack_a, int size_a)
{
	reverse_rotate(stack_a, size_a);
	ft_putstr_fd("rra\n", 1);
}

void	pb(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b)
{
	push(stack_a, stack_b, size_a, size_b);
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_number *stack_a, t_number *stack_b, int *size_a, int *size_b)
{
	push(stack_b, stack_a, size_b, size_a);
	ft_putstr_fd("pa\n", 1);
}

void	rrr(t_number *stack_a, t_number *stack_b, int size_a, int size_b)
{
	reverse_rotate(stack_a, size_a);
	reverse_rotate(stack_b, size_b);
	ft_putstr_fd("rrr\n", 1);
}

void	rr(t_number *stack_a, t_number *stack_b, int size_a, int size_b)
{
	rotate(stack_a, size_a);
	rotate(stack_b, size_b);
	ft_putstr_fd("rr\n", 1);
}
