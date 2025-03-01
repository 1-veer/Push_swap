/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:05:30 by abougati          #+#    #+#             */
/*   Updated: 2025/02/28 20:13:04 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_pb(t_stack **head_a, t_stack **head_b)
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
}

void	check_pa(t_stack **head_a, t_stack **head_b)
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
}
