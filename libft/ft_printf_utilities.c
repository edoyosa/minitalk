/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellini <ebellini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:12:53 by ebellini          #+#    #+#             */
/*   Updated: 2024/03/20 23:56:22 by ebellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_value(unsigned long long int n, char *digits,
								unsigned long long int base)
{
	int	count;

	count = 0;
	if (n < base)
		count += ft_putchar_fd(digits[n], 1);
	else
	{
		count += ft_print_value(n / base, digits, base);
		count += ft_print_value(n % base, digits, base);
	}
	return (count);
}

int	ft_void_value(void *ptr)
{
	unsigned long long int	n;

	n = (unsigned long long int)ptr;
	if (!n)
		return (ft_putstr_fd("(nil)", 1));
	else
	{
		ft_putstr_fd("0x", 1);
		return (ft_print_value(n, "0123456789abcdef", 16) + 2);
	}
}

int	ft_unsigned_value(unsigned int ui, char c)
{
	unsigned long long int	n;

	n = (unsigned long long int)ui;
	if (c == 'x')
		return (ft_print_value(n, "0123456789abcdef", 16));
	else if (c == 'X')
		return (ft_print_value(n, "0123456789ABCDEF", 16));
	else if (c == 'u')
		return (ft_print_value(n, "0123456789", 10));
	return (0);
}
