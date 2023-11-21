/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:08:30 by jtollena          #+#    #+#             */
/*   Updated: 2023/11/21 15:28:02 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
		return ft_putstr_fd("(null)", fd);
	while (*s != 0)
	{
		len += ft_putchar_fd(*s, fd);
		if (len == -1)
			return (-1);
		s++;
	}
	return (len);
}
