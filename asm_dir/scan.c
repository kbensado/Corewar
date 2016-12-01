/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 03:11:04 by kbensado          #+#    #+#             */
/*   Updated: 2016/09/10 22:21:34 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int			command_name(char *line, t_core *core,
									unsigned int len, unsigned int i)
{
	int					flag;

	flag = 0;
	ft_bzero(core->header->prog_name, PROG_NAME_LENGTH + 7);
	if (!(ft_strchr(line, '"')))
		return (ft_error("No comment...\n", NULL, NULL));
	while (line[i] != '"')
		i++;
	while (line[++i] != '"')
	{
		core->header->prog_name[len] = line[i];
		len++;
		if (len > PROG_NAME_LENGTH)
		{
			WS("Prog name 2 long !");
			return (0);
		}
	}
	return (1);
}

unsigned int			command_comment(char *line, t_core *core,
										unsigned int len, int i)
{
	if (!(ft_strchr(line, '"')))
		return (ft_error("No name...\n", NULL, NULL));
	while (line[i] != '"')
		i++;
	while (line[++i] != '"')
	{
		core->header->comment[len] = line[i];
		len++;
		if (len > COMMENT_LENGTH)
		{
			ft_printf("Comment name 2 long ! avec %d\n", len);
			return (0);
		}
		core->header->comment[len] = 0;
	}
	return (1);
}

unsigned int			scan_line(char *line, t_core *core)
{
	static int			check = 0;

	if (ft_strstr(line, NAME_CMD_STRING) != 0)
	{
		if (!(line_clean(line, 0, 0)))
			return (ft_error(NULL, "Name on one line please !", NULL));
		check++;
		if (!(command_name(line, core, 0, 0)))
			return (0);
		return (1);
	}
	if (ft_strstr(line, COMMENT_CMD_STRING) != 0)
	{
		if (!(line_clean(line, 0, 0)))
			return (ft_error(NULL, "Comment on one line please !", NULL));
		if (!(command_comment(line, core, 0, 0)))
			return (0);
		return (1);
	}
	return (0);
}

unsigned int			nb_line(int fd)
{
	char				c;
	unsigned int		i;
	unsigned int		j;
	unsigned int		l;

	i = 0;
	l = 0;
	j = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			i++;
		if (c == '\0')
			l++;
		j++;
	}
	if (j == l)
		return (0);
	if (j == 0)
		return (0);
	return (i + l);
}

t_core					*get_file(t_core *core, int fd, unsigned int i,
									int flag)
{
	char				*line;

	i = 0;
	if (!(core->tab = (char **)malloc(sizeof(char *) * core->file_size)))
		return (0);
	lseek(fd, 0, SEEK_SET);
	while (get_next_line(fd, &line))
	{
		if (line[0] != COMMENT_CHAR && !(ft_strisspace(line)))
		{
			flag++;
			if (flag == 1 || flag == 2)
			{
				if (!(scan_line(line, core)))
					return (0);
			}
			if (flag > 2 && scan_line(line, core))
				return (0);
		}
		core->tab[i] = ft_strdup(line);
		i++;
	}
	core->tab[i] = NULL;
	return (core);
}
