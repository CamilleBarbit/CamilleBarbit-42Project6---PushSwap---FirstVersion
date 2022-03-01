/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:24:45 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/01 11:16:20 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_a *stack_a)
{
	int tempo1;
	int tempo2;
	int i;

	i = stack_a->size_a - 2;
	tempo1 = stack_a->tab_a[i];
	stack_a->tab_a[stack_a->size_a - 1] = stack_a->tab_a[0];
	while (i > 0)
	{
		tempo2 = tempo1;
		tempo1 = stack_a->tab_a[i - 1];
		stack_a->tab_a[i - 1] = tempo2;
		i--;
	}
	stack_a->tab_a[stack_a->size_a -1] = tempo1;
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

void	rb(t_b *stack_b)
{
	int tempo1;
	int tempo2;
	int i;

	i = stack_b->size_b - 2;
	tempo1 = stack_b->tab_b[i];
	stack_b->tab_b[stack_b->size_b - 1] = stack_b->tab_b[0];
	while (i > 0)
	{
		tempo2 = tempo1;
		tempo1 = stack_b->tab_b[i - 1];
		stack_b->tab_b[i - 1] = tempo2;
		i--;
	}
	stack_b->tab_b[stack_b->size_b -1] = tempo1;
}

void	rr(t_b *stack_b, t_a *stack_a)
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