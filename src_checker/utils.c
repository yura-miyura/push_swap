/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:17:52 by yartym            #+#    #+#             */
/*   Updated: 2026/02/18 11:54:58 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_number *st_a, t_number *st_b, int s_a, int s_b)
{
	swap(st_a, s_a);
	swap(st_b, s_b);
}

void	rr(t_number *st_a, t_number *st_b, int s_a, int s_b)
{
	rotate(st_a, s_a);
	rotate(st_b, s_b);
}

void	rrr(t_number *st_a, t_number *st_b, int s_a, int s_b)
{
	reverse_rotate(st_a, s_a);
	reverse_rotate(st_b, s_b);
}

int	is_apply_a(char *line)
{
	return (!ft_strcmp(line, "rra\n")
		|| !ft_strcmp(line, "sa\n")
		|| !ft_strcmp(line, "ra\n"));
}

int	is_apply_b(char *line)
{
	return (!ft_strcmp(line, "rrb\n")
		|| !ft_strcmp(line, "sb\n")
		|| !ft_strcmp(line, "rb\n"));
}
