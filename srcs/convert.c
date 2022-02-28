/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 15:18:06 by rpicot        #+#    #+#                 */
/*   Updated: 2022/02/26 21:19:03 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"

int	check_base(char spec)
{
	if (spec == 'd' || spec == 'i' || spec == 'u')
		return (10);
	else
		return (16);
}

int	write_that_number(unsigned long long base,
		unsigned long long number, char *hex, unsigned long long add)
{
	int		written;
	char	c;

	written = 1;
	if (number >= base)
		written += write_that_number(base, number / base, hex, add);
	number = number % base;
	c = hex[number];
	if (number >= 10)
		c += add;
	write(1, &c, 1);
	return (written);
}

int	config_number(unsigned long long number, char spec)
{
	long	base;
	long	add;
	char	*hex;

	if (spec == 'c')
	{
		write(1, &number, 1);
		return (1);
	}
	add = 0;
	hex = "0123456789ABCDEF";
	base = check_base(spec);
	if (spec >= 'p')
		add = 32;
	return (write_that_number(base, number, hex, add));
}

long	check_negative(long integer, int *written, int txt)
{
	if (integer < 0 && txt != 'c')
	{
		integer *= -1;
		*written += write(1, "-", 1);
	}
	return (integer);
}

int	convert(char txt, va_list args, int *written)
{
	unsigned long long	integer;

	if (txt == 0)
		return (0);
	if (!ft_strchr("diuxX%pcs", txt))
		return (0);
	if (txt == '%')
		*written += write(1, &txt, 1);
	else if (txt == 's')
		*written += ft_putstr(va_arg(args, char *));
	else
	{
		if (txt == 'p')
		{
			*written += write(1, "0x", 2);
			integer = va_arg(args, unsigned long long);
		}
		else if (txt > 'i' || txt == 'X')
			integer = va_arg(args, unsigned int);
		else
			integer = check_negative(va_arg(args, int), written, txt);
		*written += config_number(integer, txt);
	}
	return (1);
}
