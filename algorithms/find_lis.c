/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:32:09 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/09 16:38:22 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Step 4: Function to get the position of lis_max in stack_a->lis_tab
*/
int	get_lis_max_pos(t_a *stack_a, int lis_max)
{
	int	i;

	i = 0;
	while(stack_a->lis_tab[i] && stack_a->lis_tab[i] != lis_max)
		i++;
	return (i);
}

/*
Step 5: Function to get sub_sequence (which actually corresponds to the LIS)
*/
void	get_sub_sequence(t_a *stack_a, int lis_max, int lis_max_pos)
{
	int	i;
	int	j;
	int	k;

	stack_a->sub_sequence = malloc(sizeof(int) * lis_max);
	if (!stack_a->sub_sequence)
		return ;
	i = lis_max_pos; //11 dans ce cas
	k = lis_max - 1; // vaut 5 (index pour se deplacer dans sub_sequent)
	j = i - 1;
	stack_a->sub_sequence[k] = stack_a->tab[i];
	while (j >= 0)
	{
		if (stack_a->lis_tab[i] - stack_a->lis_tab[j] == 1)
		{
			k--;
			stack_a->sub_sequence[k] = stack_a->tab[j];
			i = j;
		}
		j--;
	}
	free(stack_a->lis_tab); //je free lis_tab, car je n'en ai plus besoin
	// k = 0;
	// while (k < lis_max)
	// {
	// 	printf("%d\n", stack_a->sub_sequence[k]);
	// 	k++;
	// }
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
Step 3: Function to actually get the length of the longest LIS
*/
int	find_lis_max(t_a *stack_a)
{
	int	i;
	int	lis_max;

	i = 0;
	lis_max = 1;
	while (i < stack_a->size)
	{
		if (lis_max < stack_a->lis_tab[i])
			lis_max = stack_a->lis_tab[i];
		i++;

	}
	return (lis_max);
}
/*
Step 2: Function to determine all the possible sequences of ordered numbers
*/
void	test_lis(t_a *stack_a)
{
	int	i;
	int	j;

	j = 0;
	stack_a->lis_tab = malloc(sizeof(int) * stack_a->size);
	if (!stack_a->lis_tab)
		return ;
	set_lis_tab_to_one(stack_a);
	i = 1;
	while (i < stack_a->size)
	{
		while (j < i)
		{
			if (stack_a->tab[i] > stack_a->tab[j] && stack_a->lis_tab[i] < stack_a->lis_tab[j] + 1)
			{
				stack_a->lis_tab[i] = stack_a->lis_tab[j] + 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
