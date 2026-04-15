/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:38:46 by mwin              #+#    #+#             */
/*   Updated: 2025/09/12 09:45:25 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	int				data;
	int				rank;
	struct s_node	*next_node;
}	t_node;

typedef struct s_stack
{
	t_node	*top_node;
	int		n_nodes;
}	t_stack;

void	assign_stack(t_stack *stack);
int		check_store_args(int argc, char *argv[], t_stack *stack);
int		store_order_inputs(t_stack *stack, int data);
int		check_number(const char *n);
int		check_duplicate(int *input_array, int count, int number);
int		check_overflow(const char *n);
void	swap_first_2_nodes(t_stack *stack);
void	push_top_at_s1_to_top_at_s2(t_stack *s1, t_stack *s2);
void	rotate_top_to_bottom(t_stack *stack);
void	rotate_bottom_to_top(t_stack *stack);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	error_msg(void);
void	free_stack(t_stack *stack);
void	free_split(char **split);
void	swap_nbr(int *a, int *b);
void	rank_array(t_stack *stack);
int		if_sorted(t_stack *a);
void	radix_sort(t_stack *a, t_stack *b);
void	three_nbr_sort(t_stack *a);
void	four_nbr_sort(t_stack *a, t_stack *b);
void	five_nbr_sort(t_stack *a, t_stack *b);
void	check_stack_size_sort(t_stack *a, t_stack *b);

#endif
