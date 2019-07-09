/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:22:11 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/05 19:22:11 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//void	print_wchar(wchar_t *str, int countp)
//{
//	int i;
//	int j;
//
//	i = -1;
//	j = 0;
//	while (str[++i] && (countp > j))
//	{
//		ft_unicode(str[i]);
//		j += ft_count_unicode(str[i]);
//	}
//}
//
//int		count_precision(wchar_t *str, t_printf *elem)
//{
//	int count;
//	int i;
//
//	count = 0;
//	i = -1;
//	while (str[++i] && ((count + ft_count_unicode(str[i])) <= elem->precision))
//		count += ft_count_unicode(str[i]);
//	return (count);
//}
//
//int		w_precision(wchar_t *str, t_printf *elem)
//{
//	int i;
//	int	countp;
//
//	i = -1;
//	countp = count_precision(str, elem);
//	if (elem->flag_minus == 1)
//		print_wchar(str, countp);
//	if (elem->width)
//	{
//		i = elem->width - countp;
//		if (elem->flag_zero == 1)
//			while (i-- > 0)
//				ft_putchar('0');
//		else
//			while (i-- > 0)
//				ft_putchar(' ');
//		i = -1;
//	}
//	if (elem->flag_minus != 1)
//		print_wchar(str, countp);
//	if (elem->width > countp)
//		return (elem->width);
//	return (countp);
//}
//
//void	w_width(wchar_t *str, t_printf *elem)
//{
//	int i;
//	int count;
//
//	i = -1;
//	if (elem->flag_minus == 1)
//		while (str[++i])
//			ft_unicode(str[i]);
//	count = elem->width - ft_count_multiple_unicode(str);
//	if (elem->flag_zero == 1)
//		while (count-- > 0)
//			ft_putchar('0');
//	else
//		while (count-- > 0)
//			ft_putchar(' ');
//	if (elem->flag_minus != 1)
//		while (str[++i])
//			ft_unicode(str[i]);
//}
//
//int		ft_smaj(wchar_t *str, t_printf *elem)
//{
//	int		count;
//	int		i;
//
//	if (!str)
//		return (is_null(elem));
//	count = 0;
//	i = -1;
//	if (elem->precision != -1)
//		return (w_precision(str, elem));
//	else if (elem->width)
//		w_width(str, elem);
//	else
//		while (str[++i])
//			ft_unicode(str[i]);
//	count = ft_count_multiple_unicode(str);
//	if (elem->width > count)
//		return (elem->width);
//	return (count);
//}