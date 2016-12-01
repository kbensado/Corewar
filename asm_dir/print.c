/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 07:51:57 by kbensado          #+#    #+#             */
/*   Updated: 2016/09/10 22:23:13 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					ft_addrrev(int val, int flag)
{
	if (flag == 4)
	{
		val = ((val >> 24) & 0xff) |
				((val << 8) & 0xff0000) |
				((val >> 8) & 0xff00) |
				((val << 24) & 0xff000000);
		return (val);
	}
	return (val << 8) | ((val >> 8) & 0xFF);
}

int					ft_addrrev4(unsigned int val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | ((val >> 16) & 0xFFFF);
}

void				ft_putmagic_fd(t_core *core)
{
	unsigned int	i;
	unsigned int	tmp;

	i = COREWAR_EXEC_MAGIC;
	tmp = ft_addrrev(i, 4);
	write(core->fd, &tmp, 4);
	return ;
}

char				*create_path(char *str, unsigned int len)
{
	char			*res;
	char			*res2;

	str[len - 1] = '\0';
	res = ft_strjoin("./", str);
	res2 = ft_strjoin(str, "cor");
	ft_strdel(&res);
	ft_strdel(&str);
	return (res2);
}

int					create_file(t_core *core)
{
	char			*path;
	unsigned int	tmp;

	path = create_path(core->header->exec_name,
		ft_strlen(core->header->exec_name));
	core->path = path;
	if (!(core->fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 455)))
		return (0);
	ft_putmagic_fd(core);
	write(core->fd, &core->header->prog_name, PROG_NAME_LENGTH + 4);
	tmp = ft_addrrev(core->size, 4);
	write(core->fd, &tmp, 4);
	write(core->fd, &core->header->comment, COMMENT_LENGTH + 4);
	return (1);
}
