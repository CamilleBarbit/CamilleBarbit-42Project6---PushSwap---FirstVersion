/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_overflow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:43:40 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/02 10:18:44 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (ft_strcmp(str1, str2) != 0)
		return (write(2, "Error\n", 6), 1);
	return (0);
}
