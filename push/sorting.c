/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:37:34 by tclaereb          #+#    #+#             */
/*   Updated: 2024/07/04 19:19:21 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_group_2(t_list *stack, t_list *tmp, size_t *j)
{
	size_t	size;

	size = ft_lstsize(stack);
	if (size <= 100)
	{
		if ((size_t)tmp->final < (size / 7 + 1) * *j)
			tmp->group = *j;
		else
			(*j)++;
	}
	else
	{
		if ((size_t)tmp->final < (size / 17 + 1) * *j)
			tmp->group = *j;
		else
			(*j)++;
	}
}

void	set_group(t_list *stack)
{
	t_list	*tmp;
	size_t	i;
	size_t	j;

	tmp = stack;
	i = 0;
	while (i++ < ft_lstsize(stack))
	{
		tmp->group = 0;
		tmp = tmp->next;
	}
	i = 0;
	while (i++ < ft_lstsize(stack))
	{
		j = 1;
		while (tmp->group == 0)
			set_group_2(stack, tmp, &j);
		tmp = tmp->next;
	}
}

void	set_final(t_list *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = stack;
	while (tmp1->next != stack)
	{
		tmp2 = tmp1->next;
		while (tmp2 != stack)
		{
			if (tmp1->content < tmp2->content)
				tmp2->final = tmp2->final + 1;
			else
				tmp1->final = tmp1->final + 1;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

t_list	*find_min(t_list *stack)
{
	t_list	*tmp;
	size_t	size;

	size = ft_lstsize(stack);
	tmp = stack;
	while (size--)
	{
		if (tmp->content > stack->content)
			tmp = stack;
		stack = stack->next;
	}
	return (tmp);
}

void	sort_3(t_list **ptr, t_list **a_head)
{
	if ((size_t)(*ptr)->index <= (ft_lstsize(*a_head) / 2) + 1)
		ra(a_head);
	else
		rra(a_head);
}

void	sort_2(int *current, t_list **ptr, t_list **a_head)
{
	*current = (*ptr)->content;
	while ((*a_head)->content != *current)
		sort_3(ptr, a_head);
}

void	s_4(int *i, t_list **a_head, t_list **b_head, t_list **ptr)
{
	pb((*i = -1, a_head), b_head);
	*ptr = *a_head;
}

void	s_5(int *i, t_list **a_head, t_list **b_head, t_list **ptr)
{
	pb((*i = -1, a_head), b_head);
	rb(b_head);
	*ptr = *a_head;
}

void	sort_6(t_list **ptr, int *i)
{
	*ptr = (*ptr)->next;
	*i = -1;
}

void	s_1(t_list **a_head, t_list **b_head, int size, int nth_group)
{
	int		i;
	t_list	*ptr;
	int		current;

	i = -1;
	ptr = *a_head;
	while ((++i <= (int)ft_lstsize(*a_head)) && ft_lstsize(*a_head) > 3)
	{
		if ((ptr->group == nth_group || ptr->group == nth_group + 1)
			&& (size_t)ptr->final <= (size_t)size - 3)
		{
			sort_2(&current, &ptr, a_head);
			if ((size_t)(*a_head)->final <= (size_t)size - 3)
			{
				if ((*a_head)->group == nth_group)
					s_4(&i, a_head, b_head, &ptr);
				else if ((*a_head)->group == nth_group + 1)
					s_5(&i, a_head, b_head, &ptr);
			}
			else
				sort_6(&ptr, &i);
		}
		else
			ptr = ptr->next;
	}
}

void	sort(t_list **a_head, t_list **b_head)
{
	int				nth_group;
	int				size;

	nth_group = 1;
	size = ft_lstsize(*a_head);
	while (ft_lstsize(*a_head) > 3)
	{
		s_1(a_head, b_head, size, nth_group);
		nth_group = nth_group + 2;
	}
}

void	sort_back(t_list **a_head, t_list **b_head)
{
	int	max;
	t_list	*ptr;

	// size_t	size;
	// t_list	*tmp;
	// size = ft_lstsize(*a_head);
	// tmp = *a_head;
	// while (size--)
	// {
	// 	printf("%d %d %d\n", tmp->content, tmp->final, tmp->index);
	// 	tmp = tmp->next;
	// }
	// return ;

	while (*b_head)
	{
		ptr = *b_head;
		max = (int)ft_lstsize(*b_head);
		while (ptr->final != max)
			ptr = ptr->next;
		while ((*b_head)->final != max)
		{
			if ((*b_head)->final == max - 1)
				pa(a_head, b_head);
			else if (ptr->index <= (int)(ft_lstsize(*b_head) / 2) + 1)
				rb(b_head);
			else
				rrb(b_head);
		}
		pa(a_head, b_head);
		if ((*a_head)->next && (*a_head)->content > (*a_head)->next->content)
			sa(a_head);
	}
}
