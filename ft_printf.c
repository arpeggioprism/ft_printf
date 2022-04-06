/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:46:39 by jshin             #+#    #+#             */
/*   Updated: 2022/04/06 20:36:46 by jshin            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_checker(char c, va_list ptr)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += print_char(va_arg(ptr, int));
	if (c == '%')
		len += write(1, "%", 1);
	if (c == 'd' || c == 'i')
		len += print_number(va_arg(ptr, int));
	if (c == 'u')
		len += print_unb(va_arg(ptr, unsigned int));
	if (c == 'x')
		len += print_hex(va_arg(ptr, unsigned int), 1);
	if (c == 'X')
		len += print_hex(va_arg(ptr, unsigned int), 2);
	if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += print_adr(va_arg(ptr, unsigned long int));
	}
	if (c == 's')
		len += print_str(va_arg(ptr, char *));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ap;

	len = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		if (format[i] == '%')
		{
			len += ft_checker(format[i + 1], ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}

int main(void)
{
	ft_printf("len: %d\n", ft_printf(" %u\n", 4294967296));
	return 0;
}