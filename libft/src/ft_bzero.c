/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:59:01 by yartym            #+#    #+#             */
/*   Updated: 2026/01/11 22:38:11 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Zeroes a byte string.
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) s;
	while (n-- > 0)
		*tmp++ = 0;
}
