/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_d_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthottap <mthottap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:16:24 by mthottap          #+#    #+#             */
/*   Updated: 2025/04/21 12:11:28 by mthottap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate_both(t_stack_block **a,
	t_stack_block **b,
	t_stack_block *cheapest_node)
{
	while (*b != cheapest_node->block_targeted
		&& *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack_block **a,
	t_stack_block **b,
	t_stack_block *cheapest_node)
{
	while (*b != cheapest_node->block_targeted
		&& *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	move_a_to_b(t_stack_block **a, t_stack_block **b)
{
	t_stack_block	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->top_of_median
		&& cheapest_node->block_targeted->top_of_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->top_of_median)
		&& !(cheapest_node->block_targeted->top_of_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->block_targeted, 'b');
	pb(b, a, false);
}

void	move_b_to_a(t_stack_block **a, t_stack_block **b)
{
	prep_for_push(a, (*b)->block_targeted, 'a');
	pa(a, b, false);
}

void	min_on_top(t_stack_block **a)
{
	while ((*a)->nmb != find_min(*a)->nmb)
	{
		if (find_min(*a)->top_of_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
