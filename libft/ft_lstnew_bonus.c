/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:27:59 by tclaereb          #+#    #+#             */
/*   Updated: 2024/07/04 18:14:50 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*item;

	item = ft_calloc(1, sizeof(t_list));
	if (!item)
		return (NULL);
	item->content = content;
	item->next = item;
	item->previous = item;
	item->final = 1;
	item->index = 1;
	return (item);
}
