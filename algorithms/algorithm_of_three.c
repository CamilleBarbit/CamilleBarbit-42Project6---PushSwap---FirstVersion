/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_of_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:24:12 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/07 10:32:30 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
FONCTION DE TEST POUR AFFICHER LE TABLEAU TRIE
*/

// static void	print_tab(t_a *stack_a)
// {
// 	int	i;

// 	i = 0;
// 	while (i < stack_a->size)
// 	{
// 		printf("TABLEAU EN ORDRE: %d\n", stack_a->tab[i++]);
// 	}
// }

/*
FUNCTION TO PUT IN ORDER A TABLE OF THREE INTEGERS
*/

void	sort_three(t_a *stack_a)
{
	if (stack_a->tab[0] > stack_a->tab[1])
		sa(stack_a);
	if (stack_a->tab[1] > stack_a->tab[2])
		rra(stack_a);
	if (stack_a->tab[0] > stack_a->tab[1])
		sa(stack_a);
	//print_tab(stack_a);
}
