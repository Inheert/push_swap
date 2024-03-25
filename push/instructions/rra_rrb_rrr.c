/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:38:39 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/25 13:56:05 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrotate(t_list **stack)
{
	*stack = (*stack)->previous;
}

void	rra(t_list **stack_a)
{
	rrotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	rrotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
}
