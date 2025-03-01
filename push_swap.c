/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:16:50 by abougati          #+#    #+#             */
/*   Updated: 2025/02/28 18:22:53 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	initialize_a(&a, av + 1);
	if (!already_sorted(a))
	{
		if (stack_size(a) <= 3)
			sort_2_or_3(&a);
		else if (stack_size(a) == 5 || stack_size(a) == 4)
			sort_4_or_5(&a, &b);
		else
			main_sort(&a, &b);
	}
	free_a(&a);
	free_a(&b);
	return (0);
}
