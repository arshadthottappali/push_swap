/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilit_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthottap <mthottap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:16:24 by mthottap          #+#    #+#             */
/*   Updated: 2025/04/21 12:11:59 by mthottap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	len_of_stack(t_stack_block *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack_block	*find_last(t_stack_block *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_block *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nmb > stack->next->nmb)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_block	*find_min(t_stack_block *stack)
{
	long			min;
	t_stack_block	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nmb < min)
		{
			min = stack->nmb;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_block	*find_max(t_stack_block *stack)
{
	long			max;
	t_stack_block	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nmb > max)
		{
			max = stack->nmb;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
