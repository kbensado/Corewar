/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 12:50:27 by kbensado          #+#    #+#             */
/*   Updated: 2016/10/07 05:49:35 by niborrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;
	char	*t;

	i = 0;
	if ((mem = (void *)malloc(size * sizeof(void))) == NULL)
		return (NULL);
	t = (char *)mem;
	if (mem != NULL)
	{
		while (i < size)
		{
			*t++ = 0;
			i++;
		}
	}
	return (mem);
}
