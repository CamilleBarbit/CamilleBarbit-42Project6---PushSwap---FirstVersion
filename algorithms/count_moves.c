/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:44:45 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/11 14:14:35 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_moves_in_b(t_a *stack_b, int pos)
{
	int	count;

	count = 0;
	if (pos > stack_b->size / 2)
	{
		while (pos < stack_b->size)
		{
			count++;
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			count++;
			pos--;
		}
	}
	return (count);
}
