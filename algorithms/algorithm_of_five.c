/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_of_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:10:37 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/07 10:37:25 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


// static void	show_tab(t_a *stack)
// {
// 	int i;

// 	i = 0;
// 	while (i < stack->size)
// 		printf("%d\n", stack->tab[i++]);
// }

void	push_min(t_a *stack_a, t_a *stack_b, int min)
{
	if (min > stack_a->size / 2)
	{
		while (min < stack_a->size)
		{
			rra(stack_a);
			min++;
		}
		pb(stack_a, stack_b);
	}
	else
	{
		while (min > 0)
		{
			ra(stack_a);
			min--;
		}
		pb(stack_a, stack_b);
	}

}

int	look_for_smallest_num(t_a *stack_a)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = stack_a->tab[0];
	j = 0;
	while (i < stack_a->size)
	{
		if (tmp > stack_a->tab[i])
		{
			tmp = stack_a->tab[i];
			j = i;
		}
		i++;
	}
	return (j);
}


void	sort_five(t_a *stack_a, t_a *stack_b)
{
	int	j;
	int count;

	count = 2;
	while (count > 0)
	{
		j = look_for_smallest_num(stack_a);
		push_min(stack_a, stack_b, j);
		count--;
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	// printf("TAB A\n");
	// show_tab(stack_a);
}

