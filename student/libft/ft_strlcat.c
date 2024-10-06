/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:17:22 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/06 12:17:27 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	index;

	s_len = ft_strlen(src);
	d_len = 0;
	index = 0;
	while (d_len < dest_size && dest[d_len])
		d_len++;
	if (dest_size <= d_len)
		return (dest_size + s_len);
	while (src[index] && d_len + index < dest_size - 1)
	{
		dest[d_len + index] = src[index];
		index++;
	}
	dest[d_len + index] = '\0';
	return (d_len + s_len);
}
