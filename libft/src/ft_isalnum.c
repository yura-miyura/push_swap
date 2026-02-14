/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:47:30 by yartym            #+#    #+#             */
/*   Updated: 2026/01/11 22:36:16 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks for an alphanumeric character.
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
