/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthottap <mthottap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:16:24 by mthottap          #+#    #+#             */
/*   Updated: 2025/04/27 21:26:01 by mthottap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	usr_inpt_error(char *s_n)
{
	if (!(*s_n == '+'
			|| *s_n == '-'
			|| (*s_n >= '0' && *s_n <= '9')))
		return (1);
	if ((*s_n == '+'
			|| *s_n == '-')
		&& !(s_n[1] >= '0' && s_n[1] <= '9'))
		return (1);
	while (*++s_n)
	{
		if (!(*s_n >= '0' && *s_n <= '9'))
			return (1);
	}
	return (0);
}

int	repeation_error(t_stack_block *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nmb == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_block **stack)
{
	t_stack_block	*tmp;
	t_stack_block	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nmb = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_block **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
