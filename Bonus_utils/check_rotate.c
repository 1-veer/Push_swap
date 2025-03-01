/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:04:37 by abougati          #+#    #+#             */
/*   Updated: 2025/02/27 19:07:12 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_rotate(t_stack **a)
{
	t_stack	*last;
	int		size;

	size = stack_size(*a);
	if (!a || !(*a) || (size == 1))
		return ;
	last = ft_lstlast(*a);
	last->next = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	check_ra(t_stack **a)
{
	check_rotate(a);
}

void	check_rb(t_stack **b)
{
	check_rotate(b);
}

void	check_rr(t_stack **a, t_stack **b)
{
	check_rotate(a);
	check_rotate(b);
}
