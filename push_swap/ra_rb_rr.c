/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:09:24 by mwin              #+#    #+#             */
/*   Updated: 2025/08/29 16:45:29 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//top number in A moved to bottom
void	ra(t_stack *a)
{
	rotate_top_to_bottom(a);
	ft_printf("ra\n");
}

//top number in B moved to bottom
void	rb(t_stack *b)
{
	rotate_top_to_bottom(b);
	ft_printf("rb\n");
}

//top number in A & B moved to bottom
void	rr(t_stack *a, t_stack *b)
{
	rotate_top_to_bottom(a);
	rotate_top_to_bottom(b);
	ft_printf("rr\n");
}
