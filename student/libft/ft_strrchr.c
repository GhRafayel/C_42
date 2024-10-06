/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:06:53 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 10:06:57 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	*b;

	last = NULL;
	b = (char *)s;
	while (*b)
	{
		if (*b == (char)c)
		{
			last = b;
		}
		b++;
	}
	if (c == '\0')
	{
		return ((char *)b);
	}
	return (last);
}
