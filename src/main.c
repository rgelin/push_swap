/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:51:44 by rgelin            #+#    #+#             */
/*   Updated: 2021/09/21 13:43:55 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *stack)
{
	int	x;

	x = stack->value;
	while (stack->next)
	{
		if (x > stack->next->value)
			return (0);
		x = stack->next->value;
		stack = stack->next;
	}
	return (1);
}

static t_list	*init_stack_a(t_list *stack, int ac, char *av[])
{
	int		i;
	char	**tab;
	int		nb_arg;

	tab = ft_split(av[1], ' ');
	if (!tab)
		exit (EXIT_FAILURE);
	nb_arg = count_words(av[1], ' ');
	if (ac == 2)
	{
		i = 0;
		while (i < nb_arg)
			stack = add_back(stack, ft_atoi(tab[i++]));
	}
	else
	{
		i = 1;
		while (i < ac)
			stack = add_back(stack, ft_atoi(av[i++]));
	}
	free_tab(tab, nb_arg);
	return (stack);
}

static void	init_struct(t_struct *stack)
{
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->min = 0;
	stack->max = 0;
	stack->pos_min = 0;
	stack->pos_max = 0;
	stack->chunck = NULL;
	stack->hold_first = 0;
	stack->pos_first = 0;
	stack->hold_second = 0;
	stack->pos_second = 0;
	stack->nb_ra = 0;
	stack->nb_rra = 0;
}

static void	ft_free(t_struct *stack)
{
	freet_list(stack->stack_a);
	freet_list(stack->stack_b);
	free(stack);
}

int	main(int ac, char *av[])
{
	t_struct	*stack;

	if (ac == 1 || check_error(ac, av))
		return (-1);
	stack = (t_struct *)malloc(sizeof(t_struct));
	if (!stack)
		exit(EXIT_FAILURE);
	init_struct(stack);
	stack->stack_a = init_stack_a(stack->stack_a, ac, av);
	if (is_sorted(stack->stack_a))
	{
		ft_free(stack);
		return (0);
	}
	if (size_t_list(stack->stack_a) == 3)
		stack = sort_3(stack);
	else if (size_t_list(stack->stack_a) == 5)
		stack = sort_5(stack);
	else
		stack = sort_big_stack(stack);
	ft_free(stack);
	return (0);
}
