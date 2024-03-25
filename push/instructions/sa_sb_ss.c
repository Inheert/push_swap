/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 06:36:34 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/25 13:56:18 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	size_t	stack_size;

	stack_size = ft_lstsize(*stack);
	if (stack_size <= 1)
		return ;
	*stack = (*stack)->next;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->previous = first->previous;
	first->previous = second;
	second->next = first;
	second->previous->next = second;
	first->next->previous = first;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
