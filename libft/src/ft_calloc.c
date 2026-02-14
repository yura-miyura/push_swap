/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 12:26:49 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/11 22:43:48 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory and sets its bytes' values to 0
void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	if ((size != 0 && count > (__SIZE_MAX__ / size)))
		return (NULL);
	memory = malloc(count * size);
	if (!memory)
	{
		free(memory);
		return (NULL);
	}
	ft_bzero(memory, count * size);
	return (memory);
}
