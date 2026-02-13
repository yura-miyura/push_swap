/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 08:39:08 by yartym            #+#    #+#             */
/*   Updated: 2026/02/13 09:35:54 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_output(char *output, char **operations)
{
	char *tmp;
	char *tmp2;

	if (!*operations)
		*operations = ft_strdup(output);
	else
	{
		tmp2 = ft_strjoin(",", output);
		tmp = ft_strjoin(*operations, tmp2);
		free(*operations);
		free(tmp2);
		*operations = tmp;
	}
}
