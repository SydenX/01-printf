/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:08:20 by jtollena          #+#    #+#             */
/*   Updated: 2023/11/21 15:31:16 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	l;
	int		len;
	int		flen;

	len = 0;
	l = (long) n;
	if (l < 0)
	{
		l *= -1;
		len += ft_putchar_fd('-', fd);
	}
	if (l >= 10)
	{
		len += ft_putnbr_fd(l / 10, fd);
		l %= 10;
	}
	len += ft_putchar_fd(l + '0', fd);
	return (len);
}
