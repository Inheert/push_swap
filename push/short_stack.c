/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 06:41:52 by tclaereb          #+#    #+#             */
/*   Updated: 2024/07/08 16:08:37 by tclaereb         ###   ########.fr       */
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
	first_idx_place = 0;
	while (size--)
	{
		if (buff->final == idx)
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
	if ((*stack) == find_min(*stack))
	{
		if ((*stack)->next->content > (*stack)->previous->content)
			sa((rra(stack), stack));
	}
	else if ((*stack)->next == find_min(*stack))
	{
		if ((*stack)->content < (*stack)->previous->content)
			sa(stack);
		else
			ra(stack);
	}
	else
	{
		if ((*stack)->content < (*stack)->next->content)
			rra(stack);
		else
			rra((sa(stack), stack));
	}
}

void	_stack_5(t_list **stack_a, t_list **stack_b)
{
	int		first_idx_place;
	int		idx_search;

	idx_search = 0;
	while (idx_search <= 1)
	{
		first_idx_place = get_distance(stack_a, idx_search);
		while ((*stack_a)->final != idx_search)
		{
			if (first_idx_place > 2)
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

void	stack_5(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		while ((*stack_a)->final != 1 && (*stack_a)->final != 2)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	stack_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}
