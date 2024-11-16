/* ************************************************************************** */
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
