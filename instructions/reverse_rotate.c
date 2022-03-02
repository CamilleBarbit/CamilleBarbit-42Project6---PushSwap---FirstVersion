/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:51:23 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/01 14:32:52 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_a *stack)
{
	int tempo1;
	int tempo2;
	int i;

	i = 0;
	tempo1 = stack->tab[0];
	while (i < stack->size)
	{
		tempo2 = tempo1;
		tempo1 = stack->tab[i + 1];
		stack->tab[i + 1] = tempo2;
		i++;
	}
	stack->tab[0] = tempo2;
}

void	rra(t_a *stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_a *stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_a *stack_a, t_a *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}