/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:56:10 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/27 20:56:12 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *temp, char *readed_str)
{
	char	*ss;

	if (temp != NULL)
	{
		ss = ft_strdup(temp);
		free(temp);
		temp = ft_strjoin(ss, readed_str);
		free(ss);
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

int main(void)
{
    int fd;
    fd = open("t.text", O_RDONLY);
	char *a = get_next_line(fd);
	printf("%s", a);
	free(a);
	printf("%s", a);

    close(fd);
    return 0;
}