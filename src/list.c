/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:14:06 by rgelin            #+#    #+#             */
/*   Updated: 2021/09/21 13:41:03 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*add_front(t_list *stack, int x)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		exit(EXIT_FAILURE);
	element->value = x;
	element->next = stack;
	return (element);
}

t_list	*add_back(t_list *stack, int x)
{
	t_list	*element;
	t_list	*temp;

	element = malloc(sizeof(t_list));
	if (!element)
		exit(EXIT_FAILURE);
	element->value = x;
	element->next = NULL;
	if (!stack)
		return (element);
	temp = stack;
	while (temp->next)
		temp = temp->next;
	temp->next = element;
	return (stack);
}

t_list	*remove_back(t_list *stack)
{
	t_list	*temp;
	t_list	*save;

	if (!stack)
		return (NULL);
	if (stack->next == NULL)
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	temp = stack;
	save = stack;
	while (temp->next)
	{
		save = temp;
		temp = temp->next;
	}
	save->next = NULL;
	free(temp);
	temp = NULL;
	return (stack);
}

t_list	*remove_front(t_list *stack)
{
	t_list	*new_t_list;

	if (!stack)
		return (stack);
	new_t_list = stack;
	stack = stack->next;
	free (new_t_list);
	new_t_list = NULL;
	return (stack);
}

t_list	*freet_list(t_list *stack)
{
	t_list	*temp;

	if (!stack)
		return (NULL);
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	free(stack);
	stack = NULL;
	return (stack);
}
