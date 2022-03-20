/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_of_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:10:37 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/20 17:03:10 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Function to push numbers from stack_a to stack_b
depending on their position in stack_a
*/
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

void	sort_five(t_a *stack_a, t_a *stack_b)
{
	int	j;
	int	count;

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
