/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:28:22 by yartym            #+#    #+#             */
/*   Updated: 2026/01/11 22:38:58 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies string to a specific size.
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	i = -1;
	src_size = 0;
	while (src[src_size])
		src_size++;
	if (size == 0)
		return (src_size);
	while (++i < size - 1 && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (src_size);
}
