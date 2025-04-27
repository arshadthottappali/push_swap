/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthottap <mthottap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:16:24 by mthottap          #+#    #+#             */
/*   Updated: 2025/04/21 12:31:45 by mthottap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

// How each block in the stack is structured
typedef struct s_stack_block
{
	int						nmb;
	int						position;
	int						no_of_moves;
	bool					top_of_median;
	bool					cheapest;
	struct s_stack_block	*block_targeted;
	struct s_stack_block	*next;
	struct s_stack_block	*prev;
}	t_stack_block;

//errors checkers
int				usr_inpt_error(char *str_n);
int				repeation_error(t_stack_block *a, int n);
void			free_stack(t_stack_block **stack);
void			free_errors(t_stack_block **a);

//Functions to fill the Stack (initiation)
void			init_stack_a(t_stack_block **a, char **argv);
char			**split(char *s, char c);

//Block initializing functions
void			init_nodes_a(t_stack_block *a, t_stack_block *b);
void			init_nodes_b(t_stack_block *a, t_stack_block *b);
void			current_index(t_stack_block *stack);
void			set_cheapest(t_stack_block *stack);
t_stack_block	*get_cheapest(t_stack_block *stack);
void			prep_for_push(t_stack_block **s, t_stack_block *n, char c);

// Stack utilities functions
int				len_of_stack(t_stack_block *stack);
t_stack_block	*find_last(t_stack_block *stack);
bool			stack_sorted(t_stack_block *stack);
t_stack_block	*find_min(t_stack_block *stack);
t_stack_block	*find_max(t_stack_block *stack);

// Functions for Commands
void			sa(t_stack_block **a, bool print);
void			sb(t_stack_block **b, bool print);
void			ss(t_stack_block **a, t_stack_block **b, bool print);
void			ra(t_stack_block **a, bool print);
void			rb(t_stack_block **b, bool print);
void			rr(t_stack_block **a, t_stack_block **b, bool print);
void			rra(t_stack_block **a, bool print);
void			rrb(t_stack_block **b, bool print);
void			rrr(t_stack_block **a, t_stack_block **b, bool print);
void			pa(t_stack_block **a, t_stack_block **b, bool print);
void			pb(t_stack_block **b, t_stack_block **a, bool print);

// Algorithm functions
void			sort_three(t_stack_block **a);
void			sort_stacks(t_stack_block **a, t_stack_block **b);

// Sort_d_stacks functions
void			sort_stacks(t_stack_block **a, t_stack_block **b);
void			push_to_b(t_stack_block **a, t_stack_block **b);
void			move_nodes_to_b(t_stack_block **a, t_stack_block **b);
void			move_nodes_to_a(t_stack_block **a, t_stack_block **b);

// Move_nodes functions
void			move_a_to_b(t_stack_block **a, t_stack_block **b);
void			move_b_to_a(t_stack_block **a, t_stack_block **b);
void			min_on_top(t_stack_block **a);

// Rotation_utils functions
void			rotate_both(t_stack_block **a, t_stack_block **b,
					t_stack_block *cheapest_node);
void			rev_rotate_both(t_stack_block **a, t_stack_block **b,
					t_stack_block *cheapest_node);

#endif
