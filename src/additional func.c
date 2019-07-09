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

short	ft_countnbr(long nbr)
{
	short count;

	if (nbr == -9223372036854775807 - 1)
		return (20);
	if (!nbr)
		return (1);
	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	ft_putunbr(unsigned long n)
{
	if (n > 9)
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
	else
		ft_putchar((char)(n + 48));
}

void	ft_putunbrwp(unsigned long nbr, int precision)
{
	short count;

	if (precision > 0)
	{
		count = ft_countnbr(nbr);
		count = precision - count;
		while (count-- > 0)
			ft_putchar('0');
	}
	if (nbr || precision)
		ft_putunbr(nbr);
}

void	ft_putnbrwp(long nbr, int precision)
{
	short count;

	if (precision > 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		count = ft_countnbr(nbr);
		count = precision - count;
		while (count-- > 0)
			ft_putchar('0');
	}
	if (nbr || precision)
		ft_putnbr(nbr);
}

//static uintmax_t	get_size(uintmax_t nbr, int base)
//{
//	int i;
//
//	if (!nbr)
//		return (1);
//	i = 0;
//	while (nbr)
//	{
//		nbr /= base;
//		i++;
//	}
//	return (i);
//}
//
//static char		*set_tab_maj(void)
//{
//	char	*str;
//
//	str = (char*)malloc(sizeof(char) * 16);
//	str[0] = '0';
//	str[1] = '1';
//	str[2] = '2';
//	str[3] = '3';
//	str[4] = '4';
//	str[5] = '5';
//	str[6] = '6';
//	str[7] = '7';
//	str[8] = '8';
//	str[9] = '9';
//	str[10] = 'A';
//	str[11] = 'B';
//	str[12] = 'C';
//	str[13] = 'D';
//	str[14] = 'E';
//	str[15] = 'F';
//	return (str);
//}
//
//static char		*set_tab_min(void)
//{
//	char	*str;
//
//	str = (char*)malloc(sizeof(char) * 16);
//	str[0] = '0';
//	str[1] = '1';
//	str[2] = '2';
//	str[3] = '3';
//	str[4] = '4';
//	str[5] = '5';
//	str[6] = '6';
//	str[7] = '7';
//	str[8] = '8';
//	str[9] = '9';
//	str[10] = 'a';
//	str[11] = 'b';
//	str[12] = 'c';
//	str[13] = 'd';
//	str[14] = 'e';
//	str[15] = 'f';
//	return (str);
//}
//
//char			*ft_itoabaseu(uintmax_t nbr, int base, char min)
//{
//	char	*tab;
//	char	*str;
//	int		i;
//	int		size;
//
//	if (!base)
//		return (NULL);
//	if (min)
//		tab = set_tab_min();
//	else
//		tab = set_tab_maj();
//	size = get_size(nbr, base);
//	str = (char*)malloc(sizeof(char) * (size + 1));
//	i = size - 1;
//	if (!nbr)
//		str[i--] = tab[nbr % base];
//	while (nbr)
//	{
//		str[i--] = tab[nbr % base];
//		nbr /= base;
//	}
//	str[size] = '\0';
//	free(tab);
//	return (str);
//}

short	ft_countunbr(unsigned long nbr)
{
	short count;

	if (!nbr)
		return (1);
	count = 0;
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	ft_putzerox(char letter)
{
	if (letter == 'x')
		ft_putstr("0x");
	else
		ft_putstr("0X");
}