/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:10:15 by jtollena          #+#    #+#             */
/*   Updated: 2023/11/21 17:11:42 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

# define MY_INT_MAX 2147483647
# define MY_LONG_MAX 9223372036854775807

int		ft_printf(const char *type, ...);
size_t	ft_strlen(const char *s);
int		ft_putstr(int current, char *s);
int		ft_putnbr(int current, int n, char flag);
int		ft_putunbr(int current, unsigned int n);
int		ft_putchar(int current, char c);
int		ft_putnbr_base(int current, size_t nbr, int maj, char flag);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);

#endif