/* ************************************************************************** */
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

static ssize_t	ft_format(const char *str, int i, va_list arg)
{
	ssize_t	count;

	count = 0;
	if (str[i] < 13)
	{
		if (str[i] == '\0')
		{
			return (-1);
		}
		count += write(1, &str[i - 1], 1);
		count += write(1, &str[i], 1);
	}
	else
	{
		count += ft_printf_decide(str[i], arg);
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
			num = ft_format(str, ++i, arg);
			if (num == -1)
				return (-1);
			count += num;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
			count += write(1, &str[++i], 1);
		else
			count += write(1, &str[i], 1);
	}
	return (count);
}