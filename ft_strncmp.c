/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:21:02 by hanisha           #+#    #+#             */
/*   Updated: 2020/11/05 17:16:20 by hanisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t					i;
	const unsigned char		*s1;
	const unsigned char		*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (s1[i] != '\0' && s2[i] == s1[i] && s2[i] != '\0' && i < n)
		i++;
	return (int)(s1[i] - s2[i]);
}
