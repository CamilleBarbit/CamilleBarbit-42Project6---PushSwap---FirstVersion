/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:28:02 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/10 13:18:39 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i++]);
	}
}

int	check_if_in_sub_sequence(t_a *stack_a, int i)
{
	int	j;
	
	j = 0;
	while (j < stack_a->lis_max)
	{
		if (stack_a->tab[i] == stack_a->sub_sequence[j])
			return (0);
		j++;
	}
	printf("LIS: \n");
	print_tab(stack_a->sub_sequence, stack_a->lis_max);
	return (1);
}

void	do_it(t_a *stack_a, t_a *stack_b)
{
	int	i;

	i = 0;
	while(i < stack_a->size)
	{
		if (check_if_in_sub_sequence(stack_a, i) == 1)
		{
			//stack_a->size--;
			//printf("SIZE A : %d\n", stack_a->size);
			push_in_b(stack_a, stack_b, i);
		}
		i++;
	}
	printf("TABLE A\n");
	print_tab(stack_a->tab, stack_a->size);
	printf("TABLE B\n");
	print_tab(stack_b->tab, stack_a->size);
}
