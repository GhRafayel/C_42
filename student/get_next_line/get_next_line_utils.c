/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 11:07:49 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	char	*str;

	new_str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	str = new_str;
	while (*s1)
	{
		*new_str = *s1;
		new_str++;
		s1++;
	}
	*new_str = '\0';
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*p;
	char		*new_str;
	int			length;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(length * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	p = new_str;
	while (*s1)
	{
		*new_str++ = *s1++;
	}
	while (*s2)
	{
		*new_str++ = *s2++;
	}
	*new_str = '\0';
	return (p);
}

char	*ft_substr(const char *s, unsigned start, size_t len)
{
	unsigned int	i;
	char			*new_str;
	size_t			s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s[i + start] && len)
	{
		new_str[i] = s[i + start];
		i++;
		len--;
	}
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlcpy(char *dest, char *src, size_t len)
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
