/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 05:00:36 by tclaereb          #+#    #+#             */
/*   Updated: 2024/07/04 16:57:24 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include "../libft/libft.h"

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **src, t_list **dst);
void	pb(t_list **src, t_list **dst);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	exception(t_list **stack_a, t_list **stack_b);
t_list	*check_args(int argc, char **argv);
int		is_sorted(t_list **stack);
void	empty_stack(t_list **stack);
void	set_index(t_list **stack);
void	stack_3(t_list **stack);
void	stack_5(t_list **stack_a, t_list **stack_b);
void	sort_stack(t_list **stack_a, t_list **stack_b);
t_list	*find_min(t_list *stack);
void	find_nearest(int *current, t_list **ptr, t_list **a_head);
void	find_best_move(t_list **stack_a, t_list **stack_b, int n_group);

void	set_final(t_list *stack);
void	set_group(t_list *stack);
void	set_group_2(t_list *stack, t_list *tmp, size_t *j);
t_list	*find_min(t_list *stack);
void	sort_back(t_list **a_head, t_list **b_head);
void	sort(t_list **a_head, t_list **b_head);

#endif
