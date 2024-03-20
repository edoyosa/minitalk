/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellini <ebellini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:36:33 by ebellini          #+#    #+#             */
/*   Updated: 2024/03/20 23:56:43 by ebellini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	unsigned char	uc;

	if (fd < 0)
		return (0);
	uc = (unsigned char)c;
	write(fd, &uc, 1);
	return (1);
}
