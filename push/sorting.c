/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:29:11 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/11 16:43:28 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_index_set(t_list *stack)
{
	size_t	size;
	size = ft_lstsize(stack);
	while (size --)
	{
		if (!stack->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	set_index(t_list *stack)
{
	size_t	size;
	t_list	*buff;
	t_list	*lower;

	size = ft_lstsize(stack);
	buff = stack;
	while (size--)
	{
		buff->index = 1;
		buff = buff->next;
	}
	printf("%d\n", is_index_set(stack));
}
