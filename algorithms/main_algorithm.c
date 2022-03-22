/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:03:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/22 10:45:44 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Function to get the LIS and put it in my structure -> stack_a->sub_sequence
*/
void	get_lis(t_a *stack_a, t_a *stack_b)
{
	test_lis(stack_a);
	find_lis_max(stack_a);
	get_sub_sequence(stack_a);
	separate_lis(stack_a, stack_b);
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
		if (stack_a->tab[1] < stack_a->tab[0])
			sa(stack_a);
		i--;
	}
	j = look_for_smallest_num(stack_a);
	if (j > 0)
		place_it_on_top(stack_a, j);
}
