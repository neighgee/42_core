/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:05:18 by mwin              #+#    #+#             */
/*   Updated: 2025/08/29 16:45:44 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap first 2 numbers in A
void	sa(t_stack *a)
{
	swap_first_2_nodes(a);
	ft_printf("sa\n");
}

//swap first 2 numbers in B
void	sb(t_stack *b)
{
	swap_first_2_nodes(b);
	ft_printf("sb\n");
}

//swap first 2 numbers in A and B
void	ss(t_stack *a, t_stack *b)
{
	swap_first_2_nodes(a);
	swap_first_2_nodes(b);
	ft_printf("ss\n");
}
