/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:02:57 by kbensado          #+#    #+#             */
/*   Updated: 2015/12/31 13:24:12 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!(*s2))
		return ((char *)s1);
	while (*s1 && n--)
	{
		if (*s1 == s2[0])
		{
			i = 1;
			while (n-- && s1[i] && s2[i] && s1[i] == s2[i])
				++i;
			if (i == ft_strlen(s2))
				return ((char *)s1);
			n += i;
		}
		s1++;
	}
	return (NULL);
}
