/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:54:45 by mwin              #+#    #+#             */
/*   Updated: 2025/09/13 18:43:14 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nbr(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	error_msg(void)
{
	write(2, "Error\n", 6);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	while (stack->top_node)
	{
		temp = stack->top_node;
		stack->top_node = stack->top_node->next_node;
		free(temp);
	}
	stack->n_nodes = 0;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	check_stack_size_sort(t_stack *a, t_stack *b)
{
	if (a->n_nodes == 2)
	{
		if (if_sorted(a))
			return ;
		else
			ra(a);
	}
	else if (a->n_nodes == 3)
		three_nbr_sort(a);
	else if (a->n_nodes == 4)
		four_nbr_sort(a, b);
	else if (a->n_nodes == 5)
		five_nbr_sort(a, b);
	else
		radix_sort(a, b);
}
