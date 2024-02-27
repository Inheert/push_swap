/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:46:40 by tclaereb          #+#    #+#             */
/*   Updated: 2024/02/27 16:24:32 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*item;
	t_list	*next;

	if (!lst)
		return ;
	item = (t_list *)*lst;
	while (item)
	{
		next = item->next;
		ft_lstdelone(item);
		item = next;
	}
	*lst = NULL;
}
