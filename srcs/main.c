/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:51:36 by jtollena          #+#    #+#             */
/*   Updated: 2023/11/16 15:35:06 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>

int	ft_printf(const char *type, ...)
{
	int	i = 0;
	char	*str;
	va_list args;

	va_start(args, type);
	str = ft_strdup(va_arg(args, char *));
	while (str)
	{
		free(str);
		str = ft_strdup(va_arg(args, char *));
		i++;
	}
	va_end(args);
	return (i);
}

int	main(int argc, char **argv)
{
	char *s = "salut";
	printf("%s\n", s);
	printf("%d\n", ft_printf(argv[1], argv[2], argv[3], NULL));
	return (argc);
}