/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:05:48 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/04 19:05:48 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	check_plus_spacel(long nbr, t_printf *elem)
{
	char	count;

	count = 0;
	if (elem->flag_plus == 1 && nbr >= 0)
	{
		ft_putchar('+');
		count++;
	}
	else if (elem->flag_space == 1 && nbr >= 0)
	{
		ft_putchar(' ');
		count++;
	}
	return (count);
}

int		check_complet_charl(long nbr, int count, char letter, t_printf *elem)
{
	int	helper;

	if (ft_countnbr(nbr) < (elem->width + count))
	{
		if (letter == ' ' && elem->flag_space == 1 && elem->flag_sharp == 1 &&
				elem->flag_minus != 1)
			elem->width--;
		if (elem->precision >= ft_countnbr(nbr))
		{
			helper = elem->width - count - elem->precision;
			if (nbr < 0)
				helper--;
		}
		else
			helper = elem->width - count - ft_countnbr(nbr);
		while (helper-- > 0)
			ft_putchar(letter);
		return (elem->width);
	}
	else
		count += ft_countnbr(nbr);
	return (count);
}

int		with_width_zero(long nbr, t_printf *elem)
{
	int count;

	count = 0;
	if (elem->precision != -1)
		count = check_complet_charl(nbr, count, ' ', elem);
	count += check_plus_spacel(nbr, elem);
	if (nbr < 0)
		ft_putchar('-');
	if (elem->precision == -1)
		count = check_complet_charl(nbr, count, '0', elem);
	if (nbr < 0)
		nbr = -nbr;
	ft_putnbrwp(nbr, elem->precision);
	return (count);
}

int		with_widthl(long nbr, t_printf *elem)
{
	int count;

	count = 0;
	if (elem->flag_minus == 1)
	{
		count += check_plus_spacel(nbr, elem);
		ft_putnbrwp(nbr, elem->precision);
		count = check_complet_charl(nbr, count, ' ', elem);
	}
	else if (elem->flag_zero == 1)
		count = with_width_zero(nbr, elem);
	else
	{
		if ((elem->flag_plus == 1 || elem->flag_space == 1) && nbr >= 0)
			count++;
		count = check_complet_charl(nbr, count, ' ', elem);
		count += check_plus_spacel(nbr, elem);
		if ((elem->flag_plus == 1 || elem->flag_minus == 1) && nbr >= 0)
			count--;
		ft_putnbrwp(nbr, elem->precision);
	}
	return (count);
}

int		ft_l(long nbr, t_printf *elem)
{
	long	count;

	if (!nbr && !elem->precision)
	{
		count = elem->width > 0 ? elem->width : 0;
		while (elem->width-- > 0)
			ft_putchar(' ');
		return (count);
	}
	if (elem->width)
		count = with_widthl(nbr, elem);
	else
	{
		count = check_plus_spacel(nbr, elem) + ft_countnbr(nbr);
		ft_putnbrwp(nbr, elem->precision);
		if (elem->precision >= ft_countnbr(nbr))
			count++;
	}
	if (nbr && elem->precision > ft_countnbr(nbr))
	{
		count = (nbr < 0) ? elem->precision + 1 : elem->precision;
		count = (elem->width > elem->precision) ? elem->width : count;
	}
	return (count);
}