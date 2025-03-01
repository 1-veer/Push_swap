/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:08:38 by abougati          #+#    #+#             */
/*   Updated: 2025/03/01 00:31:08 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	determine_range(int size)
{
	int	range;

	if (!size)
		return (0);
	if (size <= 6)
		range = 2;
	else if (size <= 16)
		range = 3;
	else if (size <= 100)
		range = 13;
	else if (size <= 500)
		range = 30;
	else
		range = 45;
	return (range);
}

void	push_to_b(t_stack **a, t_stack **b, int *i,
		t_chunk right_chunk)
{
	if ((*a) && is_in_chunk((*a)->content, right_chunk))
	{
		if (stack_size(*b) >= 2)
		{
			if ((*b)->next && (*b)->content < (*b)->next->content)
				sb(b);
		}
		pb(a, b);
		(*i)++;
	}
	else if ((*a)->content < right_chunk.start)
	{
		pb(a, b);
		rb(b);
		(*i)++;
	}
	else
		sorted_in_reverse(a);
}

void	push_back_to_a(t_stack **b, t_stack **a)
{
	t_max_cost	max;
	int			b_size;

	if (!*b)
		return ;
	while (*b)
	{
		b_size = stack_size(*b);
		if (!b_size)
			return ;
		max = get_max(*b, b_size);
		if (max.moves != -1 && (max.position <= b_size / 2))
		{
			while (max.position-- > 0)
				rb(b);
		}
		else
		{
			while (max.position++ < b_size)
				rrb(b);
		}
		pa(a, b);
	}
}

void	sorted_in_reverse(t_stack **a)
{
	t_stack	*tmp;
	int		len;
	int		j;

	j = 0;
	tmp = *a;
	len = stack_size(*a);
	while ((tmp)->next)
	{
		if ((tmp)->content > (tmp)->next->content)
			j++;
		tmp = (tmp)->next;
	}
	j++;
	if (j == len)
		rra(a);
	else
		ra(a);
}

void	main_sort(t_stack **a, t_stack **b)
{
	int		size;
	int		chunk;
	int		*sorted;
	t_chunk	currect_chunk;
	int		i;

	size = stack_size(*a);
	sorted = sort_array(*a);
	if (!sorted || !*a)
	{
		free(sorted);
		return ;
	}
	chunk = determine_range(size);
	i = 0;
	while (*a)
	{
		if (i > size - chunk)
			i = size - chunk;
		currect_chunk.start = sorted[i];
		currect_chunk.end = sorted[is_smaller((i + 1) + (chunk - 1), size - 1)];
		push_to_b(a, b, &i, currect_chunk);
	}
	push_back_to_a(b, a);
	free(sorted);
}
