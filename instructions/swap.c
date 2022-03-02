/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:20:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/01 14:35:23 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	swap(t_a *stack)
{
	int tempo;

	if (stack->size <= 1)
		return ;
	tempo = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tempo;
}

void	sa(t_a *stack_a)
{
	swap(stack_a);
}

void	sb(t_a *stack_b)
{
	swap(stack_b);
}

void	ss(t_a *stack_a, t_a *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
