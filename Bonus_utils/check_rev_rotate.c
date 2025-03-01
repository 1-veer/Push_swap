/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:05:11 by abougati          #+#    #+#             */
/*   Updated: 2025/02/27 19:05:55 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_rev_rotate(t_stack **a)
{
	t_stack	*last;
	int		size;

	size = stack_size(*a);
	if (!a || !(*a) || size == 1)
		return ;
	last = ft_lstlast(*a);
	last->prev->next = NULL;
	last->next = *a;
	last->prev = NULL;
	*a = last;
	last->next->prev = last;
}

void	check_rra(t_stack **a)
{
	check_rev_rotate(a);
}

void	check_rrb(t_stack **b)
{
	check_rev_rotate(b);
}

void	check_rrr(t_stack **a, t_stack **b)
{
	check_rev_rotate(a);
	check_rev_rotate(b);
}
