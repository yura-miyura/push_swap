/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:40:43 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/11 22:43:19 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates a substring in a string.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*trun_hay;

	if (!haystack && !len)
		return (NULL);
	trun_hay = (char *) haystack;
	i = 0;
	if (!needle[i])
		return (trun_hay);
	while (trun_hay[i] && i < len)
	{
		if (trun_hay[i] == *needle)
		{
			j = 0;
			while (trun_hay[i + j] && needle[j]
				&& trun_hay[i + j] == needle[j] && i + j < len)
				j++;
			if (!needle[j])
				return (trun_hay + i);
		}
		i++;
	}
	return (NULL);
}
