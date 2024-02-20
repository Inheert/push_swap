/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:28:35 by tclaereb          #+#    #+#             */
/*   Updated: 2024/02/20 15:25:37 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*item;
	int		i;

	argv++;
	stack_a = check_args(argc, argv);
	item = stack_a;
	i = ft_lstsize(stack_a);
	while (i--)
	{
		printf("%d\n", item->content);
		item = item->next;
	}
	return (0);
}
