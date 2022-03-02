/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:50:58 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/02 11:48:03 by cbarbit          ###   ########.fr       */
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
	int	size_a;
	int	size_b;
	int *tab_a;
	int *tab_b;
	

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
void	init_struct(t_a *stack, int argc);
void	fill_tab_a(t_a *stack, char *str);
int		arg_is_valid(char *str);
int		check_overflow(char *str1);








#endif
