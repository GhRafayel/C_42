/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:08:14 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 15:08:16 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned start, size_t end)
{
	char		*new_str;
	size_t		i;
	size_t		s_len;

	i = -1;
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		new_str = (char *)malloc(1);
		if (new_str == NULL)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	if (end > s_len - start)
		end = s_len - start;
	new_str = (char *)malloc((end + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s[++i + start] && i < end)
	{
		new_str[i] = s[i + start];
	}
	new_str[i] = '\0';
	return (new_str);
}
