/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:44:45 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/11 17:23:43 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Function to look for the biggest num in the stack
*/
int	look_for_biggest_num(t_a *stack_a)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = stack_a->tab[0];
	j = 0;
	while (i < stack_a->size)
	{
		if (stack_a->tab[i] > tmp)
		{
			tmp = stack_a->tab[i];
			j = i;
		}
		i++;
	}
	//printf("THE INDEX OF BIGGEST NUM in A: %d\n", j);
	return (j);
}

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

/*
Function to find the position of the number directly inferior to my number -> It must be the closest number > to the one I have in stack_b
*/
int	find_closest_nb(t_a *stack_a, int nb)
{
	int	i;
	int	j;
	int	tempo;
	
	i = 0;
	j = look_for_biggest_num(stack_a);
	tempo = stack_a->tab[j] - nb;
	j = 0;
	while (i < stack_a->size)
	{
		if (stack_a->tab[i] > nb)
		{
			if (stack_a->tab[i] - nb < tempo)
			{
				tempo = stack_a->tab[i] - nb;
				j = i;
			}
		}
		i++;
	}
	return (j);
}