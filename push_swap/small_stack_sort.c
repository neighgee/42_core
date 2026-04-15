/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:32:55 by mwin              #+#    #+#             */
/*   Updated: 2025/09/08 17:30:18 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_nbr_sort(t_stack *a)
{
	int	one;
	int	two;
	int	three;

	one = a->top_node->rank;
	two = a->top_node->next_node->rank;
	three = a->top_node->next_node->next_node->rank;
	if (if_sorted(a))
		return ;
	if (one > two && two < three && one < three)
		sa(a);
	else if (one > two && two > three)
	{
		sa(a);
		rra(a);
	}
	else if (one > two && two < three && one > three)
		ra(a);
	else if (one < two && two > three && one < three)
	{
		sa(a);
		ra(a);
	}
	else if (one < two && two > three && one > three)
		rra(a);
}

void	four_nbr_sort(t_stack *a, t_stack *b)
{
	if (if_sorted(a))
		return ;
	while (a->top_node->rank != 0)
		ra(a);
	pb(a, b);
	three_nbr_sort(a);
	pa(a, b);
}

void	five_nbr_sort(t_stack *a, t_stack *b)
{
	if (if_sorted(a))
		return ;
	while (b->n_nodes < 2)
	{
		if (a->top_node->rank == 0 || a->top_node->rank == 1)
			pb(a, b);
		else
			ra(a);
	}
	three_nbr_sort(a);
	if (b->top_node->rank < b->top_node->next_node->rank)
		sb(b);
	pa(a, b);
	pa(a, b);
}
