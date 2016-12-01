/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 00:02:24 by kbensado          #+#    #+#             */
/*   Updated: 2016/05/23 16:19:17 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 32

typedef struct		s_data
{
	int				fd_saved;
	char			*data;
}					t_data;

int					get_next_line(int const fd, char **line);

#endif
