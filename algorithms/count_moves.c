/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:44:45 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/11 15:15:08 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Function to check if my number is the maximum in stack_a or/and stack_b
*/
int	is_nb_max_in_stack(t_a *stack, int nb)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->tab[i] > nb)
			return (0); //mon nombre n'est pas le maximum dans la stack_a ou dans la stack_b
		i++;
	}
	return (1); //mon nombre est le maximum dans la stack_a ou dans la stack_b
}

/*
Function to count the necessary moves to put a number on top of stack_b
*/
int	count_moves_in_b(t_a *stack_b, int pos)
{
	int	count;

	count = 0;
	if (pos > stack_b->size / 2)
	{
		while (pos < stack_b->size)
		{
			count++;
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			count++;
			pos--;
		}
	}
	return (count);
}


int	count_move_in_a(t_a *stack_b, t_a *stack_a, int pos)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = stack_b->size - 1;
	count = 1; //J'intialise count a 1 car dans tous les cas il faut faire pa pour push mon nombre de stack_b a stack_a
	if (stack_a->tab[j] > stack_b->tab[pos] && stack_b->tab[pos] < stack_a->tab[i])
		count++;
	while (i < stack_a->size / 2)
	{
		
	}
}
