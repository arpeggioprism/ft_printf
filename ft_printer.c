/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:45:35 by jshin             #+#    #+#             */
/*   Updated: 2022/04/07 02:01:53 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int nb)
{
	long long	n;
	int			len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	len += len_of_n(n);
	if (n >= 10)
	{
		print_number(n / 10);
		print_number(n % 10);
	}
	if (n < 10)
		print_char(n + 48);
	return (len);
}

int	print_adr(unsigned long int nb)
{
	int	len;

	len = 0;
	len += len_of_hex(nb);
	if (nb >= 16)
	{
		print_adr(nb / 16);
		print_adr(nb % 16);
	}
	if (nb < 16)
	{
		if (nb < 10)
			print_char(nb + 48);
		else
			print_char(nb + 87);
	}
	return (len);
}

int	print_unb(unsigned int nb)
{
	int	len;

	len = 0;
	len += len_of_n(nb);
	if (nb >= 10)
	{
		print_unb(nb / 10);
		print_unb(nb % 10);
	}
	if (nb < 10)
		print_char(nb + 48);
	return (len);
}

int	print_hex(unsigned int nb, int s)
{
	int	len;

	len = 0;
	len = len_of_hex(nb);
	if (nb >= 16)
	{
		print_hex(nb / 16, s);
		print_hex(nb % 16, s);
	}
	if (nb < 16)
	{
		if (nb < 10)
			print_char(nb + 48);
		else
		{
			if (s == 1)
				print_char(nb + 87);
			else
				print_char(nb + 55);
		}
	}
	return (len);
}

int	print_str(char	*str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}
