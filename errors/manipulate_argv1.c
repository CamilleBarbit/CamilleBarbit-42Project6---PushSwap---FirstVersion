/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_argv1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:38:14 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/04 14:25:02 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_count_words(char const *string, char a)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] != a && (string[i + 1] == a || string[i + 1] == '\0'))
			count += 1;
		i++;
	}
	return (count);
}

int	check_first_arg(char *str)
{
	char	**tab_args;
	int		len;
	int		i;

	tab_args = ft_split(str,' ');
	len = ft_count_words(str , ' ');
	i = 0;
	while (i < len)
	{
		if (check_overflow(tab_args[i]) == 1)
			return (free(tab_args), 1);
		if (compare_each_value(tab_args, i, len) == 1)
			return (free(tab_args), 1);
		i++;
	}
	return (0);
}
