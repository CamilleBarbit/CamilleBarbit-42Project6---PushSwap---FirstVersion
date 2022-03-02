/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_are_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:55:16 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/02 15:26:43 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	arg_is_digit(char a)
{
	if (!(a >= '0' && a <= '9'))
		return (1);
	return (0);
}

int	arg_is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (arg_is_digit(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}