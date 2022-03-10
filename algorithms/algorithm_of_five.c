/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_of_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:10:37 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/10 11:56:55 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_in_b(t_a *stack_a, t_a *stack_b, int pos)
{
	if (pos > stack_a->size / 2)
	{
		while (pos < stack_a->size)
		{
			rra(stack_a);
			pos++;
		}
		pb(stack_a, stack_b);
	}
	else
	{
		while (pos > 0)
		{
			ra(stack_a);
			pos--;
		}
		pb(stack_a, stack_b);
	}

}

int	look_for_smallest_num(t_a *stack_a)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = stack_a->tab[0];
	j = 0;
	while (i < stack_a->size)
	{
		if (tmp > stack_a->tab[i])
		{
			tmp = stack_a->tab[i];
			j = i;
		}
		i++;
	}
	return (j);
}

void	sort_five(t_a *stack_a, t_a *stack_b)
{
	int	j;
	int count;

	count = 2;
	while (count > 0)
	{
		j = look_for_smallest_num(stack_a);
		push_in_b(stack_a, stack_b, j);
		count--;
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

