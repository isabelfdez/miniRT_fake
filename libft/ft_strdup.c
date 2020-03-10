/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:29:00 by isfernan          #+#    #+#             */
/*   Updated: 2019/11/26 20:39:25 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
