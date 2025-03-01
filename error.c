/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:52:22 by abougati          #+#    #+#             */
/*   Updated: 2025/02/27 18:54:37 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(t_stack **a, char **av)
{
	if (av)
		free_av(av);
	free_a(a);
	write(2, "Error\n", 6);
	exit(1);
}

int	syntax_error(char *av)
{
	if (!av || !*av)
		return (1);
	if (!(av[0] == '+' || av[0] == '-' || (av[0] >= '0' && av[0] <= '9')))
		return (1);
	if ((av[0] == '+' || av[0] == '-') && !(av[1] >= '0' && av[1] <= '9'))
		return (1);
	while (*++av)
	{
		if (!(*av >= '0' && *av <= '9'))
			return (1);
	}
	return (0);
}

int	duplication_error(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->content == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_a(t_stack **a)
{
	t_stack	*current;
	t_stack	*next_current;

	if (!a)
		return ;
	current = *a;
	while (current != NULL)
	{
		next_current = current->next;
		current->content = 0;
		free(current);
		current = next_current;
	}
	*a = NULL;
}

void	free_av(char **av)
{
	int	i;

	if (!av)
		return ;
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
