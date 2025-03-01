/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:36:58 by abougati          #+#    #+#             */
/*   Updated: 2025/02/28 17:12:36 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_action(t_stack **a, t_stack **b, char *action)
{
	if (!ft_strcmp(action, "sa\n"))
		check_sa(a);
	else if (!ft_strcmp(action, "sb\n"))
		check_sb(b);
	else if (!ft_strcmp(action, "ss\n"))
		check_ss(a, b);
	else if (!ft_strcmp(action, "pa\n"))
		check_pa(a, b);
	else if (!ft_strcmp(action, "pb\n"))
		check_pb(a, b);
	else if (!ft_strcmp(action, "ra\n"))
		check_ra(a);
	else if (!ft_strcmp(action, "rb\n"))
		check_rb(b);
	else if (!ft_strcmp(action, "rr\n"))
		check_rr(a, b);
	else if (!ft_strcmp(action, "rra\n"))
		check_rra(a);
	else if (!ft_strcmp(action, "rrb\n"))
		check_rrb(b);
	else if (!ft_strcmp(action, "rrr\n"))
		check_rrr(a, b);
	else
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*action;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	initialize_a(&a, argv + 1);
	action = get_next_line(0);
	while (action)
	{
		if (!execute_action(&a, &b, action))
			(free(action), error_clean(&a, &b, NULL));
		free(action);
		action = get_next_line(0);
	}
	if (already_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_a(&a);
	free_a(&b);
	return (0);
}
