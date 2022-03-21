/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:01:31 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/21 17:13:08 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_top(t_a *stack, int nb)
{
	int	tempo1;
	int	tempo2;
	int	i;

	i = 0;
	tempo1 = stack->tab[0];
	while (i <= stack->size - 1)
	{
		tempo2 = tempo1;
		tempo1 = stack->tab[i + 1];
		stack->tab[i + 1] = tempo2;
		i++;
	}
	stack->tab[0] = nb;
	stack->size += 1;
}

void	remove_top(t_a *stack)
{
	int	tempo1;
	int	tempo2;
	int	i;

	i = stack->size - 1;
	tempo1 = stack->tab[i];
	while (i > 0)
	{
		tempo2 = tempo1;
		tempo1 = stack->tab[i - 1];
		stack->tab[i - 1] = tempo2;
		i--;
	}
	stack->size -= 1;
}

void	pa(t_a *stack_a, t_a *stack_b)
{
	if (!stack_b->tab)
		return ;
	add_top(stack_a, stack_b->tab[0]);
	remove_top(stack_b);
	ft_printf("pa\n");
}

void	pb(t_a *stack_a, t_a *stack_b)
{
	if (!stack_a->tab)
		return ;
	add_top(stack_b, stack_a->tab[0]);
	remove_top(stack_a);
	ft_printf("pb\n");
}
