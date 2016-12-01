/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 02:24:15 by kbensado          #+#    #+#             */
/*   Updated: 2016/02/28 06:33:23 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_power(int nb, int power)
{
	int	tmp;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power % 1 == 1)
		return (ft_recursive_power(nb, power - 1) * nb);
	else
	{
		tmp = ft_recursive_power(nb, power / 2);
		return (tmp * tmp);
	}
}
