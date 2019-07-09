/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:40:17 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/09 17:40:17 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	one_byte(char c)
{
	char	nbr;

	nbr = 2;
	nbr = (nbr << 6);
	nbr += c;
	ft_putchar(nbr);
}

void	four_bytes(wchar_t c)
{
	char	nbr;

	nbr = 30;
	nbr = (nbr << 3);
	nbr += (char)(c >> 18);
	c = (c & 65535);
	ft_putchar(nbr);
	nbr = 2;
	nbr = (nbr << 6);
	nbr += (char)(c >> 12);
	c = (c & 4095);
	ft_putchar(nbr);
	nbr = 2;
	nbr = (nbr << 6);
	nbr += (char)(c >> 6);
	c = (c & 63);
	ft_putchar(nbr);
	one_byte(c);
}

void	three_bytes(wchar_t c)
{
	int	nbr;

	nbr = 14;
	nbr = (nbr << 4);
	nbr += (char)(c >> 12);
	c = (c & 4095);
	ft_putchar(nbr);
	nbr = 2;
	nbr = (nbr << 6);
	nbr += (char)(c >> 6);
	c = (c & 63);
	ft_putchar(nbr);
	one_byte(c);
}

void	two_bytes(wchar_t c)
{
	int		nbr;

	nbr = 6;
	nbr = (nbr << 5);
	nbr += (c >> 6);
	c = (c & 63);
	ft_putchar(nbr);
	one_byte(c);
}