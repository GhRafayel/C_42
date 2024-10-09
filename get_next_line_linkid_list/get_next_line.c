
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
	return (temp);
}

char	*ft_control(char **static_str, char *new_str)
{
	char	*ss;
	int i = 0;
	
	if (new_str)
	{
		if(*static_str != NULL)
		{
			ss = ft_strjoin(*static_str, new_str);
			free(*static_str);
		}
		else
		{
			ss = ft_strdup(new_str);
		}
		free(new_str);
	}
	else
	{
		ss = ft_strdup(*static_str);
		free(*static_str);
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

char	*ft_read(int fd)
{
	ssize_t	readed;
	char	*readed_str;
	char	*temp;
	int  i;

	temp = NULL;
	readed = 1;
	while (readed)
	{
		readed_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (readed_str == NULL)
			return (NULL);
		readed = read(fd, readed_str, BUFFER_SIZE);
		if (readed == -1)
		{
			free(readed_str);
			return(NULL);
		}
		readed_str[readed] = '\0';
		if (readed == 0)
		{
			free(readed_str);
			return (temp);
		}
		i = 0;
		while(readed_str[i])
		{
			if(readed_str[i] == '\n')
			{
				temp = ft_join(temp, readed_str);
				free(readed_str);
				return (temp);
			}
			i++;
		}
		temp = ft_join(temp, readed_str);
		free(readed_str);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	//static MyStruct  static_obj;
	char	*new_str;
	new_str = NULL;
	if (fd > 255 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_str = ft_read(fd);
	if (new_str != NULL || static_str != NULL)
	{
		if (static_str != NULL && static_str[0] == '\0')
		{
			static_str = NULL;
		}
		new_str = ft_control(&static_str, new_str);
	}
	return (new_str);
}

int main(void)
{
    int fd;
    fd = open("t.text", O_RDONLY);
   
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

    printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

    close(fd);
    return 0;
}
