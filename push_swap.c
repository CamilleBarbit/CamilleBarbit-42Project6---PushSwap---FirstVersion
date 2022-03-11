/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:21:02 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/11 14:08:13 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_all_args(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (arg_is_valid(argv[i]) == 1)
			return (1);
		if (check_overflow(argv[i]) == 1)
			return (1);
		if (compare_each_value(argv, i, argc) == 1)
			return (1);
		i++;
	}
	return (0);
}

/*
FONCTION DE TEST POUR AFFICHER LE TABLEAU AVANT TRI
*/

static void	show_tab(t_a *stack_a)
{
	int i;

	i = 0;
	while (i < stack_a-> size)
		printf("%d\n", stack_a->tab[i++]);
}

/*
MAIN PROGRAM
*/

int main(int argc, char **argv)
{
	t_a	*stack_a = NULL;
	t_a *stack_b = NULL;

	if (argc == 2) //PARSING OK
	{
		stack_a = malloc(sizeof(t_a));
		if (!stack_a)
			return (1);
		stack_b = malloc(sizeof(t_a));
		if (!stack_b)
			return (free(stack_a), 1);
		if (argv1_is_valid(argv) == 1)
			return (free(stack_a), free(stack_b), printf("ERROR\nInvalid arguments\n"), 1);
		if (check_first_arg(argv[1], stack_a, stack_b) == 1)
			return (free(stack_a), free(stack_b), printf("ERROR\nOverflowOrDouble"), 1);
		show_tab(stack_a);
		if (stack_a->size > 1)
		{
			if (check_if_in_order(stack_a) == 0)
				sort_three(stack_a);
			// else
			// 	free(TOUT);
		}

	}
	if (argc > 2) //PARSING OK
	{
		if (check_all_args(argv, argc) == 1)
			return (printf("ERROR\nInvalid arguments\n"), 1);
		stack_a = malloc(sizeof(t_a));
		if (!stack_a)
			return (1);
		stack_b = malloc(sizeof(t_a));
		if (!stack_b)
			return (free(stack_a), 1);
		init_struct(stack_a, stack_b, argc - 1);
		fill_stack_a(stack_a, argv, 1);
		get_lis(stack_a);
		separate_lis(stack_a, stack_b);
		//sort_five(stack_a, stack_b);
		//if (check_if_in_order(stack_a) == 0)
				// sort_three(stack_a);
		// else
		// 	return (1);
		// free(stack);
	}
	return (0);
}
