/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:21:02 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/02 11:21:37 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_all_args(char *str)
{
	if (arg_is_valid(str[i]) == 1)
		return (write(2, "Error\n", 6), 1);
	if (check_overflow(str[i]) == 1)
		return (write(2, "Error\n", 6), 1);
	return (0);
}

int main(int argc, char **argv)
{
	t_a	*stack_a;
	t_a	*stack_b;
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
			if (check_all_args(argv[i++]) == 1)
				return (1);
		stack_a = malloc(sizeof(t_a));
		if (!stack_a)
			return (1);
		stack_b = malloc(sizeof(t_a));
		if (!stack_b)
			return(free(stack_a), 1);
		init_stacks(stack_a, stack_b, argc);
		i = 1;
		while (i < argc)
			fill_stack_a(stack_a, argv[i++] argc);
		// free(stack_a);
		// free(stack_b);
	}
	return (0);
}
