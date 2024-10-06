/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:46:21 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 11:46:27 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		new_str[i] = *s2++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
