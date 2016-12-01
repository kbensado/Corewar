/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 02:35:40 by kbensado          #+#    #+#             */
/*   Updated: 2016/10/07 05:15:57 by niborrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int						check_arg(int type, int op)
{
	if (type == 3)
		if (op == 2 || op == 3 || op == 6 || op == 7)
			return (1);
	if (type == 4)
		if (op == 4 || op == 5 || op == 6 || op == 7)
			return (1);
	if (type == 5)
		if (op == 5 || op == 1 || op == 7 || op == 3)
			return (1);
	if (type == 6)
		if (op == 2 || op == 3 || op == 6 || op == 7)
			return (1);
	if (type == 7)
		if (op == 4 || op == 5 || op == 6 || op == 7)
			return (1);
	return (0);
}

int						check_reg(char *str)
{
	int					res;

	res = ft_atoi(str + 1);
	if (res > REG_NUMBER || res < 0)
		return (0);
	return (res);
}

int						label_is_clean(t_tree *tree, t_tree *tmp,
						t_tree *begin, char *str_tmp)
{
	tree->i = 0;
	while (tree)
	{
		if (tree->type == 6 || tree->type == 7)
		{
			while (tmp && tree->i == 0)
			{
				str_tmp = ft_strcute(tmp->str, LABEL_CHAR);
				if (tmp->type == 1 && ft_strstrl(tree->str, str_tmp, 0, 0))
				{
					ft_strdel(&str_tmp);
					tree->i = 1;
				}
				ft_strdel(&str_tmp);
				tmp = tmp->next;
			}
			if (tree->i != 1)
				return (ft_error("No such label : ", tree->str, NULL));
			tree->i = 0;
		}
		tree = tree->next;
		tmp = begin;
	}
	return (1);
}

int						arg_is_clean(t_tree *tree, t_tree *tmp,
									unsigned int nb)
{
	unsigned int		i;

	while (tree)
	{
		if (tree->type == 2)
		{
			tmp = tree->next;
			nb = get_data(tree->str, 3, 0);
			i = -1;
			while (++i < nb)
			{
				if (tmp == NULL)
					return (ft_error("Check tes params on :\n", NULL, tree));
				if (tmp->type < 2)
					return (ft_error("Check tes params on :\n", NULL, tree));
				if (!check_arg(tmp->type, CHECK_A))
					return (ft_error("Check tes params on :\n", NULL, tree));
				tmp = tmp->next;
			}
			if (tmp && tmp->type > 2)
				return (ft_error("Check tes parametres on :\n", NULL, tree));
		}
		tree = tree->next;
	}
	return (1);
}

int						reg_is_clean(t_tree *tree, t_tree *begin)
{
	if (tree == NULL)
		return (0);
	while (tree)
	{
		if (tree->type == 2)
			begin = tree;
		if (tree->type == 5)
		{
			if (!(tree->value = check_reg(tree->str)))
			{
				WS("Error parameter (register 2 DAMNT HIGH)");
				print_error(begin);
				return (0);
			}
		}
		tree = tree->next;
	}
	return (1);
}
