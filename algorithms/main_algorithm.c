/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:03:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/15 12:08:06 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	moves_to_action(t_a *stack_a, t_a *stack_b)
{
	get_pos_a_and_pos_b(stack_a, stack_b, 0);
	
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
