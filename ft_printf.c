/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:29:24 by simonwautel       #+#    #+#             */
/*   Updated: 2021/11/26 20:36:07 by simonwautel      ###   ########.fr       */
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

void ft_itoa_pointer(long int pin, char *tab)
{
	int	index[9];
	int	i;

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
}

int	ft_len(size_t n, size_t b)
{
	int	l;

	l = 1;
	if (n < 0)
		l++;
	while (n >= b)
	{
		l++;
		n = n / b;
	}
	return (l);
}

void	write_itoa(size_t n, char *str)
{
	size_t	b;
	int		i;

	b = ft_strlen(str);

	int tab[ft_len(n, b)];

	i = 0;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	while (n > 0)
	{
		tab[i] = n % b;
		n = n / b;
		i++;
	}
	while (i-- >= 0)
	{
		write(1, &str[tab[i]], 1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			len;
	char		c;
	char		*string;
	long int	pin;

	len = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) == 'c')
		{
			c = va_arg(arg, int);
			write (1, &c, 1);
			str++;
		}
		else if (*str == '%' && *(str + 1) == 's')
		{
			string = va_arg(arg, char *);
			write(1, string, ft_strlen(string));
			str++;
		}
		else if(*str == '%' && *(str + 1) == 'p')
		{
			pin = (long int)va_arg(arg, void *);
			write(1, "0x", 2);
			ft_itoa_pointer(pin, "0123456789abcdef");
			str++;
		}
		else if(*str == '%' && *(str + 1) == 'd')
		{
			write_itoa((size_t)va_arg(arg, int), "0123456789");
		}
		else if(*str == '%' && *(str + 1) == 'i')
		{
			write_itoa((size_t)va_arg(arg, int), "0123456789");

		}
		else if(*str == '%' && *(str + 1) == 'u')
		{
			write_itoa((size_t)va_arg(arg, int), "0123456789");
		}
		else if(*str == '%' && *(str + 1) == 'x')
		{
			write_itoa((size_t)va_arg(arg, int), "0123456789abcdef");
		}
		else if(*str == '%' && *(str + 1) == 'X')
		{
			write_itoa((size_t)va_arg(arg, int), "0123456789ABCDEF");
		}
		else if(*str == '%' && *(str + 1) == '%')
			write(1, "%", 1);
		else
			write (1, str, 1);
		str++;
	}
	va_end(arg);
	return (0);
}
