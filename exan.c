int  ft_valid_char(char c, int base)
{
    if (c >= '0' && c <= '9')
        return (c - '0' < base);
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10 < base);
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10 < base);
    return (0);
}

int ft_value(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (0);
}

int ft_atoi_base(const char *s, int base)
{
    int sign = 1;
    int res = 0;

    if (base < 2 || base > 16)
        return (0);
    while (*s == ' ' || (*s >= 9 && *s <= 13))
        s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign = -1;
        s++;
    }
    while (*s && ft_valid_char(*s, base))
    {
        res = res * base + ft_value(*s);  // Փոփոխել "-" `+`-ով
        s++;
    }
    return (res * sign);
}




//////////////  print_ bits//////////
#include <unistd.h>

void    print_bits(unsigned char octet)
{
   int i;

   for (i = 7; i >= 0; i--)
   {
        if (octet & (1 << i))
            write (1, "1", 1);
        else
            write (1, "0", 1);
   }
}

//////////////  rivers_ bits//////////

unsigned char   reverse_bits(unsigned char octet)
{
	return  (((octet >> 0) & 1) << 7) | \
			(((octet >> 1) & 1) << 6) | \
			(((octet >> 2) & 1) << 5) | \
			(((octet >> 3) & 1) << 4) | \
			(((octet >> 4) & 1) << 3) | \
			(((octet >> 5) & 1) << 2) | \
			(((octet >> 6) & 1) << 1) | \
			(((octet >> 7) & 1) << 0);
}