/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:27:50 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/18 11:19:11 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_move_in_a(t_a *stack_a)
{
	if (stack_a->moves[0] < 0)
	{
		while(stack_a->moves[0] != 0)
		{
			rra(stack_a);
			stack_a->moves[0]++;
		}
	}
	if (stack_a->moves[0] > 0)
	{
		while(stack_a->moves[0] != 0)
		{
			ra(stack_a);
			stack_a->moves[0]--;
		}
	}
}

void	check_move_in_b(t_a *stack_a, t_a *stack_b)
{
	if (stack_a->moves[1] < 0)
	{
		while(stack_a->moves[1] != 0)
		{
			rrb(stack_b);
			stack_a->moves[1]++;
		}
	}
	if (stack_a->moves[1] > 0)
	{
		while(stack_a->moves[1] != 0)
		{
			rb(stack_b);
			stack_a->moves[1]--;
		}
	}
}

void	check_move_in_a_and_b(t_a *stack_a, t_a *stack_b)
{
	if (stack_a->moves[2] < 0)
	{
		while(stack_a->moves[2] != 0)
		{
			rrr(stack_a, stack_b);
			stack_a->moves[2]++;
		}
	}
	if (stack_a->moves[2] > 0)
	{
		while(stack_a->moves[2] != 0)
		{
			rr(stack_a, stack_b);
			stack_a->moves[2]--;
		}
	}
}

