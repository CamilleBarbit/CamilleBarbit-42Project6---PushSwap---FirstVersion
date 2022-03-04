/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:16:57 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/04 17:02:11 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_if_in_order(t_a *stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (j < stack_a->size)
	{
		if (stack_a->tab[i] > stack_a->tab[j])
			return (0);
		i++;
		j++;

	}
	return (1);
}
