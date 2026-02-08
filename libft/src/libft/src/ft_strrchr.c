/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:36:26 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/11 22:41:34 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates character in string (last occurrence).
char	*ft_strrchr(const char *s, int c)
{
	char			*loc;
	unsigned char	cc;
	size_t			i;

	loc = (char *) s;
	cc = c;
	i = ft_strlen(loc) + 1;
	while (i > 0)
		if (*(loc + --i) == cc)
			return (loc + i);
	return (NULL);
}
