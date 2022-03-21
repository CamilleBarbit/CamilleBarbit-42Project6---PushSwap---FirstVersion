/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:28:02 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/21 14:31:17 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_stack(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

/*
Function to check if each element of stack_a is in the LIS or not
*/
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
	return (1);
}

/*
Function to separate the LIS from the rest
-> the LIS stays in stack_a and the rest goes to stack_b
*/
void	separate_lis(t_a *stack_a, t_a *stack_b)
{
	int	i;

	i = 0;
	// printf("STACK A avant de push dans stack B\n");
	// print_stack(stack_a->tab, stack_a->size);
	while (i < stack_a->size)
	{
		if (check_if_in_sub_sequence(stack_a, 0) == 1)
		{
			push_in_b(stack_a, stack_b, 0);
		}
		i++;
		if (check_if_in_sub_sequence(stack_a, i) == 1)
		{
			push_in_b(stack_a, stack_b, i);
			i = 0;
		}
	}
	// printf("PRINT SUBSEQUENCE\n");
	// print_stack(stack_a->sub_sequence, stack_a->lis_max);
	// printf("\n\n\n");
	printf("STACK A\n");
	print_stack(stack_a->tab, stack_a->size);
	printf("\n\n\n");
	printf("STACK B\n");
	print_stack(stack_b->tab, stack_b->size);
	free(stack_a->sub_sequence);
}
