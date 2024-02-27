/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:28:35 by tclaereb          #+#    #+#             */
/*   Updated: 2024/02/27 17:46:48 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
	IMPORT FT_PRINTF
	CHANGE ERROR PRINT
	CHANGE INSTRUCTIONS PRINTS
	EXPLOSION
*/

void	test(t_list **stack_a)
{
	t_list	*stack_b;
	t_list	*item;
	size_t	size;

	stack_b = ft_lstnew(5);
	ft_lstadd_back(&stack_b, ft_lstnew(10));
	rrr(&stack_b, stack_a);
	size = ft_lstsize(*stack_a);
	item = *stack_a;
	printf("\nSTACK A:\n");
	while (size--)
	{
		printf("%d\n", item->content);
		item = item->next;
	}
	item = stack_b;
	size = ft_lstsize(stack_b);
	printf("\nSTACK B:\n");
	while (size--)
	{
		printf("%d\n", item->content);
		item = item->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	argv++;
	stack_a = check_args(argc, argv);
	test(&stack_a);
	return (0);
}
