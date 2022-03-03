/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_of_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:24:12 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/03 08:58:38 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_a *stack_a)
{
	if (stack_a->tab[0] > stack_a->tab[1])
		sa(stack_a);
	if (stack_a->tab[1] > stack_a->tab[2])
		rra(stack_a);
	if (stack_a->tab[0] > stack_a->tab[1])
		sa(stack_a);
}