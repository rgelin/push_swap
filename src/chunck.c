/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:36:59 by rgelin            #+#    #+#             */
/*   Updated: 2021/09/21 13:32:16 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	size_t_list(t_list *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	set_chunck(t_struct *stack)
{
	int		nb_chunck;
	int		chunck_interval;
	int		i;

	find_pos_max(stack, stack->stack_a);
	find_pos_min(stack, stack->stack_a);
	if (size_t_list(stack->stack_a) <= 100)
		nb_chunck = NB_CHUNCK_100;
	else
		nb_chunck = NB_CHUNCK_500;
	chunck_interval = (((long)stack->max - (long)stack->min) / nb_chunck) + 1;
	stack->chunck = (int *)malloc(sizeof(int) * nb_chunck + 1);
	if (!stack->chunck)
		exit(EXIT_FAILURE);
	stack->chunck[nb_chunck] = '\0';
	i = 0;
	while (i < nb_chunck)
	{
		stack->chunck[i] = (long)stack->min + ((i + 1) * chunck_interval);
		i++;
	}
}

void	hold_first(t_struct *stack, int chunck)
{
	t_list	*temp;

	stack->hold_first = stack->stack_a->value;
	stack->pos_first = 0;
	temp = stack->stack_a;
	while (temp)
	{
		if (stack->hold_first <= chunck)
			break ;
		stack->hold_first = temp->next->value;
		stack->pos_first++;
		temp = temp->next;
	}
}

void	hold_second(t_struct *stack, int chunck)
{
	t_list	*temp;

	stack->hold_second = stack->stack_a->value;
	stack->pos_second = 0;
	temp = stack->stack_a;
	while (temp)
	{
		if (temp->value <= chunck)
			stack->hold_second = temp->value;
		temp = temp->next;
	}
	temp = stack->stack_a;
	while (temp->value != stack->hold_second)
	{
		stack->pos_second++;
		temp = temp->next;
	}
}
