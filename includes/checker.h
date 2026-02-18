/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:08:20 by yartym            #+#    #+#             */
/*   Updated: 2026/02/18 12:38:16 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <errno.h>
# include "get_next_line.h"
# include "libft.h"
# include "push_swap.h"

void	apply_b(t_number *stack, int size, char *line);
void	apply_a(t_number *stack, int size, char *line);
void	ss(t_number *st_a, t_number *st_b, int s_a, int s_b);
void	rr(t_number *st_a, t_number *st_b, int s_a, int s_b);
void	rrr(t_number *st_a, t_number *st_b, int s_a, int s_b);
void	invalid(t_number *st_a, t_number *st_b);
int		is_apply_a(char *line);
int		is_apply_b(char *line);
int		stdin_operations(t_number *st_a, int s_a, t_number *st_b, char *line);

#endif
