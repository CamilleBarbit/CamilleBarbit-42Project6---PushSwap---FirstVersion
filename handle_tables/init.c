/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:35:53 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/10 14:37:58 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_struct(t_a *stack_a, t_a *stack_b, int size)
{
	stack_a->size = size;
	stack_b->size = 0;
	stack_a->tab = malloc(sizeof(int) * stack_a->size);
	if (!stack_a->tab)
		return ;
	stack_b->tab = malloc(sizeof(int) * stack_a->size);
	if (!stack_b->tab)
	{
		free(stack_a->tab);
		return ;
	}
}

void	fill_stack_a(t_a *stack_a, char **str, int i)
{
	int		nb;
	int		j;

	j = 0;
	while (j < stack_a->size)
	{
		nb = ft_atoi(str[i++]);
		stack_a->tab[j++] = nb;
	}
}
