/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_args_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:41:12 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/02 15:05:48 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int compare_each_value(char **str)
{
	int i;
	int j;

	i = 1;
	j = 2;
	while (str[j])
	{
		while (str[i])
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				return (write(2, "Error\n", 6) 1);
			j++;
		}
		i++;
	}
	return (0);
}