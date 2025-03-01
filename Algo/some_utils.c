/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:09:19 by abougati          #+#    #+#             */
/*   Updated: 2025/02/28 18:31:12 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_smaller(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	is_in_chunk(int num, t_chunk chunk)
{
	return (num >= chunk.start && num <= chunk.end);
}

t_max_cost	get_max(t_stack *stack, int size)
{
	t_max_cost	max;
	int			p;

	max.value = INT_MIN;
	max.moves = -1;
	max.position = -1;
	p = 0;
	while (stack)
	{
		if (stack->content > max.value)
		{
			if (p > size / 2)
				max.moves = size - p;
			else
				max.moves = p;
			max.value = stack->content;
			max.position = p;
		}
		p++;
		stack = stack->next;
	}
	return (max);
}
