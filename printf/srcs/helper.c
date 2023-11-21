/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:33:51 by jtollena          #+#    #+#             */
/*   Updated: 2023/11/21 17:12:24 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	ln;

	ln = 0;
	while (s[ln] != 0)
		ln++;
	return (ln);
}

int	ft_putchar(int current, char c)
{
	int	ln;

	if (current == -1)
		return (-1);
	ln = write(1, &c, 1);
	if (ln == -1)
		return (-1);
	else
		return (current + ln);
}

int	ft_putstr(int current, char *s)
{
	int	ln;

	ln = current;
	if (current == -1)
		return (-1);
	if (!s)
		return (ft_putstr(current, "(null)"));
	while (*s != 0)
	{
		ln = ft_putchar(ln, *s);
		s++;
	}
	return (ln);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	if (!s)
		return (NULL);
	copy = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

int	ft_putnbr_base(int current, size_t nbr, int maj, char flag)
{
	char	*base;
	int		len;

	if (current == -1)
		return (-1);
	len = current;
	if (maj == 0)
		base = ft_strdup("0123456789abcdef");
	else 
		base = ft_strdup("0123456789ABCDEF");
	if (base == NULL)
		return (-1);
	if (nbr < 0)
	{
		nbr *= -1;
		len = ft_putchar(len, '-');
	} else if (flag == '#')
		len = ft_putstr(len, "0x");
	if (nbr / 16 > 0)
		len = ft_putnbr_base(len, nbr / 16, maj, 0);
	len = ft_putchar(len, base[nbr % 16]);
	return (free(base), len);
}

static int	ft_isoverflow(unsigned long long nb, const char *str, int negation)
{
	if (nb >= MY_LONG_MAX / 10 && 
		(nb > MY_LONG_MAX / 10 || str[0] - '0' > MY_LONG_MAX % 10))
	{
		if (negation == 1)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					negation;
	unsigned long long	nb;

	nb = 0;
	negation = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			negation = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_isoverflow(nb, &str[i], negation) != 1)
			return (ft_isoverflow(nb, &str[i], negation));
		nb = (nb * 10) + str[i++] - '0';
	}
	return (nb * negation);
}
