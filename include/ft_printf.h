/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 16:22:42 by rpicot        #+#    #+#                 */
/*   Updated: 2022/02/26 20:28:17 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "./../libft/libft.h"

long	check_negative(long integer, int *written, int txt);
int		check_base(char spec);
int		convert(char txt, va_list args, int *written);
int		ft_printf(const char *txt, ...);
int		ft_putstr(char *txt);
int		write_that_number(unsigned long long base, unsigned long long number,
			char *hex, unsigned long long add);
int		config_number(unsigned long long number, char spec);
void	init_lookup(int	*lookup);

#endif
