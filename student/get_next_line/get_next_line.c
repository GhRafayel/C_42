/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 11:07:49 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char	*ft_free(char *pnt)
{
	free(pnt);
	return (NULL);
}

char	*join_strs(char *new_str, char *str)
{
	char	*temp;

	if (new_str == NULL)
	{
		new_str = ft_strdup(str);
	}
	else
	{
		temp = ft_strdup(new_str);
		free(new_str);
		new_str = ft_strjoin(temp, str);
		free(temp);
	}
	free(str);
	return (new_str);
}

char	*ft_read(size_t buffer_size, int fd)
{
	char		*new_str;
	char		*str;
	ssize_t		readed;

	readed = 1;
	new_str = NULL;
	while (readed)
	{
		str = (char *)malloc((buffer_size + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		readed = read(fd, str, buffer_size);
		if (readed == -1)
			return (ft_free(str));
		if (readed != 0)
		{
			str[readed] = '\0';
			new_str = join_strs(new_str, str);
		}
		else
			free(str);
	}
	return (new_str);
}

char	*to_print_lin(char **stat_string)
{
	char	*new_str;
	char	*temp;
	int		i;

	new_str = NULL;
	temp = NULL;
	i = 0;
	if (*stat_string != NULL && (*stat_string)[i] == '\0')
	{
		return (ft_free(*stat_string));
	}
	while ((*stat_string)[i] != '\0' && (*stat_string)[i] != '\n')
		i++;
	new_str = ft_substr(*stat_string, 0, i + 1);
	temp = ft_strdup(*stat_string);
	free(*stat_string);
	*stat_string = ft_substr(temp, i + 1, ft_strlen(temp) - i);
	free(temp);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char		*stat_string;
	char			*new_str;
	size_t			buffer_size;

	buffer_size = BUFFER_SIZE;
	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stat_string == NULL)
	{
		stat_string = ft_read(buffer_size, fd);
		if (stat_string == NULL)
		{
			return (NULL);
		}
	}
	new_str = to_print_lin(&stat_string);
	return (new_str);
}*/


char	*ft_join(char *temp, char *readed_str)
{
	char	*ss;

	if (temp != NULL)
	{
		ss = ft_strjoin(temp, readed_str);
		free(temp);
		free(readed_str);
		return (ss);
	}
	else
		temp = ft_strdup(readed_str);
	free(readed_str);
	return (temp);
}

char	*ft_read(int fd, size_t buffer)
{
	ssize_t	readed;
	char	*readed_str;
	char	*temp;
	int		i;

	temp = NULL;
	readed = 1;
	while (readed)
	{
		readed_str = (char *)malloc((buffer + 1) * sizeof(char));
		if (readed_str == NULL)
			return (NULL);
		readed = read(fd, readed_str, buffer);
		if (readed == -1)
		{
			free(readed_str);
			return (NULL);
		}
		readed_str[readed] = '\0';
		if (readed == 0)
		{
			free(readed_str);
			return (temp);
		}
		i = 0;
		while (readed_str[i])
		{
			if (readed_str[i] == '\n')
			{
				temp = ft_join(temp, readed_str);
				return (temp);
			}
			i++;
		}
		temp = ft_join(temp, readed_str);
	}
	return (temp);
}

char	*ft_control(char **static_str, char *new_str)
{
	char	*ss;
	int		i;

	i = 0;
	if (!new_str)
		return (*static_str);
	if (*static_str != NULL)
	{
		ss = ft_strjoin(*static_str, new_str);
		free(new_str);
		free(*static_str);
	}
	else
	{
		ss = ft_strdup(new_str);
		free(new_str);
	}
	while (ss[i])
	{
		if(ss[i] == '\n' && ss[i + 1] != '\0')
		{
			*static_str = ft_substr(ss, i + 1, ft_strlen(ss));
		 	new_str = ft_substr(ss, 0, i + 1);
		 	free(ss);
			return (new_str);
		}
		i++;
	}
	return (ss);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	char	*new_str;
	size_t	buffer;

	new_str = NULL;
	buffer = BUFFER_SIZE;
	if (fd > 255 || fd < 0 || buffer < 0)
		return (NULL);
	new_str = ft_read(fd, buffer);
	if (new_str != NULL || static_str != NULL)
	{
		return (ft_control(&static_str, new_str));
	}
	return (new_str);
}