/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 03:20:12 by kbensado          #+#    #+#             */
/*   Updated: 2016/09/10 22:30:41 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int		*len_fill2(char *str, char sep[3], unsigned int *tab)
{
	unsigned int	index;
	unsigned int	i;

	index = 0;
	i = 0;
	while (STRING_TEST)
		i++;
	while (str[i])
	{
		if (STRING_TEST)
		{
			tab[index] = i;
			index++;
			while (STRING_TEST)
				i++;
		}
		else
			i++;
	}
	ft_isspace(str[i - 1]) ? (void)i : (tab[index] = i);
	tab[index] = i;
	return (tab);
}

unsigned int		*len_fill(char *str, char sep[3],
							unsigned int *tab, unsigned int l)
{
	unsigned int	index;
	unsigned int	i;

	index = 0;
	i = 0;
	while (STRING_TEST)
		i++;
	while (str[i])
	{
		if (STRING_TEST)
		{
			tab[index] = l;
			l = 0;
			while (STRING_TEST)
				i++;
			str[i] != 0 ? index++ : (void)index;
		}
		else
		{
			i++;
			l++;
		}
	}
	ft_isspace(str[i - 1]) == 1 ? (void)i : (tab[index] = l);
	return (tab);
}

int					test_g(char *str, int test, int i, int j)
{
	int				l;
	int				first;

	l = 0;
	first = first_n(str, 0);
	while (str[i])
	{
		if (str[i] == SEPARATOR_CHAR)
			j++;
		if (str[i] == LABEL_CHAR)
			l++;
		i++;
	}
	if (first == 2 && j == 1 && test == 4)
		return (ft_error("Parse Error !\n", str, NULL));
	if (test > 5)
		return (ft_error("Parse Error !\n", str, NULL));
	if (j > 2)
		return (ft_error("Parse Error !\n", str, NULL));
	if (j == 2 && test < 4)
		return (ft_error("Parse Error !\n", str, NULL));
	if (j == 0 && l == 0 && test > 2)
		return (ft_error("Parse Error !\n", str, NULL));
	return (j + 2);
}

int					ft_nb_word(char *str, unsigned int i,
							char sep[3], unsigned int j)
{
	unsigned int	l;

	l = 0;
	while (STRING_TEST)
		i++;
	while (str[i])
	{
		if (STRING_TEST)
		{
			l = 0;
			while (STRING_TEST)
				i++;
			if (str[i] != 0)
				j++;
		}
		else
		{
			i++;
			l++;
		}
	}
	if (!(test_g(str, j, 0, 0)))
		exit(0);
	return (j);
}

char				**ft_strsplit2(char *str, char c, char b, char **tab)
{
	unsigned int	nb_word;
	unsigned int	*len_word;
	unsigned int	*len_word2;
	char			sep[3];
	int				i;

	i = -1;
	sep[0] = c;
	sep[1] = b;
	sep[2] = '\t';
	if (ft_strisspace(str) || str[0] == '\0')
		return (NULL);
	nb_word = ft_nb_word(str, 0, sep, 1);
	if (!(len_word = ft_memalloc(sizeof(int) * nb_word + 1)))
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * nb_word + 1)))
		return (NULL);
	len_word2 = ft_memalloc(sizeof(int) * nb_word + 1);
	len_word = len_fill(str, sep, len_word, 0);
	len_word2 = len_fill2(str, sep, len_word2);
	while (++i < (int)nb_word)
		tab[i] = ft_strsub(str, len_word2[i] - len_word[i], len_word[i]);
	tab[i] = NULL;
	return (check_double_lift(tab));
}
