/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:07:15 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/21 08:47:04 by tclaereb         ###   ########.fr       */
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
		printf("%d, %d\n", stack->content, stack->index);
		stack = stack->next;
	}
	if (!stack_b)
		return ;
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

int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;
	size_t	size;

	head = *stack;
	max = head->index;
	max_bits = 0;
	size = ft_lstsize(*stack);
	while (size--)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sorting(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_b, stack_a);
		i++;
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	size_t	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			ra(stack_a);
	}
	else if (size == 3)
		stack_3(stack_a);
	else if (size == 5)
		stack_5(stack_a, stack_b);
	else
		radix_sorting(stack_a, stack_b);
}
