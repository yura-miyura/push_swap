/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:33:59 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/11 22:38:30 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies memory area.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp;

	if (!dst && !src)
		return (NULL);
	dst_tmp = dst;
	src_tmp = src;
	while (n--)
		*dst_tmp++ = *src_tmp++;
	return (dst);
}
