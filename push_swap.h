/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:10:52 by rgelin            #+#    #+#             */
/*   Updated: 2021/09/21 13:36:08 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}				t_list;

typedef struct s_struct
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		min;
	int		max;
	int		pos_min;
	int		pos_max;
	int		*chunck;
	int		hold_first;
	int		pos_first;
	int		hold_second;
	int		pos_second;
	int		nb_ra;
	int		nb_rra;
}				t_struct;

int			is_digit(char *str);
long		ft_atoi(char *str);
char		**ft_split(char const *s, char c);
int			count_words(char const *str, char c);

void		free_tab(char **tab, int nb_arg);
int			check_error_multiple_arg(int ac, char *av[]);
int			check_error_one_arg(char *av[]);
int			check_error(int ac, char *av[]);
int			is_sorted(t_list *stack);

t_list		*add_front(t_list *stack, int x);
t_list		*add_back(t_list *stack, int x);
t_list		*remove_back(t_list *stack);
t_list		*remove_front(t_list *stack);
t_list		*freet_list(t_list *stack);
int			size_t_list(t_list *stack);

t_struct	*p(t_struct *stack, char c);
t_struct	*r(t_struct *stack, char c);
t_struct	*rr(t_struct *stack);
t_struct	*rrx(t_struct *stack, char c);
t_struct	*rrr(t_struct *stack);
t_struct	*sa(t_struct *stack, int x);
t_struct	*sb(t_struct *stack, int x);
t_struct	*ss(t_struct *stack);

void		find_pos_min(t_struct *stack, t_list *t_list);
void		find_pos_max(t_struct *stack, t_list *t_list);
t_struct	*sort_3(t_struct *stack);
t_struct	*sort_5(t_struct *stack);

void		set_chunck(t_struct *stack);
void		hold_first(t_struct *stack, int chunck);
void		hold_second(t_struct *stack, int chunck);
t_struct	*sort_big_stack(t_struct *stack);

# define	NB_CHUNCK_100	5
# define	NB_CHUNCK_500	11

#endif