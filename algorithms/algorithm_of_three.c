/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_of_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:24:12 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/20 16:30:32 by cbarbit          ###   ########.fr       */
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
