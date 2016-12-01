/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 20:16:39 by kbensado          #+#    #+#             */
/*   Updated: 2015/12/28 12:24:55 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(const char *s)
{
	int		i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	return (i);
}

static int	ft_end(const char *s)
{
	int		j;

	j = 0;
	while (s[j] != '\0')
		j++;
	j--;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	return (j);
}

char		*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	int		k;
	char	*tab;

	if (!s)
		return (NULL);
	k = 0;
	i = ft_start(s);
	j = ft_end(s);
	if (j - i <= 0)
		j = i - 1;
	tab = (char *)malloc(sizeof(char) * (j - i + 2));
	if (tab == NULL)
		return (NULL);
	while (i <= j)
	{
		tab[k] = s[i];
		i++;
		k++;
	}
	tab[k] = '\0';
	return (tab);
}
