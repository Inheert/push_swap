/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:14:46 by tclaereb          #+#    #+#             */
/*   Updated: 2024/02/27 15:37:56 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	**fill_stack(char **argv, t_list **stack)
{
	int		n;
	t_list	*item;
	while (*argv)
	{
		n = ft_atoi(*argv);
		if (n < 0)
			exception(stack, NULL);
		item = ft_lstnew(n);
		ft_lstadd_back(stack, item);
		argv++;
	}
	return (stack);
}

void	empty_stack(t_list **stack)
{
	t_list	*item;
	t_list	*next;
	size_t	stack_size;

	if (!stack)
		return ;
	item = *stack;
	stack_size = ft_lstsize(*stack);
	while (stack_size--)
	{
		next = item->next;
		free(item);
		item = next;
	}
	*stack = NULL;
}

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
	t_list	*to_check;
	t_list	*checker;
	size_t	stack_size;


	if (argc <= 1)
		exit(0);
	stack_a = NULL;
	fill_stack(argv, &stack_a);
	to_check = stack_a;
	argc = ft_lstsize(stack_a);
	while (argc--)
	{
		checker = stack_a;
		stack_size = ft_lstsize(stack_a);
		while (stack_size--)
		{
			if (checker->content == to_check->content && checker != to_check)
				exception(&stack_a, NULL);
			checker = checker->next;
		}
		to_check = to_check->next;
	}
	return (stack_a);
}
