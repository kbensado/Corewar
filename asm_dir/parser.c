/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 21:33:05 by kbensado          #+#    #+#             */
/*   Updated: 2016/08/17 21:33:09 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char				*sub_way(char *str, unsigned int i, unsigned int flag)
{
	char			*tmp;

	if (flag == 1)
	{
		while (str[i] != ';')
			i++;
		tmp = ft_strsub(str, 0, i);
		str = NULL;
		return (tmp);
	}
	else
	{
		while (str[i] != COMMENT_CHAR)
			i++;
		tmp = ft_strsub(str, 0, i);
		str = NULL;
		return (tmp);
	}
}

int					get_data(char *str, unsigned int index, unsigned int i)
{
	while (i < 17)
	{
		if (g_op_tab[i].op && match(g_op_tab[i].op, str))
		{
			if (index == 2)
				return (g_op_tab[i].op_id);
			if (index == 3)
				return (g_op_tab[i].nb_arg);
			if (index == 4)
				return (g_op_tab[i].label_size);
			if (index == 5)
				return (g_op_tab[i].octet);
		}
		i++;
	}
	return (-1);
}

t_tree				*set_arg(t_tree *tree, t_core *core, char *str)
{
	char			**tab;
	unsigned int	i;

	i = 0;
	if (!(tab = ft_strsplit(str, SEPARATOR_CHAR)))
		return (NULL);
	while (tab[i])
	{
		if (match(tab[i], "r*"))
			ft_list_p_front(&tree, &(t_build){core->buff_i, 5, 0, 0}, tab[i]);
		else if (ft_strchr(tab[i], DIRECT_CHAR)
				&& !ft_strchr(tab[i], LABEL_CHAR))
			ft_list_p_front(&tree, &(t_build){core->buff_i, 3, 0, 0}, tab[i]);
		else if (ft_strchr(tab[i], DIRECT_CHAR)
				&& ft_strchr(tab[i], LABEL_CHAR))
			ft_list_p_front(&tree, &(t_build){core->buff_i, 6, 0, 0}, tab[i]);
		else if (ft_strchr(tab[i], ':'))
			ft_list_p_front(&tree, &(t_build){core->buff_i, 7, 0, 0}, tab[i]);
		else if (!ft_strchr(tab[i], ':') && !ft_strchr(tab[i], DIRECT_CHAR))
			ft_list_p_front(&tree, &(t_build){core->buff_i, 4, 0, 0}, tab[i]);
		i++;
	}
	return (tree);
}

t_tree				*set_op(t_tree *tree, t_core *core, char *str, char *line)
{
	int				arg;

	arg = get_data(str, 3, 0);
	if (arg == -1)
	{
		WS(line);
		exit(42);
		return (NULL);
	}
	ft_list_p_front(&tree, &(t_build){core->buff_i, 2, 0, arg}, str);
	return (tree);
}

t_tree				*set_label_post(t_tree *tree, t_core *core, char *str)
{
	ft_list_p_front(&tree, &(t_build){core->buff_i, 1, 0, 0}, str);
	return (tree);
}
