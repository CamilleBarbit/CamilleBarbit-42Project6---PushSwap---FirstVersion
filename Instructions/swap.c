/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:20:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/01 12:06:55 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

// void	test(int *tab, int size)
// {
// 	int	tempo;
// 	if (size < 1)
// 		return ;
// 	tempo = tab[0];
// 	tab[0] = tab[1];
// 	tab[1] = tempo;
// }

void	sa(t_a *stack_a)
{
	int tempo;

	if (stack_a->size <= 1)
		return ;
	tempo = stack_a->tab[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->tab[1] = tempo;
}

void	sb(t_a *stack_b)
{
	int tempo;

	if (stack_b->size <= 1)
		return ;
	tempo = stack_b->tab[0];
	stack_b->tab[0] = stack_b->tab[1];
	stack_b->tab[1] = tempo;
}

void	ss(t_a *stack_a, t_a *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}


// int	main()
// {
// 	int	tab[5] = {0, 4, 7, 8, 9};
// 	int	i = 0;
// 	int size = 5;

// 	test(tab, size);
// 	while (i < size)
// 	{
// 		printf("%d\n", tab[i]);
// 		i++;
// 	}
// }