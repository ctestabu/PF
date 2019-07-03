/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:25:34 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/03 17:25:34 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_norm(char *str, t_printf *elem)
{
	int count;
	int size;

	if (elem->flag_minus == 1)
		ft_putstrwp(str, elem->precision);
	if ((elem->precision != -1) && (size_t)elem->precision < ft_strlen(str))
		size = elem->precision;
	else
		size = ft_strlen(str);
	count = size;
	if (elem->width > size)
		count = elem->width;
	if (elem->flag_zero == 1 && elem->flag_minus != 1)
		while (elem->width-- > size)
			ft_putchar('0');
	else
		while (elem->width-- > size)
			ft_putchar(' ');
	if (elem->flag_minus != 1)
		ft_putstrwp(str, elem->precision);
	return (count);

}


int 	ft_s(char *str, t_printf *elem)
{
	int count;

	count = 0;
	if (!str)
		return ();
	else if ((size_t)elem->width > ft_strlen(str) || (elem->precision < elem->width))
		count = ft_norm(str, elem);
	else
	{
		ft_putstrwp(str, elem->precision);
		if ((elem->precision != -1) && (size_t)elem->precision < ft_strlen(str))
			count += elem->precision;
		else
			count += ft_strlen(str);
	}
	return (count);
}