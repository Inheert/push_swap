/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:42:59 by tclaereb          #+#    #+#             */
/*   Updated: 2024/07/04 19:19:06 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_list **src, t_list **dst)
{
	t_list	*header;
	size_t	src_size;

	src_size = ft_lstsize(*src);
	if (src_size < 1)
		return ;
	header = ft_lstnew((*src)->content);
	if (!header)
		return (exception(src, dst));
	header->index = (*src)->index;
	header->final = (*src)->final;
	ft_lstadd_front(dst, header);
	if (src_size == 1)
		return (free(*src), *src = NULL, free(*src));
	header = *src;
	header->previous->next = header->next;
	header->next->previous = header->previous;
	header = header->next;
	free(*src);
	*src = header;
	set_index(src);
	set_index(dst);
}

void	pa(t_list **src, t_list **dst)
{
	push(dst, src);
	ft_printf("pa\n");
}

void	pb(t_list **src, t_list **dst)
{
	push(src, dst);
	ft_printf("pb\n");
}
