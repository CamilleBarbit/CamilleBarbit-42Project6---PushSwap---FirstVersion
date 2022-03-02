/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:35:53 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/02 11:40:49 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stacks(t_a *stack, int argc)
{
	stack->size_a = argc - 1;
	stack->size_b = argc - 1;
	stack->tab_a = malloc(sizeof(int) * size);
	if (!stack->tab_a)
		return ;
	stack->tab_a = NULL;
	stack->tab_b = malloc(sizeof(int) * size);
	if (!stack->tab_b)
	{
		free(stack->tab_a);
		return ;
	}
	stack->tab_b = NULL;
}

void	fill_tab_a(t_a *stack, char *str)
{
	int			nb;
	static int	i = 0;

	nb = ft_atoi(str);
	while (i < stack->size_a)
		stack->tab_a[i++] = nb;
}