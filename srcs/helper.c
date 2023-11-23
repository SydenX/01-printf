/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:33:51 by jtollena          #+#    #+#             */
/*   Updated: 2023/11/22 13:00:06 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	ln;

	ln = 0;
	while (s[ln] != 0)
		ln++;
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
