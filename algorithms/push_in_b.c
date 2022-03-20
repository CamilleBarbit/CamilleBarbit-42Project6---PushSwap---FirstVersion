/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:28:02 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/20 17:03:40 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Function to check if each element of stack_a is in the LIS or not
*/
int	check_if_in_sub_sequence(t_a *stack_a, int i)
{
	int	j;

	j = 0;
	while (j < stack_a->lis_max)
	{
		if (stack_a->tab[i] == stack_a->sub_sequence[j])
			return (0);
		j++;
	}
	return (1);
}

/*
Function to separate the LIS from the rest
-> the LIS stays in stack_a and the rest goes to stack_b
*/
void	separate_lis(t_a *stack_a, t_a *stack_b)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (check_if_in_sub_sequence(stack_a, 0) == 1)
		{
			push_in_b(stack_a, stack_b, 0);
		}
		if (check_if_in_sub_sequence(stack_a, i) == 1)
		{
			push_in_b(stack_a, stack_b, i);
			i = 0;
		}
		i++;
	}
	free(stack_a->sub_sequence);
}
