/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:03:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/09 16:00:32 by cbarbit          ###   ########.fr       */
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

static int	get_lis_max_pos(t_a *stack_a, int lis_max)
{
	int	i;

	i = 0;
	while(stack_a->lis_tab[i] && stack_a->lis_tab[i] != lis_max)
		i++;
	return (i);
}


/*
Function to get sb_sequent_lis
*/

void	get_subsequent(t_a *stack_a, int lis_max, int lis_max_pos)
{
	int	sub_sequent[lis_max];
	int	i;
	int	j;
	int	k;

	i = lis_max_pos; //11 dans ce cas
	k = lis_max - 1; // vaut 5 (index pour se deplacer dans sub_sequent)
	j = i - 1;
	sub_sequent[k] = stack_a->tab[i];
	while (j >= 0)
	{
		if (stack_a->lis_tab[i] - stack_a->lis_tab[j] == 1)
		{
			k--;
			sub_sequent[k] = stack_a->tab[j];
			i = j;
		}
		j--;
	}
	k = 0;
	while (k < lis_max)
	{
		printf("%d\n", sub_sequent[k]);
		k++;
	}
}

/*
STEP 1: Function to place the minimum on top of stack a
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
FUNCTION TO SET LIS_TAB TO 1s
*/
void	set_lis_tab_to_one(t_a *stack_a)
{
	int	i;

	i = 0;
	while(i < stack_a->size)
		stack_a->lis_tab[i++] = 1;
}

/*
FUNCTION TO DETERMINE LIS_MAX
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
FUNCTION TO FIND LIS LENGTH
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

/*
Function to find copy stack_a in tmp: STEP 2
*/
void	whatever(t_a *stack_a)
{
	int	j;
	int	i;
	int	k;
	int	lis_max;
	int	lis_max_pos;

	i = 0;
	k = 0;
	j = look_for_smallest_num(stack_a); //je cherche le minimum dans la stack_a
	if (j != 0) //si le minimum est ailleurs qu'a la premiere position, alors je le mets on top
		place_it_on_top(stack_a, j);
	printf("TAB A:\n");
	print_tab(stack_a->tab, stack_a->size);
	// printf("\n\n\n");
	// printf("TAB TEMP:\n");
	// print_tab(tmp, stack_a->size);
	test_lis(stack_a); //Je recupere mon tableau avec touttes les lis possibles
	lis_max = find_lis_max(stack_a); //Je determine la longueur de ma LIS
	lis_max_pos = get_lis_max_pos(stack_a, lis_max); //J'ai le position de mon LIS_MAX
	printf("LIS MAX: %d\n", lis_max);
	printf("LIS MAX POSITION: %d\n", lis_max_pos);
	get_subsequent(stack_a, lis_max, lis_max_pos);
	//printf("LIS TAB:\n");
	//print_tab(stack_a->lis_tab, stack_a->size);

}
