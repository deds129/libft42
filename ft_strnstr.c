/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:19:51 by hanisha           #+#    #+#             */
/*   Updated: 2020/11/05 19:13:43 by hanisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return (char *)haystack;
	while (i < len && haystack[i] != '\0')
	{
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (needle[j] == '\0' && i != len)
				return (char *)(haystack + i - j);
		}
		if (haystack[i] == '\0' && needle[j] != '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}
