/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:37:34 by tclaereb          #+#    #+#             */
/*   Updated: 2024/07/05 17:53:16 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_group(t_list **stack_a, t_list **stack_b, int size, int n_group)
{
	int		i;
	t_list	*ptr;
	int		current;

	i = -1;
	ptr = *stack_a;
	while ((++i <= (int)ft_lstsize(*stack_a)) && ft_lstsize(*stack_a) > 3)
	{
		if ((ptr->group == n_group || ptr->group == n_group + 1)
			&& ptr->final <= size - 3)
		{
			find_nearest(&current, &ptr, stack_a);
			if ((*stack_a)->final <= size - 3)
				find_best_move(stack_a, stack_b, n_group);
			else
				ptr = ptr->next;
			i = -1;
		}
		else
			ptr = ptr->next;
	}
}

void	sort(t_list **a_head, t_list **b_head)
{
	int	n_group;
	int	size;

	n_group = 1;
	size = ft_lstsize(*a_head);
	while (ft_lstsize(*a_head) > 3)
	{
		sort_group(a_head, b_head, size, n_group);
		n_group = n_group + 2;
	}
}

void	sort_back(t_list **a_head, t_list **b_head)
{
	int	max;
	t_list	*ptr;

	while (*b_head)
	{
		ptr = *b_head;
		max = (int)ft_lstsize(*b_head);
		while (ptr->final != max)
			ptr = ptr->next;
		while ((*b_head)->final != max)
		{
			if ((*b_head)->final == max - 1)
				pa(a_head, b_head);
			else if (ptr->index <= (int)(ft_lstsize(*b_head) / 2) + 1)
				rb(b_head);
			else
				rrb(b_head);
		}
		pa(a_head, b_head);
		if ((*a_head)->next && (*a_head)->content > (*a_head)->next->content)
			sa(a_head);
	}
}
