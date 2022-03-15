/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:24:40 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/15 11:00:38 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/***************** FUNCTION USED IN BOTH THE MAIN ALGORITHM AND THE ALGORITHM OF FIVE*****************/
/*
Function to look for the smallest number in stack_a, in order to put it on top
*/
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

/***************** FUNCTION USED IN THE MAIN ALGORITHM*****************/
/*
Function to place the minimum on top of stack_a->tab if need be
*/
void	place_it_on_top(t_a *stack_a, int min_pos)
{
	if (min_pos > stack_a->size / 2)
	{
		while (min_pos < stack_a->size)
		{
			rra(stack_a);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
}


/*
Function to set stack_a->lis_tab to 1s
*/
void	set_lis_tab_to_one(t_a *stack_a)
{
	int	i;

	i = 0;
	while(i < stack_a->size)
		stack_a->lis_tab[i++] = 1;
}


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
