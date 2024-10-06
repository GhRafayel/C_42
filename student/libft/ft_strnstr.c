/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:46:10 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 10:46:13 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_n;
	size_t	i_h;
	char	*p_needle_first;

	i_h = 0;
	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[i_h] != '\0' && len > i_h)
	{
		i_n = 0;
		while (haystack[i_h + i_n] == needle[i_n]
			&& len > i_h && (i_h + i_n) < len)
		{
			p_needle_first = (char *)haystack + i_h;
			if (needle[i_n + 1] == '\0')
			{
				return (p_needle_first);
			}
			i_n++;
		}
		i_h++;
	}
	return (NULL);
}
