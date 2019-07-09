/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:11:12 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/04 20:11:12 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_unicode(wchar_t c)
{
	if ((c >> 16) != 0)
		return (4);
	else if ((c >> 11) != 0)
		return (3);
	else if ((c >> 7) != 0)
		return (2);
	else
		return (1);
}

int		ft_count_multiple_unicode(wchar_t *str)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (str[++i])
		count += ft_count_unicode(str[i]);
	return (count);
}

void	ft_unicode(unsigned int c)
{
	if ((c >> 16) != 0)
		four_bytes(c);
	else if ((c >> 11) != 0)
		three_bytes(c);
	else if ((c >> 7) != 0)
		two_bytes(c);
	else
		ft_putchar(c);
}

int		ft_cwl(wint_t c, t_printf *elem)
{
	int count;

	if (elem->width)
	{
		if (ft_count_unicode(c) > 1)
			count = elem->width - ft_count_unicode(c);
		else
			count = elem->width - 1;
		if (elem->flag_minus == 1)
			ft_unicode(c);
		while (count-- > 0)
			ft_putchar(' ');
		if (elem->flag_minus != 1)
			ft_unicode(c);
	}
	else
		ft_unicode(c);
	count = ft_count_unicode(c);
	if (elem->width > count)
		return (elem->width);
	return (count);
}

int		ft_c(int c, t_printf *elem)
{
	int				count;
	unsigned char	cha;

	count = 0;
	cha = c & 255;
	if (elem->width)
	{
		count = elem->width;
		if (elem->flag_minus == 1)
			ft_putchar(cha);
		if (elem->flag_zero == 1)
			while (--count)
				ft_putchar('0');
		else
			while (--count)
				ft_putchar(' ');
		if (elem->flag_minus != 1)
			ft_putchar(cha);
		return (elem->width);
	}
	ft_putchar(cha);
	return (1);
}