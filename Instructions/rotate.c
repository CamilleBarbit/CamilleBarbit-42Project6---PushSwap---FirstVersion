/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:24:45 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/01 14:33:16 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_a *stack)
{
	int tempo1;
	int tempo2;
	int i;

	i = stack->size - 1;
	tempo1 = stack->tab[i];
	stack->tab[stack->size - 1] = stack->tab[0];
	while (i > 0)
	{
		tempo2 = tempo1;
		tempo1 = stack->tab[i - 1];
		stack->tab[i - 1] = tempo2;
		i--;
	}
	stack->tab[stack->size -1] = tempo1;
}

void	ra(t_a *stack_a)
{
	rotate(stack_b);
}

void	rb(t_a *stack_b)
{
	rotate(stack_b);
}

void	rr(t_a *stack_a, t_a *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
