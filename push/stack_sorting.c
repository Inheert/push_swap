/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:07:15 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/05 17:55:11 by tclaereb         ###   ########.fr       */
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
	int	rotation;

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
			rotation = 0;
			while ((*stack_b)->previous->content < (*stack_a)->content)
			{
				rrb(stack_b);
				rotation++;
			}
			pb(stack_a, stack_b);
			while (rotation--)
				rb(stack_b);
			rb(stack_b);
		}
	}
}

void	reverse_sorting(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		if (!(*stack_a))
			pa(stack_b, stack_a);
		else if ((*stack_a)->content > (*stack_b)->content)
			pa(stack_b, stack_a);
		else if ((*stack_b)->content > (*stack_a)->content && (*stack_b)->content > (*stack_a)->previous->content)
		{
			pa(stack_b, stack_a);
			ra(stack_a);
		}
		else if ((*stack_b)->content > (*stack_a)->content && (*stack_b)->content < (*stack_a)->previous->content)
		{
			rra(stack_a);
			pa(stack_b, stack_a);
			ra(stack_a);
			ra(stack_a);
		}
	}
}

void	rotate_until(t_list **stack, int rotation)
{
	while (rotation--)
		ra(stack);
}
