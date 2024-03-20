/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellini <ebellini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:22:52 by ebellini          #+#    #+#             */
/*   Updated: 2024/03/20 23:56:01 by ebellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_test_tag(const char *str, va_list lst_args)
{
	int		count;
	char	*s;

	s = 0;
	count = 0;
	if (*str == 'c')
		count = ft_putchar_fd(va_arg(lst_args, int), 1);
	else if (*str == 's')
	{
		s = va_arg(lst_args, char *);
		if (s)
			count = ft_putstr_fd(s, 1);
		else
			count = ft_putstr_fd("(null)", 1);
	}
	else if (*str == 'd' || *str == 'i')
		count = ft_putnbr_fd(va_arg(lst_args, int), 1);
	else if (*str == '%')
		count = ft_putchar_fd(*str, 1);
	else if (*str == 'p')
		count = ft_void_value(va_arg(lst_args, void *));
	else if (*str == 'x' || *str == 'X' || *str == 'u')
		count = ft_unsigned_value(va_arg(lst_args, unsigned int), *str);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst_args;
	int		count;

	count = 0;
	va_start(lst_args, str);
	while (*str)
	{
		if (*str != '%')
			count += ft_putchar_fd(*str, 1);
		else if (++str)
		{
			count += ft_test_tag(str, lst_args);
		}
		str++;
	}
	va_end(lst_args);
	return (count);
}
