/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:00:56 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/11 22:47:51 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes and frees the given element and every successor.
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		del((*lst)->content);
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
