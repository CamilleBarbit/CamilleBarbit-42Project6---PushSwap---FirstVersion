/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:21:02 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/01 17:23:32 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_a	*stack_a;
	t_a	*stack_b;
	int	i;

	i = 1;
	if (argc > 1)
	{
		stack_a = malloc(sizeof(t_a));
		if (!stack_a)
			return(1);
		stack_b = malloc(sizeof(t_a));
		if (!stack_b)
			return(1);
		while (i < argc)
		{
			if (arg_is_valid(argv[i]) == 1)
				return (write(2, "Error\n", 6), 1);
			
			i++;
		}
	}
	return (0);
}
