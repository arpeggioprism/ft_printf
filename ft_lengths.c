/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lengths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:14:37 by jshin             #+#    #+#             */
/*   Updated: 2022/04/06 20:33:42 by jshin            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_of_n(long long n)
{
	int count = 0;

	if (n == 0)
		return 1;
	while (n)
    {
        n /= 10;
        count++;
    }
	return count;
}

int	len_of_hex(unsigned long int nb)
{
	int count = 0;

	if (nb == 0)
		return 1;
	while (nb)
    {
        nb /= 16;
        count++;
    }
	return count;
}
