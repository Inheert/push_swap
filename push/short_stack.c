/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 06:41:52 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/21 09:09:02 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

unsigned int	get_distance(t_list **stack, int idx)
{
	int		first_idx_place;
	size_t	size;
	t_list	*buff;

	size = ft_lstsize(*stack);
	buff = *stack;
	while (size--)
	{
		if (buff->index == idx)
		{
			first_idx_place = ft_lstsize(*stack) - size;
			break ;
		}
		buff = buff->next;
	}
	return (first_idx_place);
}

void	stack_3(t_list **stack)
{
	if ((*stack)->content < (*stack)->next->content
		&& (*stack)->content < (*stack)->previous->content)
	{
		if ((*stack)->next->content > (*stack)->previous->content)
		{
			ra(stack);
			sa(stack);
			rra(stack);
		}
	}
	else if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content > (*stack)->previous->content)
	{
		ra(stack);
		if ((*stack)->content > (*stack)->next->content)
			sa(stack);
	}
	else if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content < (*stack)->previous->content)
	{
		sa(stack);
	}
	else if ((*stack)->content < (*stack)->next->content
		&& (*stack)->content > (*stack)->previous->content)
		rra(stack);
}

void	stack_5(t_list **stack_a, t_list **stack_b)
{
	int		first_idx_place;
	int		idx_search;

	idx_search = 0;
	while (idx_search <= 1)
	{
		first_idx_place = get_distance(stack_a, idx_search);
		while ((*stack_a)->index != idx_search)
		{
			if (first_idx_place > 3)
				rra(stack_a);
			else
				ra(stack_a);
		}
		pb(stack_a, stack_b);
		idx_search++;
	}
	stack_3(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
