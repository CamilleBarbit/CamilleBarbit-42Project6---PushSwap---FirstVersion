/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:16:40 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/20 16:23:41 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
LIBRARIES
*/
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

/*
STRUCTURE TYPE
*/
typedef struct s_a	t_a;
struct s_a
{
	int	size;
	int	*tab;
	int	*lis_tab;
	int	*sub_sequence;
	int	lis_max;
	int	max_pos;
	int	moves[3];
	int	tempo[3];
	int	rr;
	int	rrr;
};

/*
FUNCTIONS DEALING WITH MOVES
*/
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
void	rrr(t_a *stack_a, t_a *stack_b);

/*
FUNCTIONS SORTING THREE & FIVE NUMBERS
*/
void	sort_five(t_a *stack_a, t_a *stack_b);
void	add_top(t_a *stack, int nb);
void	remove_top(t_a *stack);
void	sort_three(t_a *stack_a);

/*
FUNCTIONS IN CHARGE OF THE PARSING
*/
int		arg_is_valid(char *str);
int		check_overflow(char *str1);
int		compare_each_value(char **argv, int i, int argc);
int		check_if_in_order(t_a *stack_a);
int		argv1_is_valid(char **str);
int		check_first_arg(char *str, t_a *stack_a, t_a *stack_b);
int		ft_strcmp(char *s1, char *s2);

/*
FUNCTIONS OF THE MAIN ALGORITHM
*/
void	init_struct(t_a *stack_a, t_a *stack_b, int size);
void	fill_stack_a(t_a *stack_a, char **str, int i);
void	push_in_b(t_a *stack_a, t_a *stack_b, int pos);
void	place_it_on_top(t_a *stack_a, int min_pos);
void	get_sub_sequence(t_a *stack_a);
void	test_lis(t_a *stack_a);
void	set_lis_tab_to_one(t_a *stack_a);
void	find_lis_max(t_a *stack_a);
void	get_lis(t_a *stack_a, t_a *stack_b);
void	separate_lis(t_a *stack_a, t_a *stack_b);
void	check_rr_or_rrr(int *tab);
void	get_pos_a_and_pos_b(t_a *stack_a, t_a *stack_b, int *tab, int pos);
void	compare_total_moves_count(t_a *stack_a, t_a *stack_b);
void	update_better_element(t_a *stack_a);
void	turn_moves_into_action(t_a *stack_a, t_a *stack_b);
void	check_move_in_a(t_a *stack_a);
void	check_move_in_b(t_a *stack_a, t_a *stack_b);
void	check_move_in_a_and_b(t_a *stack_a, t_a *stack_b);
int		look_for_smallest_num(t_a *stack_a);
int		get_lis_max_pos(t_a *stack_a, int lis_max);
int		check_if_in_sub_sequence(t_a *stack_a, int i);
int		count_moves_in_b(t_a *stack_b, int pos);
int		is_nb_max_in_stack(t_a *stack, int nb);
int		look_for_biggest_num(t_a *stack_a);
int		find_closest_nb(t_a *stack_a, int nb);
int		count_moves_in_a(t_a *stack_a, int pos);
int		sum_moves(int *tab);

#endif
