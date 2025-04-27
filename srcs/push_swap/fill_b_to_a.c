/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthottap <mthottap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:16:24 by mthottap          #+#    #+#             */
/*   Updated: 2025/04/21 12:11:43 by mthottap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	set_target_b(t_stack_block *a, t_stack_block *b)
{
	t_stack_block	*current_a;
	t_stack_block	*block_targeted;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nmb > b->nmb
				&& current_a->nmb < best_match_index)
			{
				best_match_index = current_a->nmb;
				block_targeted = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->block_targeted = find_min(a);
		else
			b->block_targeted = block_targeted;
		b = b->next;
	}
}

void	init_nodes_b(t_stack_block *a, t_stack_block *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
