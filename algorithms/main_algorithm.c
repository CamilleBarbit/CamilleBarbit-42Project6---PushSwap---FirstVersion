/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:03:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/07 16:22:19 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
FONCTION DE TEST POUR AFFICHER LE TABLEAU TRIE
*/

static void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("TABLEAU: %d\n", tab[i++]);
	}
}

/*
Function to place the minimum on top: STEP 1
*/

void	place_in_on_top(t_a *stack_a, int min)
{
	if (min > stack_a->size / 2)
	{
		while (min < stack_a->size)
		{
			rra(stack_a);
			min++;
		}
	}
	else
	{
		while (min > 0)
		{
			ra(stack_a);
			min--;
		}
	}
}

/*
FUNCTION TO FIND LIS
*/

// int	find_lis_length(int *tmp, t_a *stack_a)
// {
// 	int	lis[stack_a->size];
// 	int	i;
// 	int	j;

// 	lis[0] = 1;
// 	i = 1;
// 	j = 0;
// 	while(i < stack_a->size)
// 	{
// 		lis[i] = 1;
// 		j = i - 1;
// 		while(j < i)
// 		{
// 			if (stack_a->tab[i] > stack_a->tab[j] && lis[i] < lis[j] + 1])
// 				lis[i]= lis[j] + 1;
// 		i++;
// 	}
// }

int	look_for_biggest_lis(int *tab, t_a *stack_a)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = tab[0];
	j = 0;
	while (i < stack_a->size)
	{
		if (tmp < tab[i])
		{
			tmp = tab[i];
			j = i;
		}
		i++;
	}
	printf("INDICE DE LA LIS: %d", j);
	return (j);
}

static int	test_lis(int *tmp, t_a *stack_a)
{
	int	i;
	int	j;
	int	tab_lis[stack_a->size];
	int	lis;
	int	max_lis;
	int	k;

	i = 0;
	j = 1;
	lis = 1;
	k = 0;
	while (i < stack_a->size)
	{
		lis = 1;
		while(j < stack_a->size)
		{
			if (tmp[j] > tmp[i])
			{
				lis++;
				i++;
			}
			j++;
		}
		tab_lis[k++] = lis;
		i++;
	}
	max_lis = look_for_biggest_lis(tab_lis, stack_a);
	return (max_lis);
}

/*
Function to find copy stack_a in tmp: STEP 2
*/

void	whatever(t_a *stack_a)
{
	int	j;
	int	tmp[stack_a->size];
	int	i;
	int	k;

	j = look_for_smallest_num(stack_a);
	i = 0;
	k = 0;
	if (j != 0)
		place_in_on_top(stack_a, j);
	while (k < stack_a->size)
	 	tmp[k++] = stack_a->tab[i++];
	//print_tab(stack_a->tab, 10);
	// printf("\n\n\n");
	print_tab(tmp, 10);
	test_lis(tmp, stack_a);

}
