/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:15:32 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/04 18:15:32 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		with_width_percent(t_printf *elem)
{
	int count;

	count = elem->width - 1;
	if (elem->flag_minus == 1)
	{
		ft_putchar('%');
		while (count-- > 0)
			ft_putchar(' ');
	}
	else if (elem->flag_zero == 1)
	{
		while (count-- > 0)
			ft_putchar('0');
		ft_putchar('%');
	}
	else
	{
		while (count-- > 0)
			ft_putchar(' ');
		ft_putchar('%');
	}
	return (elem->width);
}

int		ft_percent(t_printf *elem)
{
	int count;

	count = 0;
	if (elem->width)
		count = with_width_percent(elem);
	else
	{
		ft_putchar('%');
		count++;
	}
	return (count);
}