/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:29:24 by simonwautel       #+#    #+#             */
/*   Updated: 2021/11/29 20:05:57 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

const char	*ft_pt(long int pin, char *tab, const char *str)
{
	int	index[9];
	int	i;

	write(1, "0x", 2);
	i = 0;
	while (i < 9)
	{
		index[i] = pin % 16;
		pin = pin / 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &tab[index[i]], 1);
	}
	return (++str);
}

int	ft_len(size_t n, size_t b)
{
	int	l;

	l = 1;
	while (n >= b)
	{
		l++;
		n = n / b;
	}
	return (l);
}

const char	*witoa(ssize_t n, char *str, size_t b, const char *or)
{
	int	i;
	int	*tab;

	i = 0;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	tab = malloc(sizeof(int) * ft_len(n, b));
	if (n == 0)
		write (1, str, 1);
	while (n > 0)
	{
		tab[i] = n % b;
		n = n / b;
		i++;
	}
	while (--i >= 0)
	{
		write(1, &str[tab[i]], 1);
	}
	free (tab);
	return (++or);
}

const char	*ft_write(char c, const char *str)
{
	write (1, &c, 1);
	return (++str);
}

const char	*ft_write_string(char *c, const char *str)
{
	write(1, c, ft_strlen(c));
	return (++str);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;

	va_start(arg, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) == 'c')
			str = ft_write (va_arg(arg, int), str);
		else if (*str == '%' && *(str + 1) == 's')
			str = ft_write_string(va_arg(arg, char *), str);
		else if (*str == '%' && *(str + 1) == 'p')
			str = ft_pt((long int)va_arg(arg, void *), "0123456789abcdef", str);
		else if (*str == '%' && *(str + 1) == 'd')
			str = witoa((ssize_t)va_arg(arg, int), "0123456789", 10, str);
		else if (*str == '%' && *(str + 1) == 'i')
			str = witoa((ssize_t)va_arg(arg, int), "0123456789", 10, str);
		else if (*str == '%' && *(str + 1) == 'u')
			str = witoa((ssize_t)va_arg(arg, int), "0123456789", 10, str);
		else if (*str == '%' && *(str + 1) == 'x')
			str = witoa((ssize_t)va_arg(arg, int), "0123456789abcdef", 16, str);
		else if (*str == '%' && *(str + 1) == 'X')
			str = witoa((ssize_t)va_arg(arg, int), "0123456789ABCDEF", 16, str);
		else if (*str == '%' && *(str + 1) == '%')
			str = ft_write('%', str);
		else
			write (1, str, 1);
		str++;
	}
	va_end(arg);
	return (0);
}
