/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 23:59:12 by kbensado          #+#    #+#             */
/*   Updated: 2016/10/07 05:13:53 by niborrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			check_char_label(char *str, unsigned int i)
{
	int		max;

	max = ft_strlen(str) - 1;
	while (str[i])
	{
		while ((i < 2) && (str[i] == LABEL_CHAR || str[i] == DIRECT_CHAR))
			i++;
		if (i == (unsigned int)max && str[i] == LABEL_CHAR)
			return (1);
		if (!(ft_strchr(LABEL_CHARS, str[i])))
			return (0);
		i++;
	}
	return (1);
}

int			ft_strcmpl(char *str, char *str2, unsigned int i,
					unsigned int j)
{
	while (str[i])
	{
		if (str2[j] == str[i])
		{
			i++;
			j++;
		}
		else
			break ;
	}
	if (str2[j] == 0 && str[i] == LABEL_CHAR)
		return (1);
	return (0);
}

int			test_f(char *line)
{
	if (line[0] == '#' || ft_strstr(line, NAME_CMD_STRING) ||
		ft_strstr(line, COMMENT_CMD_STRING))
		return (0);
	return (1);
}

int			check_char(char *str, unsigned int i, int flag)
{
	if (flag == 0)
	{
		while (str[i])
		{
			while ((i < 2) && (str[i] == '-' || str[i] == DIRECT_CHAR))
				i++;
			if (!(ft_strchr(NUMBERS, str[i])))
				return (0);
			i++;
		}
	}
	if (flag == 1)
	{
		while ((i < 2) && (str[i] == LABEL_CHAR || str[i] == DIRECT_CHAR))
			i++;
		while (str[i])
		{
			if (!(ft_strchr(LABEL_CHARS, str[i])))
				return (0);
			i++;
		}
	}
	return (1);
}

int			line_clean(char *str, unsigned int i, unsigned int j)
{
	while (str[i])
	{
		if (str[i] == '"')
			j++;
		i++;
	}
	if (j % 2 == 0)
		return (1);
	return (0);
}
