/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:55:36 by abougati          #+#    #+#             */
/*   Updated: 2025/02/27 18:56:17 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*node;

	if (!head_a || !head_b || !*head_a)
		return ;
	node = *head_a;
	*head_a = (*head_a)->next;
	if (*head_a)
		(*head_a)->prev = NULL;
	node->next = *head_b;
	if (*head_b)
		(*head_b)->prev = node;
	*head_b = node;
	node->prev = NULL;
	write(1, "pb\n", 3);
}

void	pa(t_stack **head_a, t_stack **head_b)
{
	t_stack	*node;

	if (!head_a || !head_b || !*head_b)
		return ;
	node = *head_b;
	*head_b = (*head_b)->next;
	if (*head_b)
		(*head_b)->prev = NULL;
	node->next = *head_a;
	if (*head_a)
		(*head_a)->prev = node;
	*head_a = node;
	node->prev = NULL;
	write(1, "pa\n", 3);
}
