/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:35:25 by mwin              #+#    #+#             */
/*   Updated: 2025/09/13 18:43:28 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_stack(t_stack *stack)
{
	stack->top_node = NULL;
	stack->n_nodes = 0;
}

int	store_order_inputs(t_stack *stack, int data)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (error_msg(), 0);
	new_node->data = data;
	new_node->rank = -1;
	new_node->next_node = NULL;
	if (!stack->top_node)
		stack->top_node = new_node;
	else
	{
		temp = stack->top_node;
		while (temp->next_node)
			temp = temp->next_node;
		temp->next_node = new_node;
	}
	stack->n_nodes++;
	return (1);
}

int	if_sorted(t_stack *a)
{
	t_node	*temp;
	int		sorted;

	if (!a || a->n_nodes <= 1)
		return (1);
	temp = a->top_node;
	sorted = 1;
	while (temp && temp->next_node)
	{
		if (temp->rank > temp->next_node->rank)
		{
			sorted = 0;
			break ;
		}
		temp = temp->next_node;
	}
	return (sorted);
}
