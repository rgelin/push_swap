/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 23:02:11 by rgelin            #+#    #+#             */
/*   Updated: 2021/09/21 12:58:09 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_condition(char *arg[], int i)
{
	int	j;

	j = i + 1;
	if (ft_atoi(arg[i]) > INT_MAX || ft_atoi(arg[i]) < INT_MIN
		|| (!is_digit(arg[i])))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (arg[j])
	{
		if (ft_atoi(arg[i]) == ft_atoi(arg[j]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		j++;
	}
	return (0);
}

int	check_error_one_arg(char *av[])
{
	char	**tab;
	int		nb_arg;
	int		i;

	tab = ft_split(av[1], ' ');
	nb_arg = count_words(av[1], ' ');
	i = 0;
	while (i < nb_arg)
	{
		if (error_condition(tab, i))
			return (1);
		i++;
	}
	free_tab(tab, nb_arg);
	return (0);
}

int	check_error_multiple_arg(int ac, char *av[])
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (error_condition(av, i))
			return (1);
		i++;
	}
	return (0);
}

void	free_tab(char **tab, int nb_arg)
{
	int	i;

	i = 0;
	while (i < nb_arg)
		free(tab[i++]);
	free(tab);
}

int	check_error(int ac, char *av[])
{
	if (ac == 2)
	{
		if (check_error_one_arg(av))
			return (1);
	}
	else
	{
		if (check_error_multiple_arg(ac, av))
			return (1);
	}
	return (0);
}
