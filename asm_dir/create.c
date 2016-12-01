/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 22:21:42 by kbensado          #+#    #+#             */
/*   Updated: 2016/09/10 22:18:53 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int		octet_cod(t_tree *tree, t_core *core, int nb,
		unsigned int i)
{
	unsigned int	oct;

	oct = 0;
	while (i < (unsigned int)nb)
	{
		if (tree == NULL)
		{
			WS("Error !");
			exit(0);
		}
		if (tree->type == 3 || tree->type == 6)
			oct = oct | DIR_CODE;
		else if (tree->type == 4 || tree->type == 7)
			oct = oct | IND_CODE;
		else if (tree->type == 5)
			oct = oct | REG_CODE;
		oct = oct << 2;
		tree = tree->next;
		i++;
	}
	while (i++ < 3)
		oct = oct << 2;
	write(core->fd, &oct, 1);
	return (oct);
}

void				wrote_file(t_core *core, t_tree *tree, int tmp2, int flag)
{
	if (tree->type == 2)
	{
		write(core->fd, &tree->value, 1);
		if (get_data(tree->str, 5, 0))
			octet_cod(tree->next, core, get_data(tree->str, 3, 0), 0);
		core->tmp = get_data(tree->str, 4, 0);
	}
	else if (tree->type == 5)
		write(core->fd, &tree->value, 1);
	else if (tree->type == 3 || tree->type == 4)
	{
		tmp2 = ft_addrrev(tree->value, flag);
		write(core->fd, &tmp2, flag);
	}
	else if (tree->type == 6)
	{
		tmp2 = ft_addrrev(tree->value, flag);
		write(core->fd, &tmp2, flag);
	}
	else if (tree->type == 7)
	{
		tmp2 = ft_addrrev(tree->value, flag);
		write(core->fd, &tmp2, flag);
	}
}

void				bring_it_on(t_core *core, t_tree *tree)
{
	int				tmp;

	tmp = 0;
	while (tree)
	{
		wrote_file(core, tree, 0, tree->key - tmp);
		tmp = tree->key;
		tree = tree->next;
	}
}

int					set_file(t_core *core, t_tree *tree, int flag)
{
	if (flag == 1)
		return (1);
	if (!(create_file(core)))
		return (0);
	bring_it_on(core, tree);
	return (1);
}
