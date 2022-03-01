/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:50:58 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/01 12:07:31 by cbarbit          ###   ########.fr       */
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
STRUCTURES
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


#endif
