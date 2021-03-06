/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:38:09 by camillebarb       #+#    #+#             */
/*   Updated: 2021/11/29 13:06:28 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	if (!((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')))
		return (0);
	return (1);
}
