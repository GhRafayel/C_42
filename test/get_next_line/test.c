# include <limits.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

size_t ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    while (*s)
    {
        len++;
        s++;
    }
    return (len);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    char *p;
    char *new_str;
    int length;

    length = ft_strlen(s1) + ft_strlen(s2) + 1;
    new_str = (char *)malloc(length * sizeof(char));
    if (new_str == NULL) return (NULL);
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

char *ft_strdup(const char *s1)
{
    char *new_str;
    char *str;

    new_str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
    if (new_str == NULL)  return (NULL);
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

char *ft_substr(const char *s, unsigned start, size_t len)
{
    char *new_str;
    unsigned int i;
    size_t s_len;

    i = 0;
    s_len = ft_strlen(s);
    if (s == NULL) return (NULL);

    if (start >= s_len) return (ft_strdup(""));

    if (len > s_len - start)  len = s_len - start;

    new_str = (char *)malloc((len + 1) * sizeof(char));

    if (new_str == NULL) return (NULL);

    while (s[i + start] && len)
    {
        new_str[i] = s[i + start];
        i++;
        len--;
    }
    new_str[i] = '\0';
    return (new_str);
}
/*
size_t ft_read(int fd, char *str, size_t buffer_size)
{
    size_t readed;

    readed = read(fd, str, buffer_size);
    return (readed);
}

/////////////////////////////////////////////////////////////////////////////////////////

char	*get_next_line(int fd)
{
    static char	*stat_string;
    char		*str;
    char		*new_str;
	char		*temp;
    int					i;
    size_t				buffer_size;
    ssize_t				readed;

    if (fd < 0 || fd > 1024) 
        return (NULL);
    buffer_size = BUFFER_SIZE;
    i = 0;
    readed = 0;
	new_str = NULL;
    while (stat_string == NULL)
    {
		str = (char *)malloc((buffer_size + 1) * sizeof(char));
    	if (str == NULL) return (NULL);
        readed = ft_read(fd, str, buffer_size);
		i += readed;
		if (i == 0)
		{
			free(str);
			return ("");
		}
		if(readed != 0)
        {
			if (new_str == NULL)
			{
				new_str =  ft_strdup(str);
			}
			else
			{
				temp = ft_strdup(new_str);
				free(new_str);
				new_str =  ft_strjoin(temp, str);
				free(temp);
				free(str);
			}
        }
		else
		{
			stat_string = ft_substr(new_str, 0, ft_strlen(new_str));
			free(str);
			free(new_str);
			break;
		}
    }
    i = 0;
    while (stat_string[i] != '\0' && stat_string[i] != '\n')
    {
       i++;
    }
    new_str = ft_substr(stat_string, 0, i + 1);
	temp = ft_strjoin("", stat_string);
	free(stat_string);
    stat_string = ft_substr(temp, i + 1, ft_strlen(temp) - i);
	free(temp);
    return (new_str);
}

int main() {

    int fd = open("file.text", O_RDONLY);
  
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));

    close(fd);
    return (0);
}
//////////////////////////////////////////////////////////////////////////////////////////

char	*ft_free(char *pnt)
{
	free(pnt);
	return (NULL);
}

char	*ft_read_file(char * stat_string, char * new_str, char * temp, int fd)
{
	size_t		buffer_size;
	ssize_t	readed;
	char	*str;
	int 	i;

	i = 0;
	readed = 0;
	buffer_size = BUFFER_SIZE;
	while (stat_string == NULL)
	{
		str = (char *)malloc((buffer_size + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		readed = read(fd, str, buffer_size);
		if (readed == -1)
			return (ft_free(str));
		str[readed] = '\0';
		i += readed;
		if (i == 0)
			return (ft_free(str));
		if (readed != 0)
		{
			if (new_str == NULL)
				new_str = ft_strdup(str);
			else
			{
				temp = new_str;
				new_str = ft_strjoin(new_str, str);
				free(temp);
			}
			free(str);
		}
		else
		{
			stat_string = ft_substr(new_str, 0, ft_strlen(new_str));
			free(new_str);
			free(str);
			break ;
		}
	}
	return(new_str);
}
char	*ft_print_list(char *stat_string, char *new_str, char *temp)
{
		int	i;

		i = 0;
		if (stat_string[0] == '\0') return (ft_free(stat_string));

		while (stat_string[i] != '\0' && stat_string[i] != '\n')
		i++;
		new_str = ft_substr(stat_string, 0, i + 1);
		temp = ft_strdup(stat_string);
		free(stat_string);
		stat_string = ft_substr(temp, i + 1, ft_strlen(temp) - i);
		free(temp);
		return (new_str);
}

char *get_next_line(int fd)
{
	static char	*stat_string;
	char	*new_str;
	char	*temp;
	
	new_str = NULL;
	temp = NULL;
	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
		return (NULL);

	if (stat_string == NULL)
	{
		new_str = ft_read_file(stat_string, new_str, temp, fd);
		if(new_str == NULL)
			return (NULL);
	}
	else
	{
		new_str = ft_print_list(stat_string, new_str, temp);
		if(new_str == NULL)
			return(NULL);
	}
	return (new_str);
}

int main() {

    int fd = open("file.text", O_RDONLY);
  
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));

    close(fd);
    return (0);
}
*/

ssize_t	ft_join(char *readed_str, char **result)
{
	char	*ss;
	int		i;

	i = 0;
	if (*result == NULL)
	{
		*result = ft_strdup(readed_str); // Նոր ալոկացիա հիշողության
		if (*result == NULL)
			return (-1); // Ալոկացման ձախողման դեպքում
	}
	else
	{
		ss = *result;
		*result = ft_strjoin(ss, readed_str); // Նոր հիշողություն
		free(ss); // Ազատում ես նախկին *result-ը
		if (*result == NULL)
			return (-1); // Ալոկացման ձախողման դեպքում
	}
	while ((*result)[i] != '\0') // (*result)[i]
	{
		if ((*result)[i] == '\n')
		{
			return (0); // '\n' գտնված է
		}
		i++;
	}
	return (1); // '\n' չի գտնվել
}


char	*ft_control(char **static_str, char *new_str)
{
	char	*result;
	int		i;

	i = 0;
	if (*static_str != NULL)
	{
		result = ft_strjoin(*static_str, new_str);
		*static_str = result;
	}
	else
	{
		result = ft_strdup(new_str);
	}	
	while (result[i])
	{
		if (result[i] == '\n' && result[i + 1] != '\0')
		{
			*static_str = ft_substr(result, i + 1, ft_strlen(result));
		 	result = ft_substr(result, 0, i + 1);
		 	free(new_str);
			break;
		}
		i++;
	}
	return (result);
}

char	*ft_read(int fd)
{
	ssize_t	readed;
	char	*readed_str;
	char	*result;

	readed = 1;
	result = NULL;
	readed_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (readed_str == NULL)
			return (NULL);
	while (readed)
	{
		readed = read(fd, readed_str, BUFFER_SIZE);
		if (readed == -1 || readed == 0)
		{
			free(readed_str);
			return (NULL);
		}
		readed_str[readed] = '\0';
		readed = ft_join(readed_str, &result);
	}
	free(readed_str);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	char		*new_str;

	new_str = NULL;
	if (fd > 255 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_str = ft_read(fd);
	if (new_str == NULL && static_str == NULL)
		return (NULL);
	

	// if (new_str != NULL || static_str != NULL)
	// {
	// 	if (static_str != NULL && !static_str[0])
	// 	{
	// 		static_str = NULL;
	// 	}
	// 	new_str = ft_control(&static_str, new_str);
	// }
	return (ft_control(&static_str, new_str));
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