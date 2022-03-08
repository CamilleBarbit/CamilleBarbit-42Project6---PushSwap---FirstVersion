/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:03:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/08 12:14:10 by cbarbit          ###   ########.fr       */
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
		printf("%d\n", tab[i++]);
	}
}

/*
Function to place the minimum on top: STEP 1
*/

void	place_it_on_top(t_a *stack_a, int min)
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
FUNCTION TO FIND LIS LENGTH
*/
int	lis_length(int *tmp, t_a *stack_a)
{
	int	lis_max;
	int	i;
	int	lis_tab[stack_a->size];
	int	sub_sequence[stack_a->size];
	int	j;

	i = 0;
	j = 0;
	lis_max = 1;
	//Initialize lis_tab with only 1s - lis_max is 1
	while (i < stack_a->size)
		lis_tab[i++] = 1;
	i = 1;
	while (i < stack_a->size)
	{
		while (j < i)
		{
			if (tmp[i] > tmp[j] && lis_tab[i] < lis_tab[j] + 1)
			{
				lis_tab[i] = lis_tab[j] + 1;
				sub_sequence[i] = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	//Il faudrait envoyer la suite dans une fonction pour recuperer l'indice de lis_max
	i = 0;
	while(i < stack_a->size)
	{
		if (lis_max < lis_tab[i])
		{
			lis_max = lis_tab[i];
		}
		i++;
	}
	printf("TAB LIS:\n");
	print_tab(lis_tab, stack_a->size);
	printf("LEN_LIS: %d\n", lis_max);
	printf("INDICE SUB_SEQUENCE:\n");
	print_tab(sub_sequence, stack_a->size);
	return (lis_max);
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
		place_it_on_top(stack_a, j);
	while (k < stack_a->size)
	 	tmp[k++] = stack_a->tab[i++];
	//print_tab(stack_a->tab, 10);
	// printf("\n\n\n");
	//print_tab(tmp, 10);
	printf("TAB TEMP:\n");
	print_tab(tmp, stack_a->size);
	lis_length(tmp, stack_a);

}
