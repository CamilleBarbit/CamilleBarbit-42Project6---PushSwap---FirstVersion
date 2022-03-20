/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_args_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:41:12 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/20 16:29:45 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	compare_each_value(char **argv, int i, int argc)
{
	int	j;

	j = i + 1;
	while (argv[i])
	{
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j++]) == 0)
				return (1);
		}
		i++;
		j = i + 1;
	}
	return (0);
}
