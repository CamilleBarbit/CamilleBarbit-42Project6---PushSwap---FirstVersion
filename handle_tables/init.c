/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:35:53 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/20 15:54:13 by cbarbit          ###   ########.fr       */
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
