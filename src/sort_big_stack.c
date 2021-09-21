/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:06:44 by rgelin            #+#    #+#             */
/*   Updated: 2021/09/21 17:44:51 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ra_or_rra(t_struct *stack)
{
	stack->nb_ra = stack->pos_first;
	stack->nb_rra = size_list(stack->stack_a) - stack->pos_second;
	if (stack->nb_ra <= stack->nb_rra)
		return (1);
	else
		return (0);
}

static int	stack_a_contains_chunck_nb(t_struct *stack, int i)
{
	t_list	*temp;

	temp = stack->stack_a;
	while (temp)
	{
		if (temp->value <= stack->chunck[i])
			return (1);
		temp = temp->next;
	}
	return (0);
}

static t_struct	*push_max_to_a(t_struct *stack)
{
	int	i;

	stack->pos_max = 0;
	find_pos_max(stack, stack->stack_b);
	stack->nb_ra = stack->pos_max;
	stack->nb_rra = size_list(stack->stack_b) - stack->pos_max;
	i = 0;
	if (stack->pos_max <= (size_list(stack->stack_b) / 2))
	{
		while (i++ < stack->nb_ra)
			r(stack, 'b');
	}
	else
	{
		while (i++ < stack->nb_rra)
			rrx(stack, 'b');
	}
	p(stack, 'a');
	return (stack);
}

static t_struct	*push_chunck_to_b(t_struct *stack, int i)
{
	int	j;

	while (stack_a_contains_chunck_nb(stack, i))
	{
		hold_first(stack, stack->chunck[i]);
		hold_second(stack, stack->chunck[i]);
		j = 0;
		if (ra_or_rra(stack))
		{
			while (j++ < stack->nb_ra)
				r(stack, 'a');
		}	
		else
		{
			while (j++ < stack->nb_rra)
				rrx(stack, 'a');
		}
		p(stack, 'b');
	}
	return (stack);
}

t_struct	*sort_big_stack(t_struct *stack)
{
	int	i;
	int	nb_chunck;

	i = -1;
	set_chunck(stack);
	stack->pos_max = 0;
	if (size_list(stack->stack_a) <= 100)
		nb_chunck = NB_CHUNCK_100;
	else
		nb_chunck = NB_CHUNCK_500;
	while (i++ < nb_chunck)
		stack = push_chunck_to_b(stack, i);
	while (stack->stack_a)
		p(stack, 'b');
	while (stack->stack_b)
		stack = push_max_to_a(stack);
	free(stack->chunck);
	stack->chunck = NULL;
	return (stack);
}
