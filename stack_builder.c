/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:18:04 by abougati          #+#    #+#             */
/*   Updated: 2025/03/01 12:31:44 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_a(t_stack **a, char **av)
{
	long	n;
	int		i;
	int		j;
	char	**arr;

	i = 0;
	while (av[i])
	{
		arr = ft_split(av[i], ' ');
		if (!arr)
			handle_error(a, NULL);
		j = 0;
		while (arr[j])
		{
			n = ft_atol(arr[j]);
			if (n == LONG_MAX || syntax_error(arr[j])
				|| duplication_error(*a, (int)n)
				|| append_to_stack(a, (int)n))
				handle_error(a, arr);
			j++;
		}
		free_av(arr);
		i++;
	}
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (LONG_MAX);
	}
	return (result * sign);
}

int	append_to_stack(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*last;

	if (!a)
		return (1);
	node = malloc(sizeof(t_stack));
	if (!node)
		return (1);
	node->content = n;
	node->next = NULL;
	if (!(*a))
	{
		node->prev = NULL;
		*a = node;
	}
	else
	{
		last = *a;
		while (last->next)
			last = last->next;
		last->next = node;
		node->prev = last;
	}
	return (0);
}
