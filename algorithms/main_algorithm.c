/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:03:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/14 16:34:10 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	update_pos_a_and_b(t_a *stack_a, t_a *stack_b, int *tempo, int i)
{
	if (stack_a->moves[0] + tempo[0] == 0 || stack_a->moves[0] - tempo[0] == 0)
	{
		if (tempo[1] - 0 < stack_a->moves[1] - 0)
		{
			get_pos_a_and_pos_b(stack_a, stack_b, i)
		}
	}

}
void	compare_total_moves_count(t_a *stack_a, t_a *stack_b)
{
	int	tempo[2];
	int	index_next_nb;
	int	i;

	i = 1;
	while (i < stack_b->size)
	{
		tempo[1] = count_moves_in_b(stack_b, i);
		index_next_nb = find_closest_nb(stack_a, stack_b->tab[i]);
		tempo[0] = count_moves_in_a(stack_a, index_next_nb);
		if (is_nb_max_in_stack(stack_b, stack_b->tab[i]) == 1 && is_nb_max_in_stack(stack_a, stack_b->tab[i]) == 1)
		{
			if (index_next_nb > stack_a->size / 2)
				tempo[0] -=1;
			else
				tempo[0] += 1;
		}
		update_pos_a_and_pos_b(stack_a, stack_b, tempo, i);
		i++;
	}

}

/*
Function to put in a table of two the nb of moves to put stack_b->tab[i] on top of stack_b and its following number on top of stack_a
*/
void	get_pos_a_and_pos_b(t_a *stack_a, t_a *stack_b, int pos) //on va envoyer la position 0
{
	int	index_next_nb;
	int	pos_b;
	int	pos_a;

	pos_b = count_moves_in_b(stack_b, pos);
	index_next_nb = find_closest_nb(stack_a, stack_b->tab[pos]);
	pos_a = count_moves_in_a(stack_a, index_next_nb);
	if (is_nb_max_in_stack(stack_b, stack_b->tab[pos]) == 1 && is_nb_max_in_stack(stack_a, stack_b->tab[pos]) == 1)
	{
		if (index_next_nb > stack_a->size / 2)
			pos_a -=1;
		else
			pos_a += 1;
	}
	printf("NEXT NUMBER: %d\n", stack_a->tab[index_next_nb]);
	stack_a->moves[0] = pos_a;
	stack_a->moves[1] = pos_b;
	printf("POS A: %d\n", stack_a->moves[0]);
	printf("POS B: %d\n", stack_a->moves[1]);
}

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
