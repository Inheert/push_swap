/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:04:14 by Theo              #+#    #+#             */
/*   Updated: 2024/03/21 06:37:14 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

int	ft_atoi(const char *nptr, t_list **stack_a)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr)
	{
		if (!(*nptr >= '0' && *nptr <= '9'))
			exception(stack_a, NULL);
		if ((long long)result * 10 + (*nptr - '0') > INT_MAX
			|| (long long)result * 10 + (*nptr - '0') < INT_MIN)
			exception(stack_a, NULL);
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}
