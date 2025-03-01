/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:08:45 by abougati          #+#    #+#             */
/*   Updated: 2025/03/01 12:36:47 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_highest(t_stack *a)
{
	t_stack	*max;

	if (!a)
		return (NULL);
	max = a;
	while (a != NULL)
	{
		if (a->content > max->content)
			max = a;
		a = a->next;
	}
	return (max);
}

t_min_cost	find_lowest(t_stack *stack, int size)
{
	t_min_cost	min;
	int			pos;

	min.value = INT_MAX;
	min.moves = -1;
	min.position = -1;
	pos = 0;
	while (stack)
	{
		if (stack->content < min.value)
		{
			if (pos > size / 2)
				min.moves = size - pos;
			else
				min.moves = pos;
			min.value = stack->content;
			min.position = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min);
}

void	sort_2_or_3(t_stack **a)
{
	t_stack	*big_node;

	big_node = find_highest(*a);
	if (big_node == *a)
		ra(a);
	else if ((*a)->next == big_node)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	sort_4_or_5(t_stack **a, t_stack **b)
{
	t_min_cost	min;
	int			size;

	if (!*a)
		return ;
	size = stack_size(*a);
	while (size > 3)
	{
		min = find_lowest(*a, size);
		if ((*a)->content == min.value)
		{
			pb(a, b);
			size--;
		}
		min = find_lowest(*a, size);
		if ((*a)->content != min.value && (min.position <= size / 2)
			&& size > 3)
			ra(a);
		if ((*a)->content != min.value && (min.position > size / 2) && size > 3)
			rra(a);
	}
	if (size == 3)
		sort_2_or_3(a);
	push_back_to_a(b, a);
}
