/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:42:59 by tclaereb          #+#    #+#             */
/*   Updated: 2024/02/27 17:33:56 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
void	push(t_list **src, t_list **dst)
{
	t_list	*top;
	size_t	src_size;

	src_size = ft_lstsize(*src);
	if (src_size < 1)
		return ;
	// Modify src
	(*src)->next->previous = (*src)->previous;
	(*src)->previous->next = (*src)->next;
	*src = (*src)->next;
	printf("%p\n", (*src)->next);
	// Set new header and previous and next for it
	top = *src;
	top->previous = (*dst)->previous;
	top->next = *dst;
	// Modify next for previous in dst
	// Modify previous for header in dst
	// Modify header of dst
	(*dst)->previous->next = top;
	(*dst)->previous = top;
	*dst = top;
	printf("%p\n", (*src)->next);
}*/

void	push(t_list **src, t_list **dst)
{
	t_list	*header;
	size_t	src_size;

	src_size = ft_lstsize(*src);
	if (src_size < 1)
		return ;
	header = ft_lstnew((*src)->content);
	ft_lstadd_front(dst, header);
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

void	pb(t_list **dst, t_list **src)
{
	push(src, dst);
	write(1, "pb\n", 3);
}
