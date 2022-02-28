/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:01:31 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/28 18:40:47 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_top(int *tab, int nb, int size)
{
	int tempo1;
	int tempo2;
	int i;
    
	i = 0;
	tempo1 = tab[0];
	while (i < size)
	{
		tempo2 = tempo1;
		tempo1 = tab[i + 1];
		tab[i + 1] = tempo2;
		i++;
	}
	tab[0] = nb;
	size += 1;  
}

void	remove_top(int *tab, int size)
{
	int tempo1;
	int tempo2;
	int i;

	i = size - 1;
	tempo1 = tab[i];
	while (i > 0)
	{
		tempo2 = tempo1;
		tempo1 = tab[i - 1];
		tab[i - 1] = tempo2;
		i--;
	}
	size -= 1;
}

void	pa(t_stacks *stack_a, t_stacks *stack_b)
{
	add_top(stack_a->tab_a, stack_b->tab_b[0], stack_a->size_a);
	remove_top(stack_b->tab_b, stack_b->size_b);
}

void	pb(t_stacks *stack_a, t_stacks *stack_b)
{
	add_top(stack_b->tab_b, stack_a->tab_a[0], stack_b->size_b);
	remove_top(stack_a->tab_a, stack_a->size_a);
}
