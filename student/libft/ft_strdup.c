/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:23:42 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 11:23:45 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	char	*str;

	new_str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (new_str == NULL)
	{
		return (NULL);
	}
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
