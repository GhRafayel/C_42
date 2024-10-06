/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:20:29 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/06 10:20:32 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	l;

	l = ft_strlen(src);
	if (len == 0)
	{
		return (l);
	}
	while (*src && len > 1)
	{
		*dest = *src;
		dest++;
		src++;
		len--;
	}
	*dest = '\0';
	return (l);
}
