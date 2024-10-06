/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:25:13 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 10:25:16 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	if (len == 0)
	{
		return (0);
	}
	while (*s1 && *s2 && *s1 == *s2 && len > 1)
	{
		s1++;
		s2++;
		len--;
	}
	return (((unsigned char)*s1) - ((unsigned char)*s2));
}
