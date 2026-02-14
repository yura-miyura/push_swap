/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:11:07 by yartym            #+#    #+#             */
/*   Updated: 2026/01/11 22:38:45 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies memory area (handles overlapping).
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_src = src;
	tmp_dest = dest;
	if (tmp_dest <= tmp_src)
		while (n--)
			*tmp_dest++ = *tmp_src++;
	else
	{
		tmp_dest += n;
		tmp_src += n;
		while (n--)
			*--tmp_dest = *--tmp_src;
	}
	return (dest);
}
