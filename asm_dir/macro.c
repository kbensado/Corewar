/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 07:42:59 by kbensado          #+#    #+#             */
/*   Updated: 2016/08/12 07:43:01 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					is_label(char *c)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(LABEL_CHARS))
	{
		if (c[i] == LABEL_CHARS[i] || c[i] == COMMENT_CHAR ||
			c[i] == LABEL_CHAR || c[i] == DIRECT_CHAR ||
			c[i] == SEPARATOR_CHAR || ft_isspace(c[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int					ft_error(char *str, char *data, t_tree *tree)
{
	if (str)
		ft_putstr(str);
	if (data != NULL)
		ft_printf("%s\n", data);
	if (tree)
		print_error(tree);
	return (0);
}

int					find_value(t_tree *tree, char *str, int res2,
								unsigned int len)
{
	char			*tmp;

	tmp = NULL;
	if (str[0] == DIRECT_CHAR)
		tmp = ft_strsub(str, 2, len);
	else
		tmp = ft_strsub(str, 1, len);
	while (tree)
	{
		if (tree->type == 1)
		{
			if (ft_strcmpl(tree->str, tmp, 0, 0))
			{
				if (tree->next == NULL)
					res2 = tree->key + 1;
				else
					res2 = brain_check(tree, 0);
				ft_strdel(&tmp);
				return (res2);
			}
		}
		tree = tree->next;
	}
	ft_strdel(&tmp);
	return (0);
}

int					warp_it(t_tree *tree, int key, int foo, int bar)
{
	while (tree->key != (unsigned int)key)
		tree = tree->next;
	return (tree->key - (foo + bar));
}

void				ajust_label(t_tree *tree,
					t_core *core, unsigned int tmp, t_tree *begin_tree)
{
	while (tree)
	{
		if (tree->type == 1)
		{
			if (tree->next == NULL)
				tree->key = tree->key;
			else
				tree->key = brain_check(tree, 0);
		}
		tree = tree->next;
	}
	tree = begin_tree;
	while (tree)
	{
		if (tree->type == 2)
			tmp = true_key(tree->key, tree->nb_oct);
		if (tree->type == 6)
			tree->value = find_value(begin_tree, tree->str, 0, LEN) - tmp;
		if (tree->type == 7)
			tree->value = find_value(begin_tree, tree->str, 0, LEN) - tmp;
		core->size = tree->key;
		tree = tree->next;
	}
	core->size++;
}
