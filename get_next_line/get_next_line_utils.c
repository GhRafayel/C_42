/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:56:10 by rghazary          #+#    #+#             */
/*   Updated: 2024/10/17 12:36:08 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

ssize_t	ft_str_chr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char **dest, char **src)
{
	int		i;
	size_t	count;

	i = 0;
	count = ft_strlen(*src);
	*dest = (char *)malloc((count + 1) * sizeof(char));
	if (*dest != NULL)
	{
		while ((*src)[i] != '\0')
		{
			(*dest)[i] = (*src)[i];
			i++;
		}
		(*dest)[i] = '\0';
	}
	free(*src);
	*src = NULL;
	return (*dest);
}

char	*ft_str_join(char **str1, char **str2, ssize_t *count, int *ss)
{
	char	*temp;
	size_t	len;
	size_t	i;
	size_t	j;

	temp = NULL;
	if (ft_str_chr(*str2) >= 0)
		*count = 0;
	else if (*ss * 2 < 2147483647)
		*ss *= 2;
	if (*str1 == NULL)
		return (ft_strdup(&*str1, &*str2));
	len = ft_strlen(*str1) + ft_strlen(*str2) + 1;
	temp = (char *)malloc(len * sizeof(char));
	if (temp == NULL)
		return (free(*str1), *str1 = NULL, free(*str2), str2 = NULL, NULL);
	i = -1;
	while ((*str1)[++i])
		temp[i] = (*str1)[i];
	j = -1;
	free(*str1);
	*str1 = NULL;
	while ((*str2)[++j])
		temp[i + j] = (*str2)[j];
	temp[j + i] = '\0';
	return (free(*str2), *str2 = NULL, ft_strdup(&*str1, &temp));
}

char	*ft_sub_str(char **dest, char **src, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	if (src == NULL || !*src)
	{
		return (NULL);
	}
	*dest = (char *)malloc((len - start + 1) * sizeof(char));
	if (*dest == NULL)
	{
		return (NULL);
	}
	while ((*src)[i + start] && i < len)
	{
		(*dest)[i] = (*src)[start + i];
		i++;
	}
	(*dest)[i] = '\0';
	return (*dest);
}
