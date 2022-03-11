/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:03:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/11 14:54:30 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
FONCTION DE TEST POUR AFFICHER LE TABLEAU TRIE
*/
// static void	print_tab(int *tab, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d\n", tab[i++]);
// 	}
// }

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
Function to get the LIS and put it in my structure -> stack_a->sub_sequence
*/
void	get_lis(t_a *stack_a)
{
	int	j;

	j = look_for_smallest_num(stack_a); //je cherche la position du minimum dans la stack_a
	if (j != 0) //si le minimum est ailleurs qu'a la premiere position, alors je le mets on top
		place_it_on_top(stack_a, j);
	test_lis(stack_a); //Je recupere mon tableau avec toutes les listes de int ordonnés possibles
	find_lis_max(stack_a); //Je determine la longueur de ma LIS
	get_sub_sequence(stack_a); //Je recupere les valeurs de la LIS
}
