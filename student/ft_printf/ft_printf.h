/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:45:53 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/23 13:45:55 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>
// # include <bsd/string.h>

int		ft_printf(const char *str, ...);
ssize_t	ft_print_hex(char c, unsigned int num);
ssize_t	ft_print_adress(intptr_t arg);
ssize_t	ft_print_u(unsigned int n);
ssize_t	ft_print_i_d(int num);

#endif
