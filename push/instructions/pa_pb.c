/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:42:59 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/21 09:34:43 by tclaereb         ###   ########.fr       */
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
	ft_lstadd_front(dst, header);
	if (src_size == 1)
		return (free(*src), *src = NULL, free(*src));
	header = *src;
	header->previous->next = header->next;
	header->next->previous = header->previous;
	header = header->next;
	free(*src);
	*src = header;
}

void	pa(t_list **src, t_list **dst)
{
	push(src, dst);
	write(1, "pa\n", 3);
}

void	pb(t_list **src, t_list **dst)
{
	push(src, dst);
	write(1, "pb\n", 3);
}
