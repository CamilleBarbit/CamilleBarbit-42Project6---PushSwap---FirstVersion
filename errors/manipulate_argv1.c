/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_argv1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:38:14 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/04 12:44:07 by cbarbit          ###   ########.fr       */
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

	tab_args = ft_split(str,' '); //mon argument est sous la forme d'un double tableau
	len = ft_count_words(str , ' '); //je connais la taille de mon tableau
	i = 0;
	while (i < len)
	{
		
	}
	
}
