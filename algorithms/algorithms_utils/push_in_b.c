/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:28:02 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/10 11:53:01 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".../push_swap.h"

void	check_if_in_sub_sequence(t_a *stack_a, t_a *stack_b)
{
	int i;
	int j;

	i = 0;
	j = 0
	while (i < stack_a->size)
	{
		while (j < stack_a->lis_max)
		{
			if (stack_a->tab[i] == stack_a->sub_sequence[j])
				i++;
			j++;
		}
		push_in_b(stack_a, stack_b, i);
		j = 0;    
	}
}