/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:03:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/09 11:51:54 by cbarbit          ###   ########.fr       */
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
// int	test_lis(int *tmp, t_a *stack_a)
// {
// 	int	lis_max;
// 	int	i;
// 	int	lis_tab[stack_a->size];
// 	int	j;

// 	j = 0;
// 	lis_max = 1;
// 	set_lis_tab_to_one(stack_a, lis_tab);
// 	i = 1;
// 	while (i < stack_a->size)
// 	{
// 		while (j < i)
// 		{
// 			if (tmp[i] > tmp[j] && lis_tab[i] < lis_tab[j] + 1)
// 			{
// 				lis_tab[i] = lis_tab[j] + 1;
// 			}
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	lis_max = find_lis_max(stack_a, lis_tab);
// 	//printf("TAB LIS:\n");
// 	//print_tab(lis_tab, stack_a->size);
// 	//printf("LEN_LIS: %d\n", lis_max);
// 	// printf("INDICE SUB_SEQUENCE:\n");
// 	// print_tab(sub_sequence, stack_a->size);
// 	return (lis_max);
// }

void	test_lis(int *tmp, t_a *stack_a)
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
			if (tmp[i] > tmp[j] && stack_a->lis_tab[i] < stack_a->lis_tab[j] + 1)
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
	int	tmp[stack_a->size];
	int	i;
	int	k;
	int	lis_max;
	int	lis_max_pos;

	i = 0;
	k = 0;
	j = look_for_smallest_num(stack_a); //je cherche le minimum dans la stack_a
	if (j != 0) //si le minimum est ailleurs qu'a la premiere position, alors je le mets on top
		place_it_on_top(stack_a, j);
	while (k < stack_a->size) //ensuite je copie stack a dans tmp
		tmp[k++] = stack_a->tab[i++];
	// printf("TAB A:\n");
	// print_tab(stack_a->tab, 10);
	// printf("\n\n\n");
	// printf("TAB TEMP:\n");
	// print_tab(tmp, stack_a->size);
	test_lis(tmp, stack_a); //Je recupere mon tableau avec touttes les lis possibles

	//printf("LIS TAB:\n");
	//print_tab(stack_a->lis_tab, stack_a->size);

}
