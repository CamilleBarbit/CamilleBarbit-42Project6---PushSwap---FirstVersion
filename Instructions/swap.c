/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:20:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/28 17:10:34 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stacks push_swap)
{
	int tempo;

	if (push_swap->size_a <= 1)
		return ;
	temp = push_swap->stack_a[0];
	push_swap->stack_a[0] = push_swap->stack_a[1];
	push_swap->stack_a[1] = tempo;
}

void	sb(t_stacks push_swap)
{
	int tempo;

	if (push_swap->size_a <= 1)
		return ;
	temp = push_swap->stack_b[0];
	push_swap->stack_b[0] = push_swap->stack_a[1];
	push_swap->stack_b[1] = tempo;
}

void	ss(t_stacks push_swap)
{
	sa(push_swap);
	sb(push_swap);
}
