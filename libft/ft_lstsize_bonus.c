/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:50:58 by tclaereb          #+#    #+#             */
/*   Updated: 2024/02/20 15:18:24 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*first;
	int		size;

	first = lst;
	size = 0;
	while (lst != first || size == 0)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
