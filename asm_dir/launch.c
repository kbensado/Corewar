/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 19:40:21 by kbensado          #+#    #+#             */
/*   Updated: 2016/10/07 05:17:50 by niborrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			dasm(void)
{
	WS("cor detected");
	return (1);
}

int			print_file(t_tree *tree, int flag, t_core *core)
{
	ft_printf("Value for %s :", core->header->prog_name);
	while (tree)
	{
		if (tree->type == 1)
		{
			flag = 1;
			ft_printf("\n%s (%d) ", tree->str, tree->key);
		}
		if (tree->type == 2 && flag == 1)
			ft_printf("%s (%d) ", tree->str, tree->key);
		if (tree->type == 2 && flag == 0)
			ft_printf("\n%s (%d) ", tree->str, tree->key);
		if (tree->type != 2 && tree->type != 1)
			ft_printf("%s (%d | %d)[%d] ", tree->str, tree->key,
										tree->value, tree->type);
		flag = 0;
		tree = tree->next;
	}
	ft_putchar('\n');
	return (1);
}

int			file(char *av, t_core *core, t_tree *tree, int flag)
{
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1 || fd == 0)
		return (ft_error(ERRORB, NULL, NULL));
	core->header->exec_name = ft_strdup(av);
	if (!(core->file_size = nb_line(fd)))
		return (ft_error("Bat file\n", NULL, NULL));
	if (core->file_size < 3)
		return (ft_error("Bat file\n", NULL, NULL));
	if (!(core = get_file(core, fd, 0, 0)))
		return (ft_error("Bat file\n", NULL, NULL));
	close(fd);
	if (!(tree = parse_file(core, 2)))
		return (ft_error("Parse error\n", NULL, NULL));
	if (!(set_file(core, tree, flag)))
		return (ft_error("Error creation file\n", NULL, NULL));
	if (!(retard_error(tree, tree)))
		return (ft_error(NULL, NULL, NULL));
	if (flag == 1)
		return (print_file(tree, 0, core));
	ft_printf("Writing output program to %s\n", core->path);
	ft_strdel(&core->path);
	free_list(core, tree, NULL);
	return (1);
}

int			launch(int ac, char **av, t_core *core, t_tree *tree)
{
	int		i;
	int		flag;
	int		j;

	flag = 0;
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-a") == 0)
		{
			flag = 1;
			i++;
			if (av[i] == NULL)
				return (0);
		}
		if (dat_s(av[i], ft_strlen(av[i])))
		{
			file(av[i], core, tree, flag);
			j++;
		}
		flag = 0;
		i++;
	}
	return (j);
}
