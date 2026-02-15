/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_p_r_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:16:59 by yartym            #+#    #+#             */
/*   Updated: 2026/02/14 20:03:20 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_number *stack, int size)
{
	t_number	tmp;

	if (size > 1)
	{
		tmp = *stack;
		*stack = *(stack + 1);
		*(stack + 1) = tmp;
		return (1);
	}
	return (0);
}

int	push(t_number *from, t_number *to, int *s_from, int *s_to)
{
	if (*s_from && from && to)
	{
		ft_memmove(to + 1, to, sizeof (t_number) * (*s_to)++);
		*to = *from;
		ft_memmove(from, from + 1, sizeof (t_number) * --(*s_from));
		return (1);
	}
	return (0);
}

int	rotate(t_number	*stack, int size)
{
	t_number	tmp;

	if (stack && size > 1)
	{
		tmp = *(stack);
		ft_memmove(stack, stack + 1, sizeof (t_number) * (size - 1));
		*(stack + size - 1) = tmp;
		return (1);
	}
	return (0);
}

int	reverse_rotate(t_number *stack, int size)
{
	t_number	tmp;

	if (stack && size > 1)
	{
		tmp = *(stack + size - 1);
		ft_memmove(stack + 1, stack, sizeof (t_number) * (size - 1));
		*stack = tmp;
		return (1);
	}
	return (0);
}

void	rb(t_number *stack_b, int size_b)
{
	rotate(stack_b, size_b);
	ft_putstr_fd("rb\n", 1);
}

void	rrb(t_number *stack_b, int size_b)
{
	rotate(stack_b, size_b);
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
