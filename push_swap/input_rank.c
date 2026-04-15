/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:39:34 by mwin              #+#    #+#             */
/*   Updated: 2025/09/12 09:40:09 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_rank(int *array, int n, t_stack *stack)
{
	int		i;
	t_node	*temp;

	temp = stack->top_node;
	while (temp)
	{
		i = 0;
		while (i < n)
		{
			if (temp->data == array[i])
			{
				temp->rank = i;
				break ;
			}
			i++;
		}
		temp = temp->next_node;
	}
}

static void	sort_array(int *array, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < (n - 1))
	{
		j = 0;
		while (j < (n - 1))
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	rank_array(t_stack *stack)
{
	int		*array;
	int		n;
	int		i;
	t_node	*temp;

	n = stack->n_nodes;
	array = malloc(sizeof(int) * n);
	i = 0;
	if (!array)
		return ;
	temp = stack->top_node;
	while (temp)
	{
		array[i++] = temp->data;
		temp = temp->next_node;
	}
	sort_array(array, n);
	find_rank(array, n, stack);
	free(array);
}
