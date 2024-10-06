/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:20:50 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/04 16:20:52 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	if (dest == NULL && src == NULL)
		return (dest);
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (pdest > psrc)
	{
		pdest += n;
		psrc += n;
		while (n--)
		{
			*(--pdest) = *(--psrc);
		}
	}
	else
	{
		while (n--)
		{
			*(pdest++) = *(psrc++);
		}
	}
	return (dest);
}
