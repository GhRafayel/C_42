/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:58:17 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 11:58:21 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	start;
	size_t	len;

	len = ft_strlen(s1);
	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	while (len > start && ft_strchr(set, s1[len - 1]))
	{
		len--;
	}
	new_str = ft_substr(s1, start, len - start);
	return (new_str);
}
