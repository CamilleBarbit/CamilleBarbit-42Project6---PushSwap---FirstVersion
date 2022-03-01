/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:24:45 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/01 12:06:03 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_a *stack_a)
{
	int tempo1;
	int tempo2;
	int i;

	i = stack_a->size - 2;
	tempo1 = stack_a->tab[i];
	stack_a->tab[stack_a->size - 1] = stack_a->tab[0];
	while (i > 0)
	{
		tempo2 = tempo1;
		tempo1 = stack_a->tab[i - 1];
		stack_a->tab[i - 1] = tempo2;
		i--;
	}
	stack_a->tab[stack_a->size -1] = tempo1;
}

// void	test(int *tab, int size)
// {
// 	int tempo1;
// 	int tempo2;
// 	int i;

// 	i = size - 1;
// 	tempo1 = tab[i];
// 	while (i > 0)
// 	{
// 		tempo2 = tempo1;
// 		tempo1 = tab[i - 1];
// 		tab[i - 1] = tempo2;
// 		i--;
// 	}
// 	tab[size - 1] = tempo1;
// }

void	rb(t_a *stack_b)
{
	int tempo1;
	int tempo2;
	int i;

	i = stack_b->size - 2;
	tempo1 = stack_b->tab[i];
	stack_b->tab[stack_b->size - 1] = stack_b->tab[0];
	while (i > 0)
	{
		tempo2 = tempo1;
		tempo1 = stack_b->tab[i - 1];
		stack_b->tab[i - 1] = tempo2;
		i--;
	}
	stack_b->tab[stack_b->size -1] = tempo1;
}

void	rr(t_a *stack_a, t_a *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

// int	main()
// {
// 	int	tab[6] = {0, 2, 4};
// 	int	size = 3;
// 	test(tab, size);
// }