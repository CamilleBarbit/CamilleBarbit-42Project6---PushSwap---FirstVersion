/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:35:53 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/02 18:19:46 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_struct(t_a *stack_a, t_a *stack_b, int argc)
{
	stack_a->size = argc - 1;
	stack_b->size = argc - 1;
	stack_a->tab = malloc(sizeof(int) * stack_a->size);
	if (!stack_a->tab)
		return ;
	stack_a->tab = NULL;
	stack_b->tab = malloc(sizeof(int) * stack_b->size);
	if (!stack_b->tab)
	{
		free(stack_a->tab);
		return ;
	}
	stack_b->tab = NULL;
}

void	fill_stack_a(t_a *stack_a, char **argv)
{
	int		nb;
	int		i;
	
	i = 1;
	while (i < stack_a->size)
	{
		nb = ft_atoi(argv[i]);
		stack_a->tab[i++] = nb;
	}
}