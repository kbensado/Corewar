/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:04:11 by kbensado          #+#    #+#             */
/*   Updated: 2015/12/30 12:04:54 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	*temp2;
	size_t			i;

	i = 0;
	temp = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	while (n--)
	{
		temp[i] = temp2[i];
		if ((unsigned char)c == temp2[i])
			return (temp + i + 1);
		i++;
	}
	return (NULL);
}
