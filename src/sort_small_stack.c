/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:53:14 by rgelin            #+#    #+#             */
/*   Updated: 2021/09/21 13:33:38 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_pos_min(t_struct *stack, t_list *list)
{
	int		min;
	int		i;
	t_list	*temp;

	if (!list)
		return ;
	min = list->value;
	temp = list;
	while (temp->next)
	{
		if (min > temp->next->value)
			min = temp->next->value;
		temp = temp->next;
	}
	i = 0;
	temp = list;
	while (temp->value != min)
	{
		i++;
		temp = temp->next;
	}
	stack->min = min;
	stack->pos_min = i;
}

void	find_pos_max(t_struct *stack, t_list *list)
{
	int		max;
	int		i;
	t_list	*temp;

	if (!list)
		return ;
	max = list->value;
	temp = list;
	while (temp->next)
	{
		if (max < temp->next->value)
			max = temp->next->value;
		temp = temp->next;
	}
	i = 0;
	temp = list;
	while (temp->value != max)
	{
		i++;
		temp = temp->next;
	}
	stack->max = max;
	stack->pos_max = i;
}

t_struct	*sort_3(t_struct *stack)
{
	find_pos_min(stack, stack->stack_a);
	find_pos_max(stack, stack->stack_a);
	if (stack->pos_min == 1 && stack->pos_max == 2)
		sa(stack, 1);
	if (stack->pos_max == 0 && stack->pos_min == 2)
	{
		sa(stack, 1);
		rrx(stack, 'a');
	}
	if (stack->pos_min == 1 && stack->pos_max == 0)
		r(stack, 'a');
	if (stack->pos_min == 0 && stack->pos_max == 1)
	{
		sa(stack, 1);
		r(stack, 'a');
	}
	if (stack->pos_max == 1 && stack->pos_min == 2)
		rrx(stack, 'a');
	return (stack);
}

static t_struct	*sort_5_next_condition(t_struct *stack)
{
	find_pos_min(stack, stack->stack_a);
	if (stack->pos_min == 0)
		p(stack, 'b');
	else if (stack->pos_min == 1)
	{
		sa(stack, 1);
		p(stack, 'b');
	}
	else
	{
		while (stack->stack_a->value != stack->min)
			rrx(stack, 'a');
		p(stack, 'b');
	}
	stack = sort_3(stack);
	while (stack->stack_b)
		p(stack, 'a');
	return (stack);
}

t_struct	*sort_5(t_struct *stack)
{
	find_pos_min(stack, stack->stack_a);
	if (stack->pos_min < 3)
	{
		while (stack->stack_a->value != stack->min)
			r(stack, 'a');
	}
	else
	{
		while (stack->stack_a->value != stack->min)
			rrx(stack, 'a');
	}
	if (is_sorted(stack->stack_a))
		return (stack);
	p(stack, 'b');
	stack = sort_5_next_condition(stack);
	return (stack);
}
