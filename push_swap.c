/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:21:02 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/20 15:24:27 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_a *stack_a, t_a *stack_b)
{
	if (stack_a->tab)
	{
		free(stack_a->tab);
		stack_a->tab = NULL;
	}
	if (stack_b->tab)
	{
		free(stack_b->tab);
		stack_b->tab = NULL;
	}
	free(stack_a);
	stack_a = NULL;
	free(stack_b);
	stack_b = NULL;
}

static int	check_all_args(char **argv, int argc)
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
	init_struct(stack_a, stack_b, argc - 1);
	fill_stack_a(stack_a, argv, 1);
	return (0);
}

static int	malloc(t_a *stack_a, t_a *stack_b)
{
	stack_a = malloc(sizeof(t_a));
	if (!stack_a)
		return (1);
	stack_b = malloc(sizeof(t_a));
	if (!stack_b)
		return (free(stack_a), 1);
}

static void	start_sorting(t_a *stack_am, t_a *stack_b)
{
	get_lis(stack_a, stack_b);
	turn_moves_into_action(stack_a, stack_b);
}

/*TEST*/
// static void	print_tab(int *tab, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d\n", tab[i++]);
// 	}
// }

int	main(int argc, char **argv)
{
	t_a	*stack_a;
	t_a	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (malloc(stack_a, stack_b) == 1)
			return (1);
		if (argc == 2)
		{
			if (argv1_is_valid(argv) == 1)
				return (free_all(stack_a, stack_b), write(2, "ERROR\n", 6), 1);
			if (check_first_arg(argv[1], stack_a, stack_b) == 1)
				return (free_all(stack_a, stack_b), write(2, "ERROR\n", 6), 1);
		}
		if (argc > 2)
		{
			if (check_all_args(argv, argc) == 1)
				return (free_all(stack_a, stack_b), write(2, "ERROR\n", 6), 1);
		}
		start_sorting(stack_a, stack_b);
		free_all(stack_a, stack_b);
	}
	return (0);
}
