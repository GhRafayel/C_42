/* ************************************************************************** */
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
