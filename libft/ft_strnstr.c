/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:32:09 by isfernan          #+#    #+#             */
/*   Updated: 2019/12/06 22:21:29 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(const char *h, const char *needle, size_t i, size_t len)
{
	size_t	c;

	c = 0;
	while (i < len && h[i])
	{
		if (!(h[i] == needle[c]))
			return (0);
		i++;
		c++;
		if (!(needle[c]))
			return (1);
	}
	if (!(needle[c]))
		return (1);
	if (needle[c] == h[i] && !(needle[c]))
		return (1);
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!(*(needle)))
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			if (ft_find(haystack, needle, i, len))
			{
				ptr = (char *)haystack + i;
				return (ptr);
			}
		}
		i++;
	}
	return (NULL);
}
