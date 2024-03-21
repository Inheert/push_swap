/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:30:13 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/21 06:37:26 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		(*lst)->next = new;
		(*lst)->previous = new;
		return ;
	}
	new->next = (*lst);
	new->previous = (*lst)->previous;
	(*lst)->previous->next = new;
	(*lst)->previous = new;
	*lst = new;
}
