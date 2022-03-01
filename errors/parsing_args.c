/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:43:40 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/01 17:30:46 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	arg_is_digit(char a)
{
	if (!(a >= '0' && a <= '9'))
		return (1);
	return (0);
}

int	arg_is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (arg_is_digit(str[i]) == 1)
			return (write(2, "Error\n", 6), 1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_overflow(char *str1)
{
	int		nb;
	char	*str2;

	nb = ft_atoi(str1);
	str2 = ft_itoa(nb);
	

}
