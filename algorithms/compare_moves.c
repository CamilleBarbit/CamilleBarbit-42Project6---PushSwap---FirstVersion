/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:03:21 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/16 14:36:24 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Function to count the total amount of moves per int -> This function will return the sum of stack_a->moves and the temp
*/
int	sum_moves(int *tab)
{
	int	temp[2];
	int	i;
	int	sum;

	i = 0;
	while (i < 2)
	{
		if (tab[i] < 0)
			temp[i] = -tab[i];
		else
			temp[i] = tab[i];
		i++;
	}
	sum = temp[0] + temp[1];
	return (sum);
}

void	compare_total_moves_count(t_a *stack_a, t_a * stack_b)
{
	int	index_next_nb;
	int	i;
	int	sum1;
	int	sum2;

	get_pos_a_and_pos_b(stack_a, stack_b, 0);
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
		sum1 = sum_moves(stack_a->moves);
		sum2 = sum_moves(tempo);
		if (sum2 < sum1)
			get_pos_a_and_pos_b(stack_a, stack_b, i);
		i++;
}

/*
Function to put in a table of two the nb of moves to put stack_b->tab[i] on top of stack_b and its following number on top of stack_a
*/
void	get_pos_a_and_pos_b(t_a *stack_a, t_a *stack_b, int pos) //on va envoyer la position 0
{
	int	index_next_nb;

	stack_a->moves[1] = count_moves_in_b(stack_b, pos);
	index_next_nb = find_closest_nb(stack_a, stack_b->tab[pos]);
	stack_a->moves[0] = count_moves_in_a(stack_a, index_next_nb);
	if (is_nb_max_in_stack(stack_b, stack_b->tab[pos]) == 1 && is_nb_max_in_stack(stack_a, stack_b->tab[pos]) == 1)
	{
		if (index_next_nb > stack_a->size / 2)
			stack_a->moves[0] -=1;
		else
			stack_a->moves[0] += 1;
	}
	//printf("NEXT NUMBER: %d\n", stack_a->tab[index_next_nb]);
	//printf("POS A: %d\n", stack_a->moves[0]);
	//printf("POS B: %d\n", stack_a->moves[1]);
}

void	count_and_push(t_a *stack_a, t_a *stack_b)
{
	int	i;

	i = 0;

	while (i < stack_b->size - 1)
	{
		compare_total_moves_count(stack_a, stack_b);
	}
}
