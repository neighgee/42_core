/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:50:42 by mwin              #+#    #+#             */
/*   Updated: 2025/09/12 09:45:50 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//top number in B goes to top of A
void	pa(t_stack *a, t_stack *b)
{
	push_top_at_s1_to_top_at_s2(b, a);
	ft_printf("pa\n");
}

//top number in A goes to top of B
void	pb(t_stack *a, t_stack *b)
{
	push_top_at_s1_to_top_at_s2(a, b);
	ft_printf("pb\n");
}
