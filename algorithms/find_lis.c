/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:32:09 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/21 14:06:21 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static void	print_stack(int *tab, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d\n", tab[i]);
// 		i++;
// 	}
// }

/*
Step 3: Function to get sub_sequence (which actually corresponds to the LIS)
*/
void	get_sub_sequence(t_a *stack_a)
{
	int	i;
	int	j;
	int	k;

	stack_a->sub_sequence = malloc(sizeof(int) * stack_a->lis_max);
	if (!stack_a->sub_sequence)
		return ;
	i = stack_a->max_pos;
	k = stack_a->lis_max - 1;
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
	free(stack_a->lis_tab);
}

/*
Step 2: Function to actually get the length of the LIS 
and its index in stack_a->lis_tab
*/
void	find_lis_max(t_a *stack_a)
{
	int	i;

	i = 0;
	stack_a->lis_max = 1;
	while (i < stack_a->size)
	{
		if (stack_a->lis_max < stack_a->lis_tab[i])
		{
			stack_a->lis_max = stack_a->lis_tab[i];
			stack_a->max_pos = i;
		}
		i++;
	}
}

/*
Step 1: Function to determine all the possible sequences of ordered numbers
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
			if (stack_a->tab[i] > stack_a->tab[j]
				&& stack_a->lis_tab[i] < stack_a->lis_tab[j] + 1)
			{
				stack_a->lis_tab[i] = stack_a->lis_tab[j] + 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
