/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:51:36 by jtollena          #+#    #+#             */
/*   Updated: 2023/11/21 17:38:31 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr(int current, int n, char flag)
{
	long	l;
	int		len;

	if (current == -1)
		return (-1);
	len = current;
	l = (long) n;
	if (l < 0)
	{
		l *= -1;
		len = ft_putchar(len, '-');
	} else if (flag == '+' || flag == ' ')
		len = ft_putchar(len, flag);
	if (l >= 10)
	{
		len = ft_putnbr(len, l / 10, 0);
		l %= 10;
	}
	len = ft_putchar(len, l + '0');
	return (len);
}

int	ft_putunbr(int current, unsigned int n)
{
	unsigned long	l;
	int				len;

	if (current == -1)
		return (-1);
	len = current;
	l = (unsigned long) n;
	if (l < 0)
	{
		l *= -1;
		len = ft_putchar(len, '-');
	}
	if (l >= 10)
	{
		len = ft_putunbr(len, l / 10);
		l %= 10;
	}
	len = ft_putchar(len, l + '0');
	return (len);
}

int	ft_formats(char *tmptype, int pln, int i, va_list args, char flag)
{
	if (pln == -1)
		return (-1);
	if (tmptype[i] == 'c')
		pln = ft_putchar(pln, va_arg(args, int));
	else if (tmptype[i] == 'd' || tmptype[i] == 'i')
		pln = ft_putnbr(pln, va_arg(args, int), flag);
	else if (tmptype[i] == 'u')
		pln = ft_putunbr(pln, va_arg(args, unsigned int));
	else if (tmptype[i] == 's')
		pln = ft_putstr(pln, va_arg(args, char *));
	else if (tmptype[i] == 'x')
		pln = ft_putnbr_base(pln, (size_t)va_arg(args, unsigned int), 0, flag);
	else if (tmptype[i] == 'X')
		pln = ft_putnbr_base(pln, (size_t)va_arg(args, unsigned int), 1, flag);
	else if (tmptype[i] == 'p')
	{
		pln = ft_putstr(pln, "0x");
		pln = ft_putnbr_base(pln, va_arg(args, size_t), 0, 0);
	}
	return (pln);
}

int	ft_sendspaces(int current, int i)
{	
	if (current == -1)
		return (-1);
	while (i-- > 0)
		current = ft_putchar(current, ' ');
	return (current);
}

int	ft_countspaces(int current, char *nexts)
{
	int	i;

	if (current == -1)
		return (-1);
	i = ft_atoi(nexts);
	return (i);
}

int	ft_isflag(char c, char *nexts)
{
	int	i;

	if (c == '+' && (nexts[0] == 'd' || nexts[0] == 'i'))
		return (1);
	if (c == '#' && (nexts[0] == 'x' || nexts[0] == 'X'))
		return (1);
	if (c == ' ' && (nexts[0] == 'd' || nexts[0] == 'i'))
		return (1);
	if (c == '-' && (nexts[0] >= '0' && nexts[0] <= '9'))
		return (2);
	else if (c == '-')
		return (1);
	return (0);
}

int	ft_nbrlen(int n)
{
	int	ln;

	ln = 1;
	if (n < 0)
		ln++;
	while (n / 10 != 0)
	{
		ln++;
		n /= 10;
	}
	return (ln);
}


#include <stdio.h>
int	ft_printf(const char *type, ...)
{
	va_list	args;
	char	*tmptype;
	int		i;
	long	pln;
	char	flag;
	int		j;

	pln = 0;
	tmptype = (char *)type;
	va_start(args, type);
	i = 0;
	j = 0;
	while (tmptype[i] != '\0')
	{
		while (tmptype[i] != '%' && tmptype[i] != '\0')
			pln = ft_putchar(pln, tmptype[i++]);
		if (tmptype[i++] != '\0')
		{
			if (ft_isflag(tmptype[i], &tmptype[i + 1]) == 2)
			{
				j = ft_countspaces(pln, &tmptype[i + 1]);
				i += ft_nbrlen(j - pln) + 1;
				pln = j;
			}
			if (ft_isflag(tmptype[i], &tmptype[i + 1]) >= 1)
				flag = tmptype[i++];
			if (tmptype[i] == '%')
				pln = ft_putchar(pln, tmptype[i++]);
			pln = ft_formats(tmptype, pln, i, args, flag);
			i++;
		}
	}
	if (j > 0)
		pln = ft_sendspaces(pln, j - (pln - j));
	va_end(args);
	return (pln);
}

//Pour compiler durant les tests;
//  gcc main.c helper.c -L. -lft
#include <stdio.h>
int	main(int argc, char **argv)
{
	// char *s = "salut";
	// int  i = 10;
	// void  *pi;
	// char *type = ft_substr(argv[1], 0, ft_strlen(argv[1]));
	// printf(ft_strjoin("->", type), 'b', 033, pi);
	// ft_printf(type, 'b', 033, pi);
	// free(type);

	printf("%-5d", 4213);
	ft_printf("%-5d", 4234);

	write(0, "\n", 2);
	return (argc);
}