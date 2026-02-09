/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:23:19 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/11 22:41:17 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates character in string (first occurrence).
char	*ft_strchr(const char *s, int c)
{
	char			*loc;
	unsigned char	cc;

	loc = (char *) s;
	cc = c;
	while (*loc)
	{
		if (*loc == cc)
			return (loc);
		loc++;
	}
	if (*loc == cc)
		return (loc);
	return (NULL);
}
