/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:28:35 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/18 17:07:15 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
	IMPORT FT_PRINTF
	CHANGE ERROR PRINT
	CHANGE INSTRUCTIONS PRINTS
	EXPLOSION
*/

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	argv++;
	stack_a = check_args(argc, argv);
	stack_b = NULL;
	set_index(&stack_a);
	display_stacks(&stack_a, &stack_b);
	sort_stack(&stack_a, &stack_b);
	display_stacks(&stack_a, &stack_b);
	/*
	while (!is_sorted(&stack_a) && !stack_b)
	{
		sorting(&stack_a, &stack_b);
		reverse_sorting(&stack_a, &stack_b);
	}
	*/
	return (0);
}
