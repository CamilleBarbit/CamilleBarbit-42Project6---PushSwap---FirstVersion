/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:51:23 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/01 12:36:08 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_a *stack_a)
{
	int tempo1;
	int tempo2;
	int i;

	i = 0;
	tempo1 = stack_a->tab[0];
	while (i < stack_a->size)
	{
		tempo2 = tempo1;
		tempo1 = stack_a->tab[i + 1];
		stack_a->tab[i + 1] = tempo2;
		i++;
	} 
	stack_a->tab[0] = tempo2;
}

void	rrb(t_a *stack_b)
{
	int tempo1;
	int tempo2;
	int i;

	i = 0;
	tempo1 = stack_b->tab[0];
	while (i < stack_b->size)
	{
		tempo2 = tempo1;
		tempo1 = stack_b->tab[i + 1];
		stack_b->tab[i + 1] = tempo2;
		i++;
	} 
	stack_b->tab[0] = tempo2;
}

void	rrr(t_a *stack_a, t_a *stack_b)
{
	rra(t_a *stack_a);
	rrb(t_a *stack_b);
}