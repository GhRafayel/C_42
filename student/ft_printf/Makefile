._ft_print_adress.c                                                                                 000644  000765  000024  00000000333 14700167521 017322  0                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                             Mac OS X            	   2   �      �                                      ATTR       �   �   #                  �     com.apple.provenance    �     com.apple.quarantine  a�&*�n7q/0081;66fa58c2;Chrome;                                                                                                                                                                                                                                                                                                      PaxHeader/ft_print_adress.c                                                                         000644  000765  000024  00000000411 14700167521 021053  x                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                         30 mtime=1728114513.430127894
70 LIBARCHIVE.xattr.com.apple.quarantine=MDA4MTs2NmZhNThjMjtDaHJvbWU7
59 SCHILY.xattr.com.apple.quarantine=0081;66fa58c2;Chrome;
57 LIBARCHIVE.xattr.com.apple.provenance=AQIAYeARJiq4bjc
49 SCHILY.xattr.com.apple.provenance= a�&*�n7
                                                                                                                                                                                                                                                       ft_print_adress.c                                                                                   000644  000765  000024  00000002705 14700167521 017112  0                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 21:04:08 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/27 21:04:10 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	ssize_t	ft_print_pnter(unsigned long long arg)
{
	ssize_t		count;
	size_t		index;
	char		*hex_low;

	count = 0;
	hex_low = "0123456789abcdef";
	if (arg >= 16)
	{
		index = arg % 16;
		count += ft_print_pnter(arg / 16);
		count += write(1, &hex_low[index], 1);
	}
	else
	{
		count += write(1, &hex_low[arg], 1);
	}
	return (count);
}

ssize_t	ft_print_adress(intptr_t arg)
{
	ssize_t	count;

	count = 0;
	if (arg == 0)
	{
		return (write(1, "0x0", 3));
	}
	count += write(1, "0x", 2);
	count += ft_print_pnter((unsigned long long)arg);
	return (count);
}
                                                           ._ft_print_hex.c                                                                                    000644  000765  000024  00000000333 14700167465 016634  0                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                             Mac OS X            	   2   �      �                                      ATTR       �   �   #                  �     com.apple.provenance    �     com.apple.quarantine  a�&*�n7q/0081;66fa58c2;Chrome;                                                                                                                                                                                                                                                                                                      PaxHeader/ft_print_hex.c                                                                            000644  000765  000024  00000000411 14700167465 020365  x                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                         30 mtime=1728114485.265825384
70 LIBARCHIVE.xattr.com.apple.quarantine=MDA4MTs2NmZhNThjMjtDaHJvbWU7
59 SCHILY.xattr.com.apple.quarantine=0081;66fa58c2;Chrome;
57 LIBARCHIVE.xattr.com.apple.provenance=AQIAYeARJiq4bjc
49 SCHILY.xattr.com.apple.provenance= a�&*�n7
                                                                                                                                                                                                                                                       ft_print_hex.c                                                                                      000644  000765  000024  00000002523 14700167465 016422  0                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:56:10 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/27 20:56:12 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print_hex(char c, unsigned int num)
{
	ssize_t		count;
	size_t		index;
	char		*hex;

	count = 0;
	index = 0;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (num == 16)
		count += write(1, "10", 2);
	else if (num > 16)
	{
		index = num % 16;
		count += ft_print_hex(c, num / 16);
		count += write(1, &hex[index], 1);
	}
	else
	{
		index = num;
		count += write(1, &hex[index], 1);
	}
	return (count);
}
                                                                                                                                                                             ._ft_print_i_d.c                                                                                    000644  000765  000024  00000000333 14700167426 016600  0                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                             Mac OS X            	   2   �      �                                      ATTR       �   �   #                  �     com.apple.provenance    �     com.apple.quarantine  a�&*�n7q/0081;66fa58c2;Chrome;                                                                                                                                                                                                                                                                                                      PaxHeader/ft_print_i_d.c                                                                            000644  000765  000024  00000000411 14700167426 020331  x                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                         30 mtime=1728114454.184674025
