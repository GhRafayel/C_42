# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
ssize_t	ft_print_hex(char c, unsigned int num);
ssize_t	ft_print_adress(intptr_t arg);
ssize_t	ft_print_u(unsigned int n);
ssize_t	ft_print_i_d(int num);
static	ssize_t	ft_print_pnter(unsigned long long arg)
{
	ssize_t		count;
	size_t		index;
	char		*hex_low;

	count = 0;
	hex_low = "0123456789abcdef";
	if (arg >= 16)
	{
		index = arg % 16;
		count += ft_print_pnter(arg / 16);
		count += write(1, &hex_low[index], 1);
	}
	else
	{
		count += write(1, &hex_low[arg], 1);
	}
	return (count);
}
ssize_t	ft_print_hex(char c, unsigned int num)
{
	size_t		count;
	size_t		index;
	char		*hex;

	count = 0;
	index = 0;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (num == 16)
		count += write(1, "10", 2);
	else if (num > 16)
	{
		index = num % 16;
		count += ft_print_hex(c, num / 16);
		count += write(1, &hex[index], 1);
	}
	else
	{
		index = num;
		count += write(1, &hex[index], 1);
	}
	return (count);
}

ssize_t	ft_print_i_d(int num)
{
	long long int	n;
	size_t			i;
	char			chr;

	i = 0;
	if (num == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (num < 0)
	{
		n = num * -1;
		i += write(1, "-", 1);
	}
	else
	{
		n = num;
	}
	if (n > 9)
	{
		i += ft_print_i_d(n / 10);
	}
	chr = n % 10 + 48;
	i += write(1, &chr, 1);
	return (i);
}

ssize_t	ft_print_u(unsigned int n)
{
	size_t			count;
	char			chr;

	count = 0;
	if (n > 9)
	{
		chr = n % 10 + 48;
		count += ft_print_u(n / 10);
	}
	else
	{
		chr = n + 48;
	}
	count += write(1, &chr, 1);
	return (count);
}

ssize_t	ft_print_adress(intptr_t arg)
{
	size_t	count;

	count = 0;
	if (arg == 0)
	{
		return (write(1, "(nil)", 5));
	}
	count += write(1, "0x", 2);
	count += ft_print_pnter((unsigned long long)arg);
	return (count);
}

static ssize_t	ft_print_str(const char *str)
{
	ssize_t	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		count += write (1, str++, 1);
	}
	return (count);
}

static ssize_t	ft_printf_decide(char c, va_list arg)
{
	char	chr;

	if (c == 's')
		return (ft_print_str(va_arg(arg, char *)));
	else if (c == 'c')
	{
		chr = (char)va_arg(arg, int);
		return (write(1, &chr, 1));
	}
	else if (c == 'd' || c == 'i')
	{
		return (ft_print_i_d(va_arg(arg, int)));
	}
	else if (c == 'u')
	{
		return (ft_print_u(va_arg(arg, unsigned int)));
	}
	else if (c == 'p')
		return (ft_print_adress(va_arg(arg, intptr_t)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(c, va_arg(arg, unsigned int)));
	return (-1);
}

static ssize_t	ft_format(const char *str, int i, va_list *arg)
{
	ssize_t	count;

	count = 0;
	if (str[i] < 13)
	{
		if (str[i] == '\0')
		{
			return (-1);
		}
		count += write(1, &str[i], 1);
	}
	else
	{
		count += ft_printf_decide(str[i], *arg);
		va_arg(*arg, int);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	ssize_t		count;
	ssize_t		i;
	ssize_t		num;

	i = -1;
	count = 0;
	va_start(arg, str);
	if (!str)
		return (-1);
	while (str[++i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			num = ft_format(str, ++i, &arg);
			if (num == -1)
				return (count);
			count += num;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
			count += write(1, &str[++i], 1);
		else
			count += write(1, &str[i], 1);
	}
	return (count);
}


int main (void)
{
	int a = ft_printf(" y%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 
	'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\n");
	printf("%d",a);

	return (0);
}