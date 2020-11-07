/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:50:24 by hanisha           #+#    #+#             */
/*   Updated: 2020/11/05 19:28:58 by hanisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int res;
	int sign;
	int i;

	sign = 1;
	res = 0;
	i = 0;
	while (str && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
				str[i] == '\r' || str[i] == ' ' || str[i] == '\f'))
		i++;
	if (str && str[i] == '+')
		i++;
	if (str && str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
