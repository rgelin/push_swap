/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:08:25 by rgelin            #+#    #+#             */
/*   Updated: 2021/09/21 13:32:16 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_struct	*sa(t_struct *stack, int x)
{
	t_list	*element;
	t_list	*cur;
	t_list	*temp;

	if (stack->stack_a == NULL || stack->stack_a->next == NULL)
		return (stack);
	element = malloc(sizeof(t_list));
	if (!element)
		exit(EXIT_FAILURE);
	element->value = stack->stack_a->next->value;
	element->next = NULL;
	cur = stack->stack_a->next;
	temp = stack->stack_a;
	temp->next = cur->next;
	free (cur);
	stack->stack_a = add_front(stack->stack_a, element->value);
	if (x == 1)
		write(1, "sa\n", 3);
	free (element);
	element = NULL;
	return (stack);
}

t_struct	*sb(t_struct *stack, int x)
{
	t_list	*element;
	t_list	*cur;
	t_list	*temp;

	if (stack->stack_b == NULL || stack->stack_b->next == NULL)
		return (stack);
	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->value = stack->stack_b->next->value;
	element->next = NULL;
	cur = stack->stack_b->next;
	temp = stack->stack_b;
	temp->next = cur->next;
	free (cur);
	stack->stack_b = add_front(stack->stack_b, element->value);
	if (x == 1)
		write(1, "sb\n", 3);
	free (element);
	element = NULL;
	return (stack);
}

t_struct	*ss(t_struct *stack)
{
	if (stack->stack_a && stack->stack_b)
	{
		stack = sa(stack, 2);
		stack = sb(stack, 2);
		write (1, "ss\n", 3);
	}
	return (stack);
}
