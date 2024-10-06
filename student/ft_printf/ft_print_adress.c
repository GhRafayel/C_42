/* ************************************************************************** */
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
