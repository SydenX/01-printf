/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:51:36 by jtollena          #+#    #+#             */
/*   Updated: 2023/11/21 16:09:57 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int current, int n)
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
	}
	if (l >= 10)
	{
		len = ft_putnbr(len, l / 10);
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

int	ft_formats(char *tmptype, int pln, int i, va_list args)
{
	if (pln == -1)
		return (-1);
	if (tmptype[i] == 'c')
		pln = ft_putchar(pln, va_arg(args, int));
	else if (tmptype[i] == 'd' || tmptype[i] == 'i')
		pln = ft_putnbr(pln, va_arg(args, int));
	else if (tmptype[i] == 'u')
		pln = ft_putunbr(pln, va_arg(args, unsigned int));
	else if (tmptype[i] == 's')
		pln = ft_putstr(pln, va_arg(args, char *));
	else if (tmptype[i] == 'x')
		pln = ft_putnbr_base(pln, (size_t)va_arg(args, unsigned int), 0);
	else if (tmptype[i] == 'X')
		pln = ft_putnbr_base(pln, (size_t)va_arg(args, unsigned int), 1);
	else if (tmptype[i] == 'p')
	{
		pln = ft_putstr(pln, "0x");
		pln = ft_putnbr_base(pln, va_arg(args, size_t), 0);
	}
	return (pln);
}

int	ft_printf(const char *type, ...)
{
	va_list	args;
	char	*tmptype;
	int		i;
	long	pln;

	pln = 0;
	tmptype = (char *)type;
	va_start(args, type);
	i = 0;
	while (tmptype[i] != '\0')
	{
		while (tmptype[i] != '%' && tmptype[i] != '\0')
			pln = ft_putchar(pln, tmptype[i++]);
		if (tmptype[i] == '\0')
			break ;
		if (tmptype[++i] == '%')
			pln = ft_putchar(pln, '%');
		pln = ft_formats(tmptype, pln, i, args);
		i++;
	}
	va_end(args);
	return (pln);
}

//Pour compiler durant les tests;
//  gcc main.c helper.c -L. -lft

// int	main(int argc, char **argv)
// {
	// char *s = "salut";
	// int  i = 10;
	// void  *pi;
	// char *type = ft_substr(argv[1], 0, ft_strlen(argv[1]));
	// printf(ft_strjoin("->", type), 'b', 033, pi);
	// ft_printf(type, 'b', 033, pi);
	// free(type);

// 	printf(" %x ", (unsigned int)9223372036854775807);
// 	ft_printf(" %x ", (unsigned int)9223372036854775807);

// 	write(0, "\n", 2);
// 	return (argc);
// }