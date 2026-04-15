/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:09:20 by mwin              #+#    #+#             */
/*   Updated: 2025/09/13 18:42:34 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_bits(t_stack *a)
{
	int		max;
	int		max_bits;
	t_node	*temp;

	if (!a || a->n_nodes <= 1)
		return (0);
	max = 0;
	max_bits = 0;
	temp = a->top_node;
	while (temp)
	{
		if (temp->rank > max)
			max = temp->rank;
		temp = temp->next_node;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	n;
	int	max_bits;
	int	bits;
	int	i;

	if (!a || a->n_nodes <= 1 || if_sorted(a))
		return ;
	n = a->n_nodes;
	max_bits = find_max_bits(a);
	bits = 0;
	while (bits < max_bits)
	{
		i = 0;
		while (i < n)
		{
			if (((a->top_node->rank >> bits) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (b->n_nodes > 0)
			pa(a, b);
		bits++;
	}
}
