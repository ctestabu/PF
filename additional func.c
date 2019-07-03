/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 19:26:34 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/02 19:26:34 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = -1;
	if (n < 0)
	{
		while (str[++i] && i < (int)ft_strlen(str) + n)
			ft_putchar(str[i]);
	}
	else
	{
		while (str[++i] && i < n)
			ft_putchar(str[i]);
	}
}

void	ft_putstrwp(char *str, int precision) /*with precision */
{
	if ((precision != -1) && ((size_t)precision < ft_strlen(str)))
	{
		while (precision--)
		{
			ft_putchar(*str);
			str++;
		}
	}
	else
		ft_putstr(str);
}