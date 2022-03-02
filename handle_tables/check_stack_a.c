/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:16:57 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/02 20:32:57 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//I check if it is in order only if argc > 3
int	check_if_in_order(t_a *stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (j < stack_a->size)
	{
		if (stack_a->tab[i] > stack_a->tab[j])
			return(1);
		i++;
		j++;
		
	}
	return (0);
}