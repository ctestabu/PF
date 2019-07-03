/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:55:45 by ctestabu          #+#    #+#             */
/*   Updated: 2019/06/30 15:55:45 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 	*check_flags(char **str, t_printf *elem)
{
	if (**str == '#' || **str == '0' || **str == '-' || **str == '+' || **str == ' ')
	{
		if (**str == '#')
			elem->flag_sharp = 1;
		else if (**str == '0')
			elem->flag_zero = 1;
		else if (**str == '-')
			elem->flag_minus = 1;
		else if (**str == '+')
			elem->flag_plus = 1;
		else if (**str == ' ')
			elem->flag_space = 1;
		(*str)++;
		return check_flags(str, elem);
	}
	else
		return (*str);
}

char	*check_width(char **str, t_printf *elem)
{
	char	*helper;
	char	*helper2;
	int		i;

	i = -1;

	if ((**str < 47) || (**str > 57))
		return (*str);
	helper = *str;
	while ((*helper >= 48) && (*helper <= 57))
		helper++;
	helper2 = (char *)malloc(sizeof(char) * (helper - *str) + 1);
	while ((*helper2 >= 48) && (*helper2 <= 57))
	{
		helper2[++i] = **str;
		(*str)++;
//		i++;
	}
	helper2[i] = '\0';
	elem->width = ft_atoi(helper2);
	free(helper2);
//	free(helper);
	return (*str);
}

char 	*check_precision(char **str, t_printf *elem)
{
	char	*helper;
	char	*helper2;
	int		i;

	i = -1;

	if (**str != '.')
		return (*str);
	(*str)++;
	elem->precision = 0;
	if ((**str < 47) || (**str > 57))
		return (*str);
	helper = *str;
	while ((*helper >= 48) && (*helper <= 57))
		helper++;
	helper2 = (char *)malloc(sizeof(char) * (helper - *str) + 1);
	while ((*helper2 >= 48) && (*helper2 <= 57))
	{
		helper2[++i] = **str;
		(*str)++;
//		i++;
	}
	helper2[i] = '\0';
	elem->precision = ft_atoi(helper2);
	free(helper2);
//	free(helper);
	return (*str);
}

char 	*check_len(char **str, t_printf *elem)
{
	char s;

	s = **str;
	if ((elem->length) && (elem->length[0] > s))
		(*str)++;
	if ((elem->length) && (elem->length[0] > s))
		s = 0;
	else if ((elem->length) && (elem->length[0] < s) && (s == 'l' || s =='h'||
	s == 'j' || s == 'z' || s == 'L'))
		free(elem->length);
	if (s && (s == 'l' || s =='h'|| s == 'j' || s == 'z' || s == 'L'))
	{
		if ((s == 'l' && *(*str + 1) == 'l') || (s == 'h' && *(*str + 1) == 'h'))
			elem->length = ft_strnew(2);
		else
			elem->length = ft_strnew(1);
		elem->length[0] = s;
		if ((s == 'l' && *(*str + 1) == 'l') || (s == 'h' && *(*str + 1) == 'h'))
			elem->length[1] = (s == 'l') ? 'l' : 'h';
		if (elem->length[1] != '\0')
			(*str)++;
		(*str)++;
	}
	return (*str);
}

int 	check_conversion(char **str, char *ch, t_printf *elem)
{
	char s;

	s = **str;
	if (s == 'd' || s == 'i' || s == 'o' || s == 'u' || s == 'x' || s == 'X' || s == 'f' ||
			s == 'F' || s == 's' || s == 'S' || s == 'p' || s == '%' || s == 'c' || s == 'C' ||
			s == 'O' || s == 'D' || s == 'U' || s)
	{
		elem->conversion = **str;
		*ch = **str;
		if ((s != '#') && (s != '0') && (s != '-') && (s != '+') && (s != ' ') && (s != '.') &&
				(s != 'l') && (s != 'h') && (s != 'j') && (s != 'z') && (s != 'L')
				&& ((s >= 48) && (s <= 57)))
			(*str)++;
		return (1);

	}
	return (0);
}
