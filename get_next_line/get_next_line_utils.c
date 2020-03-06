/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:40:54 by isfernan          #+#    #+#             */
/*   Updated: 2020/03/06 18:09:03 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cat(char const *s1, char const *s2, char *s3)
{
	int		c[3];

	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	while (s1[c[0]])
	{
		s3[c[2]] = s1[c[0]];
		c[2]++;
		c[0]++;
	}
	while (s2[c[1]])
	{
		s3[c[2]] = s2[c[1]];
		c[2]++;
		c[1]++;
	}
	s3[c[2]] = 0;
	return (s3);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		c1;
	int		c2;

	c1 = 0;
	c2 = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[c1])
		c1++;
	while (s2[c2])
		c2++;
	if (!(s3 = malloc(sizeof(char) * (c1 + c2 + 1))))
		return (0);
	s3 = ft_cat(s1, s2, s3);
	return (s3);
}

int		ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	while (s[i])
	{
		if (s[i] == ch)
			return (i);
		i++;
	}
	if (ch == s[i])
		return (i);
	return (-1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*src_cast;
	char	*dst_cast;
	size_t	i;

	i = 0;
	if (!n || dst == src)
		return (dst);
	src_cast = (char *)src;
	dst_cast = (char *)dst;
	while (i < n)
	{
		dst_cast[i] = src_cast[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	d;
	char	*s2;

	d = ft_strlen(s1) + 1;
	if (!(s2 = malloc(sizeof(char) * d)))
		return (NULL);
	ft_memcpy(s2, s1, d);
	return (s2);
}
