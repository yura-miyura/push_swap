/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:12:46 by yartym            #+#    #+#             */
/*   Updated: 2026/02/09 15:42:08 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/includes/libft.h"

typedef struct s_stack
{
	int				number;
	unsigned int	index;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;


t_stack	*node_new(int content, int index);
t_stack	*node_last(t_stack	*lst);
void	node_add_back(t_stack **lst, t_stack *new);
int		*put_nbr_in_array(int ac, char **av)


#endif
