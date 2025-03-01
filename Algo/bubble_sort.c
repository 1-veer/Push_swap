/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sprt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:09:27 by abougati          #+#    #+#             */
/*   Updated: 2025/02/28 18:35:49 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_em(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap_em(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int	*sort_array(t_stack *a)
{
	int	len;
	int	*array;
	int	i;

	if (!a)
		return (NULL);
	len = stack_size(a);
	array = malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	i = 0;
	while (a)
	{
		array[i++] = a->content;
		a = a->next;
	}
	bubble_sort(array, len);
	return (array);
}
