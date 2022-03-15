/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:03:21 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/15 12:14:09 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	nb_is_negative(int nb1, int nb2)
// {
// 	if (nb1 < 0 && nb2 > 0)
// 		if (-nb1 > nb2)
// 			return (1); // -> il faudra remplacer moves par tempo
// 	if (nb1 > 0 && nb2 < 0)
// 		if (-nb2 < nb1)
// 			return (1);
// 	else
// 		if (-nb1 > -nb2)
// 			return (1);
// 	return (0);
// }

// void	update_pos_a_and_b(t_a *stack_a, t_a *stack_b, int *tempo, int i)
// {
// 	if (stack_a->moves[0] + tempo[0] == 0 || stack_a->moves[0] - tempo[0] == 0)
// 	{
// 		if ((stack_a->moves[1] > 0 && tempo[1] > 0) && (tempo[1] < stack_a->moves[1]))
// 			get_pos_a_and_pos_b(stack_a, stack_b, i);
// 		else if (nb_is_negative(stack_a->moves[1], tempo[1]) == 1)
// 			get_pos_a_and_pos_b(stack_a, stack_b, i);
// 	}
// 	else if (stack_a->moves[1] + tempo[1] == 0 || stack_a->moves[1] - tempo[1] == 0)
// 	{
// 		if ((stack_a->moves[0] > 0 && tempo[0] > 0) && (tempo[0] < stack_a->moves[0]))
// 			get_pos_a_and_pos_b(stack_a, stack_b, i);
// 		else if (nb_is_negative(stack_a->moves[0], tempo[0]) == 1)
// 			get_pos_a_and_pos_b(stack_a, stack_b, i);
// 	}
// }

void    update_pos_a_and_pos_b(t_a *stack_a, t_a *stack_b, int *tempo, int i)
{
    int sum1;
    int sum2;
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