70 LIBARCHIVE.xattr.com.apple.quarantine=MDA4MTs2NmZhNThjMjtDaHJvbWU7
59 SCHILY.xattr.com.apple.quarantine=0081;66fa58c2;Chrome;
57 LIBARCHIVE.xattr.com.apple.provenance=AQIAYeARJiq4bjc
49 SCHILY.xattr.com.apple.provenance= a�&*�n7
                                                                                                                                                                                                                                                       ft_print_i_d.c                                                                                      000644  000765  000024  00000002360 14700167426 016365  0                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 21:06:47 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/27 21:06:49 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print_i_d(int num)
{
	long long int	n;
	ssize_t			i;
	char			chr;

	i = 0;
	if (num == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (num < 0)
	{
		n = num * -1;
		i += write(1, "-", 1);
	}
	else
	{
		n = num;
	}
	if (n > 9)
	{
		i += ft_print_i_d(n / 10);
	}
	chr = n % 10 + 48;
	i += write(1, &chr, 1);
	return (i);
}
                                                                                                                                                                                                                                                                                ._ft_print_u.c                                                                                      000644  000765  000024  00000000333 14700167441 016306  0                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                             Mac OS X            	   2   �      �                                      ATTR       �   �   #                  �     com.apple.provenance    �     com.apple.quarantine  a�&*�n7q/0081;66fa58c2;Chrome;                                                                                                                                                                                                                                                                                                      PaxHeader/ft_print_u.c                                                                              000644  000765  000024  00000000411 14700167441 020037  x                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                         30 mtime=1728114465.390665779
70 LIBARCHIVE.xattr.com.apple.quarantine=MDA4MTs2NmZhNThjMjtDaHJvbWU7
59 SCHILY.xattr.com.apple.quarantine=0081;66fa58c2;Chrome;
57 LIBARCHIVE.xattr.com.apple.provenance=AQIAYeARJiq4bjc
49 SCHILY.xattr.com.apple.provenance= a�&*�n7
                                                                                                                                                                                                                                                       ft_print_u.c                                                                                        000644  000765  000024  00000002167 14700167441 016100  0                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 21:02:01 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/27 21:02:03 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print_u(unsigned int n)
{
	ssize_t			count;
	char			chr;

	count = 0;
	if (n > 9)
	{
		chr = n % 10 + 48;
		count += ft_print_u(n / 10);
	}
	else
	{
		chr = n + 48;
	}
	count += write(1, &chr, 1);
	return (count);
}
                                                                                                                                                                                                                                                                                                                                                                                                         ._ft_printf.c                                                                                       000644  000765  000024  00000000333 14700325203 016120  0                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                             Mac OS X            	   2   �      �                                      ATTR       �   �   #                  �     com.apple.provenance    �     com.apple.quarantine  a�&*�n7q/0081;66fa58c2;Chrome;                                                                                                                                                                                                                                                                                                      PaxHeader/ft_printf.c                                                                               000644  000765  000024  00000000410 14700325203 017650  x                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                         29 mtime=1728162435.94219045
70 LIBARCHIVE.xattr.com.apple.quarantine=MDA4MTs2NmZhNThjMjtDaHJvbWU7
59 SCHILY.xattr.com.apple.quarantine=0081;66fa58c2;Chrome;
57 LIBARCHIVE.xattr.com.apple.provenance=AQIAYeARJiq4bjc
49 SCHILY.xattr.com.apple.provenance= a�&*�n7
                                                                                                                                                                                                                                                        ft_printf.c                                                                                         000644  000765  000024  00000004625 14700325203 015713  0                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:00:03 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/27 11:00:07 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_print_str(const char *str)
{
	ssize_t	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		count += write (1, str++, 1);
	}
	return (count);
}

static ssize_t	ft_printf_decide(char c, va_list arg)
{
	char	chr;

	if (c == 's')
		return (ft_print_str(va_arg(arg, char *)));
	else if (c == 'c')
	{
		chr = (char)va_arg(arg, int);
		return (write(1, &chr, 1));
	}
	else if (c == 'd' || c == 'i')
	{
		return (ft_print_i_d(va_arg(arg, int)));
	}
	else if (c == 'u')
	{
		return (ft_print_u(va_arg(arg, unsigned int)));
	}
	else if (c == 'p')
		return (ft_print_adress(va_arg(arg, intptr_t)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(c, va_arg(arg, unsigned int)));
	return (-1);
}

static ssize_t	ft_format(const char *str, int i, va_list *arg)
{
	ssize_t	count;

	count = 0;
	if (str[i] < 13)
	{
		if (str[i] == '\0')
		{
			return (-1);
		}
		count += write(1, &str[i], 1);
	}
	else
	{
		count += ft_printf_decide(str[i], *arg);
		va_arg(*arg, int);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	ssize_t		count;
	ssize_t		i;
	ssize_t		num;

	i = -1;
	count = 0;
	va_start(arg, str);
	if (!str)
		return (-1);
	while (str[++i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			num = ft_format(str, ++i, &arg);
			if (num == -1)
				return (count);
			count += num;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
			count += write(1, &str[++i], 1);
		else
			count += write(1, &str[i], 1);
	}
	va_end(arg);
	return (count);
}                                                                                                           ._ft_printf.h                                                                                       000644  000765  000024  00000000333 14700170145 016130  0                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                             Mac OS X            	   2   �      �                                      ATTR       �   �   #                  �     com.apple.provenance    �     com.apple.quarantine  a�&*�n7q/0081;66fa58c2;Chrome;                                                                                                                                                                                                                                                                                                      PaxHeader/ft_printf.h                                                                               000644  000765  000024  00000000411 14700170145 017661  x                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                         30 mtime=1728114789.969733884
70 LIBARCHIVE.xattr.com.apple.quarantine=MDA4MTs2NmZhNThjMjtDaHJvbWU7
59 SCHILY.xattr.com.apple.quarantine=0081;66fa58c2;Chrome;
57 LIBARCHIVE.xattr.com.apple.provenance=AQIAYeARJiq4bjc
49 SCHILY.xattr.com.apple.provenance= a�&*�n7
                                                                                                                                                                                                                                                       ft_printf.h                                                                                         000644  000765  000024  00000002460 14700170145 015716  0                                                                                                    ustar 00rafayelghazaryan                staff                           000000  000000                                                                                                                                                                         /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:45:53 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/23 13:45:55 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>
// # include <bsd/string.h>

int		ft_printf(const char *str, ...);
ssize_t	ft_print_hex(char c, unsigned int num);
ssize_t	ft_print_adress(intptr_t arg);
ssize_t	ft_print_u(unsigned int n);
ssize_t	ft_print_i_d(int num);

#endif
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                