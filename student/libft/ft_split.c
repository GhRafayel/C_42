/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:03:29 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/10 12:03:32 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	how_many_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static void	*ft_free(char **result, int i)
{
	while (i > 0)
	{
		free(result[--i]);
	}
	free(result);
	return (NULL);
}

static char	**ft_creat_list( char **result, const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;

	end = 0;
	start = 0;
	i = 0;
	while (s[start] != '\0')
	{
		if (s[start] != c)
		{
			end = 0;
			while (s[end + start] != c && s[end + start] != '\0')
				end++;
			result[i] = ft_substr(s, start, end);
			if (result[i] == NULL)
				return (ft_free (result, i));
			i++;
			start += end;
		}
		else
			start++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (s == NULL)
	{
		return (NULL);
	}
	result = (char **)malloc((how_many_words(s, c) + 1) * sizeof(char *));
	if (result == NULL)
	{
		return (NULL);
	}
	return (ft_creat_list(result, s, c));
}
