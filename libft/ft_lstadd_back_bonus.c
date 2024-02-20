/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:32:43 by tclaereb          #+#    #+#             */
/*   Updated: 2024/02/20 15:16:58 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
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
	new->previous = (*lst)->previous;
	new->next = *lst;
	(*lst)->previous->next = new;
	(*lst)->previous = new;
}
