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

#endif
