/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/10/17 12:35:24 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <ctype.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

size_t	ft_strlen(const char *s);
ssize_t	ft_str_chr(char *str);
char	*get_next_line(int fd);
char	*ft_strdup(char **result, char **str_readed);
char	*ft_str_join(char **result, char **str_readed, ssize_t *count, int *ss);
char	*ft_sub_str(char **dest, char **src, size_t start, size_t len);
#endif
