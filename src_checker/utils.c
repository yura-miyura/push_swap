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
	return (!ft_strncmp(line, "rra", 3)
		|| !ft_strncmp(line, "sa", 2)
		|| !ft_strncmp(line, "ra", 2));
}

int	is_apply_b(char *line)
{
	return (!ft_strncmp(line, "rrb", 3)
		|| !ft_strncmp(line, "sb", 2)
		|| !ft_strncmp(line, "rb", 2));
}
