/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:51:23 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/28 19:16:12 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_a *stack_a)
{
	int tempo1;
	int tempo2;
	int i;

	i = size - 2;
	tempo1 = tab[i];
	tab[size - 1] = tab[0];
	while (i > 0)
	{
		tempo2 = tempo1;
		tempo1 = tab[i - 1];
		tab[i - 1] = tempo2;
		i--;
	}
}

void	rb(t_b *stack_b)
{
	int tempo1;
	int tempo2;
	int i;

	i = size - 2;
	tempo1 = tab[i];
	tab[size - 1] = tab[0];
	while (i > 0)
	{
		tempo2 = tempo1;
		tempo1 = tab[i - 1];
		tab[i - 1] = tempo2;
		i--;
	}
}

void	rr(t_b *stack_b, t_a *stack_a)
{
	ra(stack_a);
	rb(stack_b);
}