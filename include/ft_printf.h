/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:04:55 by ctestabu          #+#    #+#             */
/*   Updated: 2019/06/30 15:04:55 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <wchar.h>
#include <float.h>
#include <stdio.h>
#include <inttypes.h>
#include "../libft/libft.h"

typedef struct	s_printf
{
	int flag_sharp;
	int flag_zero;
	int flag_minus;
	int flag_plus;
	int flag_space;

	int width;
	int precision;

	char *length;
	char conversion;
}				t_printf;

char 	*check_flags(char **str, t_printf *elem);
char	*check_width(char **str, t_printf *elem);
char 	*check_precision(char **str, t_printf *elem);
char 	*check_len(char **str, t_printf *elem);
int 	check_conversion(char **str, char *ch, t_printf *elem);
void	ft_putnstr(char *str, int n);
void	ft_putstrwp(char *str, int precision);
short	ft_countnbr(long nbr);
void	ft_putunbrwp(unsigned long nbr, int precision);
void	ft_putnbrwp(long nbr, int precision);
int		ft_percent(t_printf *elem);
int 	ft_s(char *str, t_printf *elem);
int		ft_l(long nbr, t_printf *elem);
int		ft_cwl(wint_t c, t_printf *elem);
int		ft_c(int c, t_printf *elem);
int				treat(t_printf *elem, va_list ap);
char			*ft_itoabaseu(uintmax_t nbr, int base, char min);
int		ft_p(void *address, t_printf *elem);
int		ft_invalid_input(char c, t_printf *elem);
short	ft_countunbr(unsigned long nbr);
int		end_o(char *str, int count, t_printf *elem);
int		ft_o(unsigned long nbr, t_printf *elem);
int		ft_x(unsigned long nbr, char letter, t_printf *elem);
void	ft_putzerox(char letter);
int		ft_oux(unsigned long nbr, char letter, t_printf *elem);
int		ft_count_unicode(wchar_t c);
void	four_bytes(wchar_t c);
void	three_bytes(wchar_t c);
void	two_bytes(wchar_t c);

#endif
