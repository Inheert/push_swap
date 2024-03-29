/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_setter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:29:11 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/21 06:35:01 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_buff_sorted(t_list *stack)
{
	t_list	*buff;

	buff = stack;
	while (stack->next != buff)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	swap_node(t_list *a, t_list *b)
{
	int	temp_content;

	temp_content = a->content;
	a->content = b->content;
	b->content = temp_content;
}

void	bubble_list(t_list **list)
{
	t_list	*tmp;
	size_t	size;
	int		start;

	size = ft_lstsize(*list);
	while (size--)
	{
		start = 0;
		tmp = *list;
		while (tmp != *list || start == 0)
		{
			start = 1;
			if (tmp->content > tmp->next->content)
				swap_node(tmp, tmp->next);
			tmp = tmp->next;
		}
	}
	if ((*list)->content > (*list)->previous->content)
		swap_node(*list, (*list)->previous);
}

void	set_stack_index(t_list **stack, t_list **buffer)
{
	t_list	*buffer_node;
	size_t	stack_size;
	size_t	buffer_size;

	buffer_node = *stack;
	stack_size = ft_lstsize(*stack);
	while (stack_size--)
	{
		buffer_size = ft_lstsize(*buffer);
		while (buffer_size--)
		{
			if (buffer_node->content == (*buffer)->content)
				buffer_node->index = (*buffer)->index;
			*buffer = (*buffer)->next;
		}
		buffer_node = buffer_node->next;
	}
}

void	set_index(t_list **stack)
{
	t_list			*buffer;
	t_list			*node_buffer;
	size_t			size;
	unsigned int	idx;

	buffer = NULL;
	node_buffer = *stack;
	size = ft_lstsize(*stack);
	while (size--)
	{
		ft_lstadd_back(&buffer, ft_lstnew(node_buffer->content));
		node_buffer = node_buffer->next;
	}
	while (!is_buff_sorted(buffer))
		bubble_list(&buffer);
	size = ft_lstsize(buffer);
	idx = 0;
	while (size--)
	{
		buffer->index = idx;
		buffer = buffer->next;
		idx++;
	}
	set_stack_index(stack, &buffer);
	empty_stack(&buffer);
}
