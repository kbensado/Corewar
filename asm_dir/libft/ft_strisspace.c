/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 22:27:40 by kbensado          #+#    #+#             */
/*   Updated: 2016/08/20 22:27:42 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strisspace(char *str)
{
	unsigned int	i;

	i = 0;
	if (str == 0 || str[i] == 0)
		return (1);
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
