/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:29:25 by mwin              #+#    #+#             */
/*   Updated: 2025/09/13 19:37:32 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_input(int *input_array, int *count, char *argv)
{
	int	number;

	if (!check_number(argv))
		return (0);
	if (check_overflow(argv))
		return (0);
	number = ft_atoi(argv);
	if (check_duplicate(input_array, *count, number))
		return (0);
	input_array[(*count)++] = number;
	return (1);
}

static int	split_argv(char *argv, int **input_array, int *count)
{
	char	**split;
	int		j;

	j = 0;
	split = ft_split(argv, ' ');
	if (!split)
		return (error_msg(), 0);
	if (!split[0])
	{
		free(split);
		return (error_msg(), 0);
	}
	while (split[j])
	{
		if (!validate_input(*input_array, count, split[j]))
		{
			free_split(split);
			return (0);
		}
		j++;
	}
	free_split(split);
	return (1);
}

static int	store_inputs(t_stack *stack, int *input_array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!store_order_inputs(stack, input_array[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_store_args(int argc, char *argv[], t_stack *stack)
{
	int		*input_array;
	int		count;
	int		i;

	i = 1;
	count = 0;
	input_array = malloc(sizeof(int) * 10000);
	if (!input_array)
		return (error_msg(), 0);
	while (i < argc)
	{
		if (!split_argv(argv[i], &input_array, &count))
			return (free(input_array), free_stack(stack), 0);
		i++;
	}
	if (!store_inputs(stack, input_array, count))
		return (free(input_array), free_stack(stack), 0);
	free(input_array);
	return (1);
}
