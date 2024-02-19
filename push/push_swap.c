/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:14:46 by tclaereb          #+#    #+#             */
/*   Updated: 2024/02/19 13:24:47 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*	MANAGE INT MIN AND INT MAX FOR ARGS
*/
t_list	*fill_stack(char **argv, t_list *stack)
{
	int		n;
	t_list	*item;
	while (*argv)
	{
		n = ft_atoi(*argv);
		if (n < 0)
			exception(&stack, NULL);
		item = ft_lstnew(n);
		ft_lstadd_back(&stack, item);
		argv++;
	}
	return (stack);
}

void	empty_stack(t_list **stack)
{
	t_list	*item;
	t_list	*next;

	if (!stack)
		return ;
	item = *stack;
	while (item)
	{
		next = item->next;
		free(item);
		item = next;
	}
	*stack = NULL;
}

// IMPORT AND USE PERSONAL PRINTF FUNC
void	exception(t_list **stack_a, t_list **stack_b)
{
	empty_stack(stack_a);
	empty_stack(stack_b);
	printf("Error\n");
	exit(1);
}

t_list	*check_args(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc <= 1)
		exception(NULL, NULL);
	stack_a = ft_lstnew(-1);
	fill_stack(argv, stack_a);
	return (stack_a);
}
