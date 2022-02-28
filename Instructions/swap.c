/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:20:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/28 18:56:05 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_a stack_a)
{
	int tempo;

	if (stack_a->size_a <= 1)
		return ;
	temp = stack_a->tab_a[0];
	stack_a->tab_a[0] = stack_a->tab_a[1];
	stack_a->tab_a[1] = tempo;
}

void	sb(t_b stack_b)
{
	int tempo;

	if (stack_b->size_a <= 1)
		return ;
	temp = stack_b->tab_b[0];
	stack_b->tab_b[0] = stack_b->tab_b[1];
	stack_a->tab_b[1] = tempo;
}

void	ss(t_a stack_a, t_b stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
