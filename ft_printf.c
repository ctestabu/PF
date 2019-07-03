/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 22:11:45 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/01 22:11:45 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*init_el(void)
{
	t_printf *elem;
	elem = (t_printf*)malloc(sizeof(t_printf));
	elem->flag_sharp = 0;
	elem->flag_plus = 0;
	elem->flag_minus = 0;
	elem->flag_zero = 0;
	elem->flag_space = 0;
	elem->width = 0;
	elem->precision = -1;
	elem->length = NULL;
	elem->conversion = NULL;
	return (elem);
}

int 	free_elem(t_printf *elem, int nbr)
{
	if (elem->length)
		free(elem->length);
	free(elem);
	return (nbr);
}

int 	init_args(char **str, va_list ap)
{
	t_printf	*elem;
	char 		ch;

	elem = init_el();
	(*str)++;
	while (42)
	{
		if (*str == '\0')
			return (free_elem(elem, 0));
		if (!(check_flags(str, elem)))
			return (free_elem(elem, 0));
		if (!(check_width(str, elem)))
			return (free_elem(elem, 0));
		if (!(check_precision(str, elem)))
			return (free_elem(elem, 0));
		if (!(check_len(str, elem)))
			return (free_elem(elem, 0));
		if (!(check_conversion(str, &ch, elem)))
			return (free_elem(elem, 0));
		if ((ch != '#') && (ch != '0') && (ch != '-') && (ch != '+') && (ch != ' ') && (ch != '.') &&
				(ch != 'l') && (ch != 'h') && (ch != 'j') && (ch != 'z') && (ch != 'L'))
			break;
	}
	return (free_elem(/*smt */));
}

int 	magic(char *str, va_list ap, int size)
{
	char *helper;
	int count;

	if (*str == '\0')
		return (size);
	helper = ft_strchr(str, '%');
	if (!helper)
	{
		ft_putstr(str);
		return (size + ft_strlen(str));
	}
	else if (helper > str)
	{
		ft_putnstr(str, helper - str);
		return (magic(str, ap, size + (helper - str)));
	}
	else
	{
		if ((count = init_args(&str, ap) == -1))
			return (0);
		else
			return (magic(str, ap, size + count));
	}
}




int ft_printf(const char *format, ... )
{
	va_list ap;
	int 	count;

	if (!format)
		return (0);
	va_start(ap, format);
	count = magic((char*)format, ap, 0);
	va_end(ap);
	return (count);
}