/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 02:14:49 by kbensado          #+#    #+#             */
/*   Updated: 2016/10/07 05:13:34 by niborrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		retard_error(t_tree *tree, t_tree *begin)
{
	while (tree)
	{
		if (tree->type == 2)
			begin = tree;
		if (tree->type == 6 || tree->type == 7)
		{
			if (!(check_char(tree->str, 0, 1)))
				return (ft_error("Error\n", NULL, begin));
		}
		if (tree->type == 3)
			if (!(check_char(tree->str, 0, 0)))
				return (ft_error("Error\n", NULL, begin));
		if (tree->type == 1 || tree->type == 6 || tree->type == 7)
			if (!(check_char_label(tree->str, 0)))
				return (ft_error("Error\n", tree->str, NULL));
		tree = tree->next;
	}
	return (1);
}

void	print_error(t_tree *tree)
{
	while (tree)
	{
		ft_printf("%s ", tree->str);
		tree = tree->next;
		if (tree)
		{
			if (tree->type == 1 || tree->type == 2)
			{
				WS("");
				return ;
			}
		}
	}
	WS("");
}

int		ft_strstrl(char *str, char *str2, int i, int j)
{
	while (str[i])
	{
		while ((i < 2) && (str[i] == LABEL_CHAR || str[i] == DIRECT_CHAR))
			i++;
		if (str2[j] == str[i])
		{
			i++;
			j++;
		}
		else
			break ;
	}
	if (str2[j] == 0 && str[i] == 0)
		return (1);
	return (0);
}

void	free_list(t_core *core, t_tree *tree, t_tree *tmp)
{
	if (core)
	{
		ft_bzero(core->header->prog_name, PROG_NAME_LENGTH + 1);
		ft_bzero(core->header->comment, PROG_NAME_LENGTH + 1);
	}
	if (tree)
	{
		while (tree)
		{
			tmp = tree->next;
			ft_strdel(&tree->str);
			free(tree);
			tree = NULL;
			tree = tmp;
		}
	}
}

int		true_key(int key, int oct)
{
	if (oct > 0)
		return (key - oct);
	return (key);
}
