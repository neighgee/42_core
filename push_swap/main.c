/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:24:18 by mwin              #+#    #+#             */
/*   Updated: 2025/09/12 23:19:21 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		check;

	assign_stack(&a);
	b.top_node = NULL;
	b.n_nodes = 0;
	check = 0;
	if (argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (error_msg(), 0);
	if (!check_store_args(argc, argv, &a))
		check = 1;
	else if (a.n_nodes > 0)
	{
		rank_array(&a);
		check_stack_size_sort(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (check);
}
