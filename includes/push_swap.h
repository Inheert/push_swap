/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 05:00:36 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/21 07:54:50 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

void	exception(t_list **stack_a, t_list **stack_b);
t_list	*check_args(int argc, char **argv);

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

int		is_sorted(t_list **stack);
void	empty_stack(t_list **stack);
void	set_index(t_list **stack);
void	stack_3(t_list **stack);
void	stack_5(t_list **stack_a, t_list **stack_b);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sorting(t_list **stack_a, t_list **stack_b);
void	reverse_sorting(t_list **stack_a, t_list **stack_b);
void	display_stacks(t_list **stack_a, t_list **stack_b);
void	rotate_until(t_list **stack, int rotation);
#endif
