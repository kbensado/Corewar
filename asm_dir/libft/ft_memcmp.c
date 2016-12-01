/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:02:57 by kbensado          #+#    #+#             */
/*   Updated: 2015/12/30 17:14:41 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				result;
	size_t			i;
	unsigned char	*data;
	unsigned char	*data2;

	i = 0;
	result = 0;
	data = (unsigned char *)s1;
	data2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (data[i] == data2[i])
			i++;
		else
			return (data[i] - data2[i]);
	}
	return (result);
}
