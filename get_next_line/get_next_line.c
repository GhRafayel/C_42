/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/10/17 12:35:15 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_control(char **static_str)
{
	ssize_t	i;
	char	*str;
	char	*res;

	i = 0;
	if (*static_str != NULL)
	{
		if ((*static_str)[0] == '\0')
			return (free(*static_str), *static_str = NULL);
		i = ft_str_chr(*static_str);
		if (i < 0)
			return (ft_strdup(&res, static_str), res);
		str = ft_sub_str(&str, &*static_str, i + 1, ft_strlen(*static_str));
		if (str == NULL)
			return (free(*static_str),*static_str = NULL);
		res = ft_sub_str(&res, static_str, 0, i + 1);
		if (res == NULL)
			return (free(str), free(*static_str), *static_str = NULL);
		free(*static_str);
		*static_str = NULL;
		*static_str = str;
		return (res);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*static_str;
	char			*str_readed;
	ssize_t			count;
	int				ss;

	ss = BUFFER_SIZE;
	count = 1;
	if (fd < 0 || fd > 1024 || ss <= 0)
		return (NULL);
	while (count)
	{
		str_readed = (char *)malloc((ss + 1) * sizeof(char));
		if (str_readed == NULL)
			return (free(static_str), static_str = NULL, NULL);
		count = read(fd, str_readed, ss);
		if (count < 0)
			return (free(str_readed), free(static_str), static_str = NULL);
		if (count > 0)
		{
			str_readed[count] = '\0';
			ft_str_join(&static_str, &str_readed, &count);
		}
		else
			free(str_readed);
	}
	return (ft_control(&static_str));
}
