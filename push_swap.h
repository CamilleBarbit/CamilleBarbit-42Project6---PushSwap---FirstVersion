/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:16:40 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/08 14:04:33 by cbarbit          ###   ########.fr       */
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
void	push_min(t_a *stack_a, t_a *stack_b, int min);
void	sort_three(t_a *stack_a);
void	sort_five(t_a *stack_a, t_a *stack_b);
int		arg_is_valid(char *str);
int		check_overflow(char *str1);
int		check_all_args(char **argv, int argc);
int		ft_strcmp(char *s1, char *s2);
int		compare_each_value(char **argv, int i, int argc);
int		check_if_in_order(t_a *stack_a);
int		argv1_is_valid(char **str);
int		check_first_arg(char *str, t_a *stack_a, t_a *stack_b);
int		look_for_smallest_num(t_a *stack_a);
int		find_all_lis(int *tmp, t_a *stack_a);
int		find_lis_max(t_a *stack_a, int *lis_tab);
void	whatever(t_a *stack_a);

#endif
