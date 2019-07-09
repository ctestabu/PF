/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invalid_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:18:48 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/05 19:18:48 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		with_width_invalid(char c, t_printf *elem)
{
	int count;

	count = elem->width - 1;
	if (elem->flag_minus == 1)
	{
		ft_putchar(c);
		while (count-- > 0)
			ft_putchar(' ');
	}
	else if (elem->flag_zero == 1)
	{
		while (count-- > 0)
			ft_putchar('0');
		ft_putchar(c);
	}
	else
	{
		while (count-- > 0)
			ft_putchar(' ');
		ft_putchar(c);
	}
	return (elem->width);
}

int		ft_invalid_input(char c, t_printf *elem)
{
	int		count;

	count = 1;
	if (elem->width)
		count = with_width_invalid(c, elem);
	else
		ft_putchar(c);
	return (count);
}