/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:16:40 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/11 14:59:38 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
LIBRARIES
*/

#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"

/*
STRUCTURE
*/

typedef struct s_a	t_a;
struct s_a
{
	int	size;
	int *tab;
	int	*lis_tab;
	int	*sub_sequence;
	int	lis_max;
	int	max_pos;
};

/*
FUNCTIONS
*/

void	add_top(t_a *stack, int nb);
void	remove_top(t_a *stack);
void	pa(t_a *stack_a, t_a *stack_b);
void	pb(t_a *stack_a, t_a *stack_b);
void	ra(t_a *stack_a);
void	rb(t_a *stack_b);
void	rr(t_a *stack_a, t_a *stack_b);
void	sa(t_a *stack_a);
void	sb(t_a *stack_b);
void	ss(t_a *stack_a, t_a *stack_b);
void	rra(t_a *stack_a);
void	rrb(t_a *stack_b);
void	init_struct(t_a *stack_a, t_a *stack_b, int size);
void	fill_stack_a(t_a *stack_a, char **str, int i);
void	push_in_b(t_a *stack_a, t_a *stack_b, int pos);
void	sort_three(t_a *stack_a);
void	sort_five(t_a *stack_a, t_a *stack_b);
void	place_it_on_top(t_a *stack_a, int min_pos);
void	get_sub_sequence(t_a *stack_a);
void	test_lis(t_a *stack_a);
void	find_lis_max(t_a *stack_a);
void	get_lis(t_a *stack_a);
void	separate_lis(t_a *stack_a, t_a *stack_b);
int		arg_is_valid(char *str);
int		check_overflow(char *str1);
int		check_all_args(char **argv, int argc);
int		ft_strcmp(char *s1, char *s2);
int		compare_each_value(char **argv, int i, int argc);
int		check_if_in_order(t_a *stack_a);
int		argv1_is_valid(char **str);
int		check_first_arg(char *str, t_a *stack_a, t_a *stack_b);
int		look_for_smallest_num(t_a *stack_a);
int		get_lis_max_pos(t_a *stack_a, int lis_max);
int		check_if_in_sub_sequence(t_a *stack_a, int i);
int		count_moves_in_b(t_a *stack_b, int pos);
int		is_nb_max_in_stack(t_a *stack, int nb);

#endif
