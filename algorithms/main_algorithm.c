/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:03:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/18 12:25:27 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*TEST*/
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
Function to get the LIS and put it in my structure -> stack_a->sub_sequence
*/
void	get_lis(t_a *stack_a, t_a *stack_b)
{
	int	j;

	j = look_for_smallest_num(stack_a); //je cherche la position du minimum dans la stack_a
	if (j != 0) //si le minimum est ailleurs qu'a la premiere position, alors je le mets on top
		place_it_on_top(stack_a, j);
	test_lis(stack_a); //Je recupere mon tableau avec toutes les listes de int ordonnés possibles
	find_lis_max(stack_a); //Je determine la longueur de ma LIS
	get_sub_sequence(stack_a); //Je recupere les valeurs de la LIS
	separate_lis(stack_a, stack_b); //Je push la LIS dans stack_b
	printf("TAB A - step 1:\n");
	print_tab(stack_a->tab, stack_a->size);
	printf("TAB B - step 1:\n");
	print_tab(stack_b->tab, stack_b->size);
}


void	turn_moves_into_action(t_a *stack_a, t_a *stack_b)
{
	int	i;
	int	j;

	i = stack_b->size;
	while (i > 0)
	{
		compare_total_moves_count(stack_a, stack_b);
		check_move_in_a(stack_a);
		check_move_in_b(stack_a, stack_b);
		check_move_in_a_and_b(stack_a, stack_b);
		pa(stack_a, stack_b);
		if (is_nb_max_in_stack(stack_b, stack_a->tab[0]) == 1 
			&& is_nb_max_in_stack(stack_a, stack_a->tab[0]) == 1)
			sa(stack_a);
		i--;
	}
	j = look_for_smallest_num(stack_a);
	if (j != 0)
		place_it_on_top(stack_a, j);
	printf("TAB A - step 2:\n");
	print_tab(stack_a->tab, stack_a->size);
	printf("TAB B - step 2:\n");
	print_tab(stack_b->tab, stack_b->size);
}
