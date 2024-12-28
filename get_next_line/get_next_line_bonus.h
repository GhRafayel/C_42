/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:40:33 by rghazary          #+#    #+#             */
/*   Updated: 2024/10/17 12:35:47 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef MAX_FD
#  define MAX_FD 256
# endif

size_t	ft_strlen(const char *s);
ssize_t	ft_str_chr(char *str);
char	*get_next_line(int fd);
char	*ft_strdup(char **result, char **str_readed);
char	*ft_str_join(char **result, char **str_readed, ssize_t *count);
char	*ft_sub_str(char **dest, char **src, size_t start, size_t len);
#endif
