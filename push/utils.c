/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_setter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:29:11 by tclaereb          #+#    #+#             */
/*   Updated: 2024/07/05 16:16:26 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_index(t_list **stack)
{
	t_list	*tmp;
	size_t	size;
	int		i;

	tmp = *stack;
	i = 1;
	size = ft_lstsize(tmp);
	while (size--)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
}

t_list	*find_min(t_list *stack)
{
	t_list	*tmp;
	size_t	size;

	size = ft_lstsize(stack);
	tmp = stack;
	while (size--)
	{
		if (tmp->content > stack->content)
			tmp = stack;
		stack = stack->next;
	}
	return (tmp);
}

void	find_nearest(int *current, t_list **ptr, t_list **a_head)
{
	*current = (*ptr)->content;
	while ((*a_head)->content != *current)
	{
		if ((size_t)(*ptr)->index <= ft_lstsize(*a_head) / 2 + 1)
			ra(a_head);
		else
			rra(a_head);
	}
}

void	find_best_move(t_list **stack_a, t_list **stack_b, int n_group)
{
	if ((*stack_a)->group == n_group)
	{
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->group == n_group + 1)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
	}
}
