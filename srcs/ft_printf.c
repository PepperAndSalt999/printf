/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 15:17:48 by rpicot        #+#    #+#                 */
/*   Updated: 2022/02/26 21:19:14 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"

int	ft_putstr(char *txt)
{
	int	size;

	size = 0;
	if (txt != 0)
	{
		size = ft_strlen(txt);
		write(1, txt, size);
	}
	else
	{
		write(1, "(null)", 6);
		size = 6;
	}
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		written;
	char	*txt;
	va_list	args;

	txt = (char *)format;
	written = 0;
	va_start (args, format);
	while (*txt)
	{
		if (*txt == '%')
		{
			txt++;
			if (convert(*txt, args, &written) == 0)
				return (-1);
		}
		else
			written += write(1, txt, 1);
		txt++;
	}
	va_end(args);
	return (written);
}
