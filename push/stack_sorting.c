/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:07:15 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/04 17:44:16 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*stack;
	size_t	size;

	stack = *stack_a;
	size = ft_lstsize(*stack_a);
	printf("\n\nSTACK A:\n");
	while (size--)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
	stack = *stack_b;
	size = ft_lstsize(*stack_b);
	printf("\nSTACK B:\n");
	while (size--)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

int	is_sorted(t_list **stack)
{
	int		n;
	size_t	size;
	t_list	*buff;

	size = ft_lstsize(*stack);
	buff = *stack;
	n = buff->content;
	while (size--)
	{
		if (n > buff->content)
			return (0);
		n = buff->content;
		buff = buff->next;
	}
	return (1);
}

void	sorting(t_list **stack_a, t_list **stack_b)
{
	printf("Is sorted: %d\n", is_sorted(stack_a));
	while (*stack_a)
	{
		if (!(*stack_b))
			pb(stack_a, stack_b);
		else if ((*stack_a)->content > (*stack_b)->content)
			pb(stack_a, stack_b);
		else if ((*stack_b)->content > (*stack_a)->content && (*stack_b)->previous->content > (*stack_a)->content)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if ((*stack_b)->content > (*stack_a)->content && (*stack_b)->previous->content < (*stack_a)->content)
		{
			rrb(stack_b);
			pb(stack_a, stack_b);
			rb(stack_b);
		}
	}
	display_stacks(stack_a, stack_b);
}
