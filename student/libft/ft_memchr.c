/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:56:42 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 09:56:45 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ps;
	unsigned char		pc;

	ps = s;
	pc = (unsigned char)c;
	while (n--)
	{
		if (*ps == pc)
		{
			return ((void *)ps);
		}
		ps++;
	}
	return (NULL);
}
