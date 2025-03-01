/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:02:08 by abougati          #+#    #+#             */
/*   Updated: 2025/02/27 19:02:09 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_clean(t_stack **a, t_stack **b, char *av)
{
	if (av)
		free(av);
	free_a(a);
	free_a(b);
	write(2, "Error\n", 6);
	exit(1);
}
