/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:53:58 by rgelin            #+#    #+#             */
/*   Updated: 2021/09/21 13:32:16 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_struct	*p(t_struct *stack, char c)
{
	t_list	*element;

	if (c == 'a')
	{
		if (!stack->stack_b)
			return (stack);
		element = stack->stack_b;
		stack->stack_a = add_front(stack->stack_a, element->value);
		stack->stack_b = remove_front(stack->stack_b);
		write (1, "pa\n", 3);
	}
	else if (c == 'b')
	{
		if (!stack->stack_a)
			return (stack);
		element = stack->stack_a;
		stack->stack_b = add_front(stack->stack_b, element->value);
		stack->stack_a = remove_front(stack->stack_a);
		write (1, "pb\n", 3);
	}
	return (stack);
}

t_struct	*r(t_struct *stack, char c)
{
	t_list	*element;

	if (c == 'a')
	{
		if (!stack->stack_a)
			return (stack);
		element = stack->stack_a;
		stack->stack_a = remove_front(stack->stack_a);
		stack->stack_a = add_back(stack->stack_a, element->value);
		write (1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		if (!stack->stack_b)
			return (stack);
		element = stack->stack_b;
		stack->stack_b = remove_front(stack->stack_b);
		stack->stack_b = add_back(stack->stack_b, element->value);
		write (1, "rb\n", 3);
	}
	return (stack);
}

t_struct	*rr(t_struct *stack)
{
	t_list	*element;

	if (stack->stack_a && stack->stack_b)
	{
		element = stack->stack_a;
		stack->stack_a = remove_front(stack->stack_a);
		stack->stack_a = add_back(stack->stack_a, element->value);
		element = stack->stack_b;
		stack->stack_b = remove_front(stack->stack_b);
		stack->stack_b = add_back(stack->stack_b, element->value);
		write (1, "rr\n", 3);
	}
	return (stack);
}

t_struct	*rrx(t_struct *stack, char c)
{
	t_list	*temp;

	if (c == 'a')
	{
		if (!stack->stack_a)
			return (stack);
		temp = stack->stack_a;
		while (temp->next)
			temp = temp->next;
		stack->stack_a = remove_back(stack->stack_a);
		stack->stack_a = add_front(stack->stack_a, temp->value);
		write (1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		if (!stack->stack_b)
			return (stack);
		temp = stack->stack_b;
		while (temp->next)
			temp = temp->next;
		stack->stack_b = remove_back(stack->stack_b);
		stack->stack_b = add_front(stack->stack_b, temp->value);
		write (1, "rrb\n", 4);
	}
	return (stack);
}

t_struct	*rrr(t_struct *stack)
{
	t_list	*temp_a;
	t_list	*temp_b;

	if (stack->stack_a && stack->stack_b)
	{
		temp_a = stack->stack_a;
		while (temp_a->next)
			temp_a = temp_a->next;
		stack->stack_a = remove_back(stack->stack_a);
		stack->stack_a = add_front(stack->stack_a, temp_a->value);
		temp_b = stack->stack_b;
		while (temp_b->next)
			temp_b = temp_b->next;
		stack->stack_b = remove_back(stack->stack_b);
		stack->stack_b = add_front(stack->stack_b, temp_b->value);
		write (1, "rrr\n", 4);
	}
	return (stack);
}
