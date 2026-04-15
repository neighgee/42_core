/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:36:57 by mwin              #+#    #+#             */
/*   Updated: 2025/09/12 09:49:33 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//bottom number in A goes to top
void	rra(t_stack *a)
{
	rotate_bottom_to_top(a);
	ft_printf("rra\n");
}

//bottom number in B goes to top
void	rrb(t_stack *b)
{
	rotate_bottom_to_top(b);
	ft_printf("rrb\n");
}

//bottom number in A & B goes to top
void	rrr(t_stack *a, t_stack *b)
{
	rotate_bottom_to_top(a);
	rotate_bottom_to_top(b);
	ft_printf("rrr\n");
}
