/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:21:02 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/01 16:42:26 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_a	*stack_a;
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (arg_is_valid(argv[i]) == 1)
				return (write(2, "Error\n", 6), 1);
		}
	}
	else
		write(2, "Error\n", 6);
	return (0);




	stack_a = malloc(sizeof(t_a));
	if (!stack_a)
		return (1);
	// stack_b = malloc(sizeof(t_a));
	// if (!stack_b)
	//     return (1);
	stack_a->tab = malloc(sizeof(int) * 3);
	stack_a->tab[0] = 4 ;
	stack_a->tab[1] = 5;
	stack_a->tab[2] = 2;
	stack_a->size = 3;
	rra(stack_a);
}
