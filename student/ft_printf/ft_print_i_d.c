/* ************************************************************************** */
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
