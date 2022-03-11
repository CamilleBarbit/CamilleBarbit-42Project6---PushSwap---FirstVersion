/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:44:45 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/11 17:51:36 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Function to look for the biggest num in the stack -> it returns its index
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
	int	k;
	
	i = 0;
	j = look_for_biggest_num(stack_a);
	tempo = stack_a->tab[j] - nb;
	k = j;
	while (i < stack_a->size)
	{
		if (stack_a->tab[i] > nb)
		{
			if (stack_a->tab[i] - nb < tempo)
			{
				tempo = stack_a->tab[i] - nb;
				k = i;
			}
		}
		i++;
	}
	return (k); // this is the index of the closest following number
}

/*
Function that counts the number of moves to put a number from stack_b to its right place in stack_a
*/
int	count_moves_in_a(t_a *stack_a, int pos)
{
	int	count;

	count = 1;
	if (pos > stack_a->size / 2)
	{
		while (pos < stack_a->size)
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
	printf("NOMBRE DE MOVES POUR METTRE LE NB AU TOP: %d\n", count);
	return (count);
}