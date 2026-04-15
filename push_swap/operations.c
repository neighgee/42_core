/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:43:16 by mwin              #+#    #+#             */
/*   Updated: 2025/09/12 09:44:29 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1. assign "first" as top node
2. assign "second" as node after that
3. assign address of 1st "next_node" to 2nd's "next_node"
4. assign 2nd's "next_node" to point to 1st's "next_node"
NOW:
	- 1st's and 2nd's data remains the same
	- 1st next_node is 2nd's next_node
	- 2nd's next_node is 1st's next_node
5. change the top node to "second" - SWAPPING COMPLETED
*/
void	swap_first_2_nodes(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->n_nodes < 2)
		return ;
	first = stack->top_node;
	second = first->next_node;
	first->next_node = second->next_node;
	second->next_node = first;
	stack->top_node = second;
}

/*
1. use a temp node to store the top_node at stack1(s1)
2. change s1's top_node to now be it's next_node using temp
NOW:
	- s1 does not have its original top_node and has -1 node
3. shift s2's top node down and replace its top_node with s1's
	by:
	- store s2's top_node in temp's next_node
	- assign s2's top_node as temp: temp is s1's top_node
NOW:
	- s2's top_node is s1's top_node
	- next_node points to s2's original top_node
	- s2 now has +1 node
4. assign 2nd's "next_node" to point to 1st's "next_node" - PUSHING COMPLETE
*/
void	push_top_at_s1_to_top_at_s2(t_stack *s1, t_stack *s2)
{
	t_node	*temp;

	if (!s1 || s1->n_nodes == 0)
		return ;
	temp = s1->top_node;
	s1->top_node = temp->next_node;
	s1->n_nodes--;
	temp->next_node = s2->top_node;
	s2->top_node = temp;
	s2->n_nodes++;
}

/*
1. 2 variables, "top" and "bottom" t_nodes
2. start with both as the top of stack
3. iterate through stack using bottom, "bottom" now points to the bottom node
NOW:
	- top points to top_node at stack
	- bottom points to bottom_node at stack
4. change the top_node of stack to be the next_node after top
5. assign top's next_node to NULL, cutting off/ending top
NOW:
	- stack starts at the 2nd node aka node after top
	- top is "dangling"
6. assign bottom's next_node as top, top is now bottom
ROTATION COMPLETE
*/
void	rotate_top_to_bottom(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;

	if (!stack || stack->n_nodes < 2)
		return ;
	top = stack->top_node;
	bottom = stack->top_node;
	while (bottom->next_node)
		bottom = bottom->next_node;
	stack->top_node = top->next_node;
	top->next_node = NULL;
	bottom->next_node = top;
}

/*
1. 2 variables, "second_last" and "last" t_nodes
2. assign last as top_node in stack, second_last as NULL
3. iterate through stack using last, assigning 2ndlast and last
NOW:
	- 2nd last points to 2nd last value
	- last points to last value
4. end the stack at 2nd last
	by:
	- 2nd last "next_node" ends aka assign it to NULL
5. move stack's top_node to last's next_node
6. assign last to be at the top_node of stack
NOW:
	- last is at the top
	- last's next_node points to original top_node
ROTATION COMPLETE
*/
void	rotate_bottom_to_top(t_stack *stack)
{
	t_node	*second_last;
	t_node	*last;

	if (!stack || stack->n_nodes < 2)
		return ;
	second_last = NULL;
	last = stack->top_node;
	while (last->next_node)
	{
		second_last = last;
		last = last->next_node;
	}
	if (second_last)
		second_last->next_node = NULL;
	last->next_node = stack->top_node;
	stack->top_node = last;
}
