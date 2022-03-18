/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:21:02 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/18 17:36:05 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_a *stack_a, t_a *stack_b)
{
	free(stack_a->tab);
	free(stack_b->tab);
	free(stack_a);
	free(stack_b);
}

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
	t_a	*stack_a = NULL;
	t_a *stack_b = NULL;

	if (argc > 1) //au moins deux arguments
	{
		stack_a = malloc(sizeof(t_a));
		if (!stack_a)
			return (1);
		stack_b = malloc(sizeof(t_a));
		if (!stack_b)
			return (free(stack_a), 1);
		if (argc == 2)
		{
			if (argv1_is_valid(argv) == 1)
				return (free(stack_a), free(stack_b), printf("ERROR\nInvalid arguments\n"), 1);
			if (check_first_arg(argv[1], stack_a, stack_b) == 1)
				return (free_all(stack_a, stack_b), printf("ERROR\nOverflowOrDouble"), 1);
		}
		if (argc > 2)
		{
			if (check_all_args(argv, argc) == 1)
				return (free(stack_a), free(stack_b), printf("ERROR\nInvalid arguments\n"), 1);
			init_struct(stack_a, stack_b, argc - 1);
			fill_stack_a(stack_a, argv, 1);
		}
		get_lis(stack_a, stack_b);
		turn_moves_into_action(stack_a, stack_b);
		free_all(stack_a, stack_b);	
	}
}
/*
MAIN PROGRAM
*/

// int main(int argc, char **argv)
// {
// 	t_a	*stack_a = NULL;
// 	t_a *stack_b = NULL;

// 	if (argc == 2) //PARSING OK
// 	{
// 		stack_a = malloc(sizeof(t_a));
// 		if (!stack_a)
// 			return (1);
// 		stack_b = malloc(sizeof(t_a));
// 		if (!stack_b)
// 			return (free(stack_a), 1);
// 		if (argv1_is_valid(argv) == 1)
// 			return (free(stack_a), free(stack_b), printf("ERROR\nInvalid arguments\n"), 1);
// 		if (check_first_arg(argv[1], stack_a, stack_b) == 1)
// 			return (free(stack_a), free(stack_b), printf("ERROR\nOverflowOrDouble"), 1);
// 		// if (stack_a->size > 1)
// 		// {
// 		// 	if (check_if_in_order(stack_a) == 0)
// 		// 		sort_three(stack_a);
// 		// 	else
// 		// 		free(TOUT);
// 		get_lis(stack_a, stack_b);
// 		turn_moves_into_action(stack_a, stack_b);
// 	}
// 	if (argc > 2)
// 	{
// 		if (check_all_args(argv, argc) == 1)
// 			return (printf("ERROR\nInvalid arguments\n"), 1);
// 		// stack_a = malloc(sizeof(t_a));
// 		// if (!stack_a)
// 		// 	return (1);
// 		// stack_b = malloc(sizeof(t_a));
// 		// if (!stack_b)
// 		// 	return (free(stack_a), 1);
// 		init_struct(stack_a, stack_b, argc - 1);
// 		fill_stack_a(stack_a, argv, 1);
// 		get_lis(stack_a, stack_b);
// 		turn_moves_into_action(stack_a, stack_b);
// 		//printf("TAB A - END:\n");
// 		//print_tab(stack_a->tab, stack_a->size);
// 		//print_tab(stack_a->tab, stack_a->size);
// 		//if (check_if_in_order(stack_a) == 0)
// 				// sort_three(stack_a);
// 		// else
// 		// 	return (1);
// 		// free(stack);
// 	}
// 	return (0);
// }
