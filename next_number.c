/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:54:51 by yartym            #+#    #+#             */
/*   Updated: 2026/02/13 12:02:08 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
//
// int	number_in_range(int n, int index)
// {
// 	int	step;
//
// 	step = 0;
// 	while (index % RANGE_SIZE)
// 		index--;
// 	while (step < RANGE_SIZE - 1 && n != index + step)
// 		step++;
// 	return (n == index + step);
// }
//
// int moves_to_next_number(t_number *stack, int size, int index)
// {
// 	int	reverse;
// 	int	rotate;
//
// 	reverse = size;
// 	rotate = -1;
// 	if (number_in_range(stack[0].index, index))
// 		return (0);
// 	while (++rotate < size)
// 		if(number_in_range(stack[rotate].index, index))
// 			break ;
// 	while (--reverse > 0)
// 		if(number_in_range(stack[reverse].index, index))
// 			break ;
// 	if (rotate < size - reverse)
// 		return (rotate);
// 	else
// 	 	return ((size  - reverse) * (-1));
// }
//
// t_number	*search_push(t_number	*stack_a, int size)
// {
// 	int			i;
// 	int			a_size;
// 	int			b_size;
// 	int			moves;
// 	t_number	*stack_b;
//
//
// 	i = -1;
// 	a_size = size;
// 	b_size = 0;
// 	stack_b = malloc(sizeof (t_number) * size);
// 	while (++i < size)
// 	{
// 		moves = moves_to_next_number(stack_a, a_size, i);
// 		if (moves > 0)
// 		{
// 			while (moves--)
// 			{
// 				rotate(stack_a, a_size);
// 				write(1, "ra\n", 3);
// 			}
// 		}
// 		else if (moves < 0)
// 		{
// 		 	while (moves++ < 0)
// 			{
// 				reverse_rotate(stack_a, a_size);
// 				write(1, "rra\n", 4);
// 			}
//
// 		}
// 		push(stack_a, stack_b, &a_size, &b_size);
// 		write(1, "pa\n", 3);
// 	}
// 	return (stack_b);
// }
//
// int moves_tmp(t_number *stack, int size)
// {
// 	int	reverse;
// 	int	rotate;
//
// 	reverse = size - 1;
// 	rotate = 0;
// 	if (stack[0].index == size - 1)
// 		return (0);
// 	while (stack[rotate].index != size - 1)
// 		rotate++;
// 	while (stack[reverse].index != size - 1)
// 		reverse--;
// 	if (rotate < size - reverse)
// 		return (rotate);
// 	else
// 	 	return ((size  - reverse) * (-1));
// }
//
// void	search_push_to_a(t_number *stack_a, t_number *stack_b, int size)
// {
// 	int size_b;
// 	int size_a;
// 	int moves;
//
// 	size_b = size;
// 	size_a = 0;
// 	while (size_b > 0)
// 	{
// 		moves = moves_tmp(stack_b, size_b);
// 		if (moves > 0)
// 		{
// 			while (moves--)
// 			{
// 				rotate(stack_b, size_b);
// 				write(1, "rb\n", 3);
// 			}
// 		}
// 		else if (moves < 0)
// 		{
// 		 	while (moves++ < 0)
// 			{
// 				reverse_rotate(stack_b, size_b);
// 				write(1, "rrb\n", 4);
// 			}
// 		}
// 		push(stack_b, stack_a, &size_b, &size_a);
// 		write(1, "pb\n", 3);
// 	}
// }
