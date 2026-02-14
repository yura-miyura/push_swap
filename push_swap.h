/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:12:46 by yartym            #+#    #+#             */
/*   Updated: 2026/02/13 19:38:16 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/includes/libft.h"

# define RANGE_SIZE

typedef struct s_node
{
	int	nb;
	int	i;
	struct s_node *next;
}				t_node;

// lst.c

t_node	*node_new(int number);
void	node_add_back(t_node **stack, t_node *new_node);
t_node	*node_last(t_node *node);

t_node	**init_stack(void);
void	put_input_in_stack(t_node	**stack, int ac, char **av);


void	iter_put_nb_free(t_node **stack);

#endif
