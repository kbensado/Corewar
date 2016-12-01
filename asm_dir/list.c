/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 21:58:07 by kbensado          #+#    #+#             */
/*   Updated: 2016/08/17 21:58:12 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				free_double_char(char **str, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (str && str[i] && i < len)
	{
		if (str[i])
			ft_strdel(&str[i]);
		i++;
	}
	return ;
}

int					get_value(char *str, unsigned int type)
{
	if (type == 3 || type == 4)
		if (ft_strlen(str) > 19)
			return (0);
	if (type == 3 || type == 5)
		return (ft_atoi(str + 1));
	if (type == 4)
		return (ft_atoi(str));
	if (type == 2)
		return (get_data(str, 2, 0));
	return (0);
}

t_tree				*ft_create_elem(t_build build[1], char *str)
{
	t_tree	*tree;

	if (!(tree = (t_tree *)malloc(sizeof(t_tree))))
		return (NULL);
	tree->key = build->key;
	tree->type = build->type;
	tree->nb_oct = build->nb_oct;
	if (tree->type == 2)
		tree->nb_oct = get_data(str, 5, 0);
	tree->nb_arg = build->nb_arg;
	tree->value = get_value(str, tree->type);
	tree->next = NULL;
	if (!(tree->str = ft_strdup(str)))
	{
		free(tree);
		return (NULL);
	}
	return (tree);
}

void				ft_list_p_front(t_tree **begin_list, t_build build[1],
					char *str)
{
	t_tree	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(build, str);
	}
	else
		*begin_list = ft_create_elem(build, str);
}

int					brain_check(t_tree *tree, int flag)
{
	if (flag == 1)
	{
		while (tree && flag == 1)
		{
			if (tree->type == 3 || tree->type == 6)
			{
				if (ft_strlen(tree->str) < 2)
					return (0);
			}
			tree = tree->next;
		}
		return (1);
	}
	else
	{
		while (tree->type == 1)
			tree = tree->next;
		return (tree->key - tree->nb_oct);
	}
	return (1);
}
