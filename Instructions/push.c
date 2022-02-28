/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:01:31 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/28 17:34:14 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    pa(t_stacks push_swap)
{
    int tempo;
    
    if (!t_stacks->stack_b)
        return ;
    tempo = t_stacks->stack_b[0];
    int i = 0;
    int temp = t_stacks->stack_a[0];
    int temp2;
    while (i < t_stacks->size_a)
    {
        temp2 = temp;
        temp = t_stacks->stack_a[i + 1];
        t_stacks->stack_a[++i] = temp2;
    }
    t_stacks->size_a[0] = tempo;
    t_stacks->size_a++;

    i = t_stacks->size_b - 1;
    temp = t_stacks->stack_b[i];
    while (i > 0)
    {
        temp2 = temp;
        temp = t_stacks->stack_b[i - 1];
        t_stacks->stack_b[--i] = temp2;
    }
    t_stacks->size_b--;
}