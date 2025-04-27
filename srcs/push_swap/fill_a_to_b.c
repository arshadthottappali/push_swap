/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthottap <mthottap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:16:24 by mthottap          #+#    #+#             */
/*   Updated: 2025/04/21 12:11:40 by mthottap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	current_index(t_stack_block *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = len_of_stack(stack) / 2;
	while (stack)
	{
		stack->position = i;
		stack->top_of_median = (i <= median);
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_stack_block *a, t_stack_block *b)
{
	t_stack_block	*current_b;
	t_stack_block	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nmb < a->nmb
				&& current_b->nmb > best_match_index)
			{
				best_match_index = current_b->nmb;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->block_targeted = find_max(b);
		else
			a->block_targeted = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack_block *a, t_stack_block *b)
{
	int	len_a;
	int	len_b;

	len_a = len_of_stack(a);
	len_b = len_of_stack(b);
	while (a)
	{
		a->no_of_moves = a->position;
		if (!(a->top_of_median))
			a->no_of_moves = len_a - (a->position);
		if (a->block_targeted->top_of_median)
			a->no_of_moves += a->block_targeted->position;
		else
			a->no_of_moves += len_b - (a->block_targeted->position);
		a = a->next;
	}
}

void	set_cheapest(t_stack_block *stack)
{
	long			cheapest_value;
	t_stack_block	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->no_of_moves < cheapest_value)
		{
			cheapest_value = stack->no_of_moves;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_block *a, t_stack_block *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
