/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:50:58 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/18 13:11:01 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	t_list	*first;
	size_t	size;

	if (!lst)
		return (0);
	first = lst;
	size = 0;
	while (lst != first || size == 0)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
