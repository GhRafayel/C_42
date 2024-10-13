/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 11:07:49 by rghazary         ###   ########.fr       */
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
		{
			res = ft_strdup(&res, &*static_str);
			return (free(*static_str), *static_str = NULL, res);
		}
		str = ft_sub_str(&str, &*static_str, i + 1, ft_strlen(*static_str));
		res = ft_sub_str(&res, &*static_str, 0, i + 1);
		free(*static_str);
		*static_str = NULL;
		*static_str = ft_strdup(&*static_str, &str);
		return (res);
	}
	return (*static_str);
}

char	*get_next_line(int fd)
{
	static char		*static_str;
	char			*str_readed;
	ssize_t			count;

	count = 1;
	if (fd > 1024 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (count)
	{
		str_readed = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (str_readed == NULL)
			return (NULL);
		count = read(fd, str_readed, BUFFER_SIZE);
		if (count < 0)
			return (free(str_readed), free(static_str), static_str = NULL);
		if (count > 0)
		{
			str_readed[count] = '\0';
			ft_str_join(&static_str, &str_readed);
			if (ft_str_chr(static_str) >= 0)
				break ;
		}
		free(str_readed);
	}
	return (ft_control(&static_str));
}
