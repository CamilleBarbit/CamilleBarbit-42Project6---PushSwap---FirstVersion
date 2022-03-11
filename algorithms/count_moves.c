/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:44:45 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/11 14:48:27 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Function to check if my number is the maximum in stack_a or/and stack_b
*/
int	is_my_number_max_in_stack(t_a *stack, int nb)
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
