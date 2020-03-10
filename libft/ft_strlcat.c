/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:31:13 by isfernan          #+#    #+#             */
/*   Updated: 2019/11/23 17:34:01 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t len, size_t dst)
{
	if (len < dst)
		return (len);
	else
		return (dst);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	size_t	j;

	i = 0;
	n = ft_min(ft_strlen(dst), dstsize);
	j = ft_strlen(src);
	if (dstsize == n)
		return (j + n);
	while (src[i] && i < dstsize - n - 1)
	{
		dst[i + n] = src[i];
		i++;
	}
	dst[i + n] = 0;
	return (j + n);
}
