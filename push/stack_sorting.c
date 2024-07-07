/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:07:15 by tclaereb          #+#    #+#             */
/*   Updated: 2024/07/05 16:18:21 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	set_group_2(t_list *stack, t_list *tmp, size_t *j)
{
	size_t	size;

	size = ft_lstsize(stack);
	if (size <= 100)
	{
		if ((size_t)tmp->final < (size / 7 + 1) * *j)
			tmp->group = *j;
		else
			(*j)++;
	}
	else
	{
		if ((size_t)tmp->final < (size / 17 + 1) * *j)
			tmp->group = *j;
		else
			(*j)++;
	}
}

void	set_group(t_list *stack)
{
	t_list	*tmp;
	size_t	i;
	size_t	j;

	tmp = stack;
	i = 0;
	while (i++ < ft_lstsize(stack))
	{
		tmp->group = 0;
		tmp = tmp->next;
	}
	i = 0;
	while (i++ < ft_lstsize(stack))
	{
		j = 1;
		while (tmp->group == 0)
			set_group_2(stack, tmp, &j);
		tmp = tmp->next;
	}
}

void	set_final(t_list *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = stack;
	while (tmp1->next != stack)
	{
		tmp2 = tmp1->next;
		while (tmp2 != stack)
		{
			if (tmp1->content < tmp2->content)
				tmp2->final = tmp2->final + 1;
			else
				tmp1->final = tmp1->final + 1;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	size_t	size;

	if (is_sorted(stack_a))
		return ;
	size = ft_lstsize(*stack_a);
	set_final(*stack_a);
	set_group(*stack_a);
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
	{
		sort(stack_a, stack_b);
		stack_3(stack_a);
		sort_back(stack_a, stack_b);
		if (is_sorted(stack_a))
			return ;
	}
}
