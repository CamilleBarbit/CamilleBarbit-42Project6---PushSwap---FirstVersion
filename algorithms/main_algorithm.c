/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:03:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/03/07 11:10:50 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tempo;
	int	j;

	i = 0;
	j = i + 1;
	while (j < size)
	{
		j = i + 1;
		if (tab[i] > tab[j])
		{
			tempo = tab[i];
			tab[i] = tab[j];
			tab[j] = tempo;
			i = 0;
		}
		else
			i++;
	}
}

int	main()
{
	int	tab[5] = {5, -6, 18, 23, -15};
	int	size = 5;
	int i = 0;
	ft_sort_int_tab(tab, size);
	while ( i < size)
	{
		printf("%d\n", tab[i++]);
	}
}
