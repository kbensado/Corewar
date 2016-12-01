/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:32:50 by kbensado          #+#    #+#             */
/*   Updated: 2016/10/09 17:32:52 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		first_n(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i])
	{
		if (str[i] == LABEL_CHAR)
		{
			j++;
			return (1);
		}
		if (str[i] == ' ' || str[i] == '\t')
		{
			if (j == 0)
				return (2);
		}
		if (str[i] == SEPARATOR_CHAR)
			return (2);
		i++;
	}
	return (0);
}

char	**check_double_lift(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] != NULL)
		{
			if (match(str[i + 1], "*:"))
			{
				if (match(str[i + 1], "*:"))
					exit(ft_error("Double label...\n", NULL, NULL));
			}
		}
		i++;
	}
	return (str);
}
