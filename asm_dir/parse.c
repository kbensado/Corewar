/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 21:55:04 by kbensado          #+#    #+#             */
/*   Updated: 2016/09/10 22:02:27 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				match(char *s1, char *s2)
{
	if (*s1 != '\0' && *s2 == '*')
		return (match(s1 + 1, s2) || match(s1, s2 + 1));
	if (*s1 == *s2 && *s2 == '\0')
		return (1);
	else if (*s1 == '\0' && *s2 == '*')
		return (match(s1, s2 + 1));
	else if (*s1 == *s2 && *s2 != '\0')
		return (match(s1 + 1, s2 + 1));
	else
		return (0);
}

t_tree			*parse_line(t_core *core, char *line, t_tree *tree,
		unsigned int i)
{
	char		**str;

	if (!(test_f(line)))
		return (tree);
	str = ft_strsplit2(line, ' ', SEPARATOR_CHAR, NULL);
	while (str && str[i])
	{
		if (!ft_strisspace(str[i]))
		{
			if (match(str[i], "*:"))
				tree = set_label_post(tree, core, str[i]);
			else if (!(ft_strchr(str[i], LABEL_CHAR)) && IS_ALPHA)
				tree = set_op(tree, core, str[i], line);
			else if (ft_strchr(str[i], SEPARATOR_CHAR) || ft_strchr(str[i],
				DIRECT_CHAR) || match(str[i], "r*") ||
				match(str[i], ":*") || ft_str_is_numeric(str[i]))
				tree = set_arg(tree, core, str[i]);
			else
				exit(ft_error("Parse error !\n", line, NULL));
		}
		i++;
	}
	ft_strdel(&line);
	free_double_char(str, i);
	return (tree);
}

void			fill_tree(t_tree *tree, unsigned int set, unsigned int i)
{
	while (tree)
	{
		if (tree->type == 1)
			tree->key = i;
		else if (tree->type == 2)
		{
			set = get_data(tree->str, 2, 0) - 1;
			tree->key = i + get_data(tree->str, 5, 0) + 1;
		}
		else if (tree->type == 4 || tree->type == 7)
			tree->key = i + 2;
		else if (tree->type == 5)
			tree->key = i + 1;
		else if (tree->type == 6 || tree->type == 3)
			tree->key = i + g_op_tab[set].label_size;
		i = tree->key;
		tree = tree->next;
	}
}

t_tree			*parse_file(t_core *core, unsigned int i)
{
	t_tree		*tree;

	tree = NULL;
	core->buff_i = 0;
	while (core->tab[i])
	{
		if (match(core->tab[i], "*;*"))
			core->tab[i] = sub_way(core->tab[i], 0, 1);
		if (match(core->tab[i], "*#*"))
			core->tab[i] = sub_way(core->tab[i], 0, 0);
		if (!ft_strisspace(core->tab[i]))
			tree = parse_line(core, core->tab[i], tree, 0);
		i++;
	}
	if (!reg_is_clean(tree, tree))
		return (NULL);
	if (!(label_is_clean(tree, tree, tree, NULL)))
		return (NULL);
	if (!(arg_is_clean(tree, NULL, 0)))
		return (NULL);
	if (!(brain_check(tree, 1)))
		return (NULL);
	fill_tree(tree, 0, -1);
	ajust_label(tree, core, 0, tree);
	return (tree);
}
