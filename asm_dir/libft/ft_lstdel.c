/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 21:32:32 by kbensado          #+#    #+#             */
/*   Updated: 2015/12/28 12:18:38 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**tmp;
	t_list	*tmpnext;

	tmp = alst;
	while (*tmp != NULL)
	{
		tmpnext = (*tmp)->next;
		del((*tmp)->content, (*tmp)->content_size);
		free(*tmp);
		*tmp = tmpnext;
	}
}
