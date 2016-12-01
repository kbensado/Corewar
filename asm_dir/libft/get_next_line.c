/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:18:25 by kbensado          #+#    #+#             */
/*   Updated: 2016/05/23 16:18:38 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_data		*get_data(int const fd, t_list **lst_ptr)
{
	t_list			*lst;
	t_data			data;

	lst = *lst_ptr;
	while (lst)
	{
		if (((t_data*)(lst->content))->fd_saved == fd)
			return (lst->content);
		lst = lst->next;
	}
	data.fd_saved = fd;
	data.data = ft_strnew(BUFF_SIZE);
	if (!(lst = ft_lstnew(&data, sizeof(t_data))) || !data.data)
	{
		free(data.data);
		return (NULL);
	}
	ft_lstadd(lst_ptr, lst);
	return ((*lst_ptr)->content);
}

static int			read_data(t_data *data, char **line)
{
	int				ret;
	char			*str;

	ret = 0;
	if ((str = ft_strchr(data->data, '\n')))
	{
		*str = '\0';
		str++;
		ret = 1;
	}
	*line = ft_strdup(data->data);
	if (!(*line))
		return (-1);
	if (ret)
		ft_strcpy(data->data, str);
	else
		ft_strclr(data->data);
	return (ret);
}

static int			read_buf(char *buf, char **line, t_data *data)
{
	int				ret;
	char			*tmp;

	ret = 0;
	if ((tmp = ft_strchr(buf, '\n')))
	{
		*tmp = '\0';
		tmp++;
		ft_strcpy(data->data, tmp);
		ret = 1;
	}
	tmp = *line;
	*line = ft_strjoin(*line, buf);
	if (!(*line))
		return (-1);
	free(tmp);
	return (ret);
}

static int			free_str_return(char *str, int ret)
{
	free(str);
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	int				ret;
	char			*buf;
	t_data			*data;
	static t_list	*lst;

	if (!line || (BUFF_SIZE <= 0) || !(data = get_data(fd, &lst)))
		return (-1);
	if (!(ret = read_data(data, line)))
	{
		if (!(buf = ft_strnew(BUFF_SIZE)))
			return (-1);
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			if (ret < 0)
				return (free_str_return(buf, -1));
			buf[ret] = '\0';
			if ((ret = read_buf(buf, line, data)))
				return (free_str_return(buf, ret));
		}
		if (**line)
			return (free_str_return(buf, 1));
		return (free_str_return(buf, 0));
	}
	return (ret);
}
