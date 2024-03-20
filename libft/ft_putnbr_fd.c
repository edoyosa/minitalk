/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellini <ebellini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:33:35 by ebellini          #+#    #+#             */
/*   Updated: 2024/03/20 23:57:03 by ebellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
	{
		count = ft_putstr_fd("-2147483648", fd);
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
		count += ft_putnbr_fd(n / 10, fd);
	count += ft_putchar_fd('0' + (n % 10), fd);
	return (count);
}
