/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:52:07 by yartym            #+#    #+#             */
/*   Updated: 2026/02/18 12:29:46 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	apply_a(t_number *stack, int size, char *line)
{
	if (!ft_strncmp(line, "rra", 3))
		reverse_rotate(stack, size);
	else if (!ft_strncmp(line, "sa", 2))
		swap(stack, size);
	else if (!ft_strncmp(line, "ra", 2))
		rotate(stack, size);
}

void	apply_b(t_number *stack, int size, char *line)
{
	if (!ft_strncmp(line, "rrb", 3))
		reverse_rotate(stack, size);
	else if (!ft_strncmp(line, "sb", 2))
		swap(stack, size);
	else if (!ft_strncmp(line, "rb", 2))
		rotate(stack, size);
}

int	stdin_operations(t_number *st_a, int s_a, t_number *st_b, char *line)
{
	int	s_b;

	s_b = 0;
	while (line != NULL)
	{
		if (is_apply_a(line))
			apply_a(st_a, s_a, line);
		else if (is_apply_b(line))
			apply_b(st_b, s_b, line);
		else if (!ft_strncmp(line, "rrr", 3))
			rrr(st_a, st_b, s_a, s_b);
		else if (!ft_strncmp(line, "ss", 2))
			ss(st_a, st_b, s_a, s_b);
		else if (!ft_strncmp(line, "rr", 2))
			rr(st_a, st_b, s_a, s_b);
		else if (!ft_strncmp(line, "pb", 2))
			push(st_a, st_b, &s_a, &s_b);
		else if (!ft_strncmp(line, "pa", 2))
			push(st_b, st_a, &s_b, &s_a);
		else
			return (invalid(st_a, st_b, line), 0);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (1);
}

void	invalid(t_number *st_a, t_number *st_b, char *line)
{
	ft_putstr_fd("Error\n", 1);
	return (free(line), free(st_a), free(st_b));
}

int	main(int ac, char **av)
{
	t_number	*stack_a;
	t_number	*stack_b;
	int			size;
	char		*line;
	char		*message;

	if (ac == 1)
		return (0);
	stack_a = init_stack(ac, av);
	size = ac - 1;
	stack_b = malloc(sizeof(t_number) * size);
	line = get_next_line(STDIN_FILENO);
	if (!stdin_operations(stack_a, size, stack_b, line))
		return (1);
	if (errno != 0)
		return (invalid(stack_a, stack_b, line), 1);
	message = "OK\n";
	while (--size > 0)
		if (stack_a[size].number < stack_a[size - 1].number)
			message = "KO\n";
	ft_putstr_fd(message, 1);
	return (free(stack_a), free(stack_b), 0);
}
