/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:08:44 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/18 14:05:44 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sum_moves(int *tab)
{
	int	temp[3];
	int	i;
	int	sum;

	i = 0;
	while (i < 3)
	{
		if (tab[i] < 0)
			temp[i] = -tab[i];
		else
			temp[i] = tab[i];
		i++;
	}
	sum = temp[0] + temp[1] + temp[2];
	return (sum); //count the number of moves ->after optimisation;
}

void	check_rr_or_rrr(int *tab)
{
	if (tab[0] < 0 && tab[1] < 0)
	{
		while (tab[0] < 0 || tab[1] < 0)
		{
			tab[0]++;
			tab[1]++;
			tab[2]--;
		}
	}
	if (tab[0] > 0 && tab[1] > 0)
	{
		while (tab[0] > 0 || tab[1] > 0)
		{
			tab[0]--;
			tab[1]--;
			tab[2]++;
		}
	}
}

void	get_pos_a_and_pos_b(t_a *stack_a, t_a *stack_b, int *tab, int pos)
{
	int	index_next_nb;

	tab[1] = count_moves_in_b(stack_b, pos);	
	index_next_nb = find_closest_nb(stack_a, stack_b->tab[pos]);
	tab[0] = count_moves_in_a(stack_a, index_next_nb);
	tab[2] = 0;
	check_rr_or_rrr(tab);
}

void	update_better_element(t_a *stack_a)
{
	stack_a->moves[0] = stack_a->tempo[0];
	stack_a->moves[1] = stack_a->tempo[1];
	stack_a->moves[2] = stack_a->tempo[2];
}

void	compare_total_moves_count(t_a *stack_a, t_a * stack_b)
{
	int	i;
	int	sum1;
	int	sum2;

	get_pos_a_and_pos_b(stack_a, stack_b, stack_a->moves, 0); //je mets dans la struct les infos pour stack_b[0]
	i = 1;
	while (i < stack_b->size)
	{
		get_pos_a_and_pos_b(stack_a, stack_b, stack_a->tempo, i);
		sum1 = sum_moves(stack_a->moves);
		sum2 = sum_moves(stack_a->tempo);
		if (sum2 < sum1)
			update_better_element(stack_a);
		i++;
	}
}
