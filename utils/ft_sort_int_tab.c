/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:32:34 by rgelin            #+#    #+#             */
/*   Updated: 2021/09/21 17:44:04 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*put_in_tab(t_struct *stack)
{
	int		*tab;
	int		i;
	t_list	*temp;

	tab = malloc(sizeof(int) * size_list(stack->stack_a) + 1);
	if (!tab)
		exit (EXIT_FAILURE);
	i = 0;
	temp = stack->stack_a;
	while (temp)
	{
		tab[i] = temp->value;
		i++;
		temp = temp->next;
	}
	tab[i] = '\0';
	return (tab);
}

int	*ft_sort_int_tab(t_struct *stack)
{
	int	i;
	int	j;
	int	temp;
	int	*tab;

	j = 0;
	tab = put_in_tab(stack);
	i = 0;
	while (j < size_list(stack->stack_a) - 1)
	{
		i = 0;
		while (i < size_list(stack->stack_a) - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
	return (tab);
}
