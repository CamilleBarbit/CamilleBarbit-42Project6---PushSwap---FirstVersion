/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:03:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/09 16:33:46 by cbarbit          ###   ########.fr       */
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
STEP 1: Function to place the minimum on top of stack_a->tab
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
	test_lis(stack_a); //Je recupere mon tableau avec toutes les lis possibles
	lis_max = find_lis_max(stack_a); //Je determine la longueur de ma LIS
	lis_max_pos = get_lis_max_pos(stack_a, lis_max); //J'ai le position de mon LIS_MAX
	printf("LIS MAX: %d\n", lis_max);
	printf("LIS MAX POSITION: %d\n", lis_max_pos);
	get_subsequent(stack_a, lis_max, lis_max_pos);
	//printf("LIS TAB:\n");
	//print_tab(stack_a->lis_tab, stack_a->size);

}
