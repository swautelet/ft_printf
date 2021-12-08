/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:29:24 by simonwautel       #+#    #+#             */
/*   Updated: 2021/12/08 11:14:13 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	t_tracker	*count;
	int		result;

	count = malloc(sizeof(t_tracker));
	count->pos = str;
	va_start(arg, str);
	while (count->pos[0] != '\0')
	{
		if (*str == '%' && *(str + 1) == 'c')
			ft_write (va_arg(arg, int), count);
		else if (*str == '%' && *(str + 1) == 's')
			ft_write_string(va_arg(arg, char *), count);
		else if (*str == '%' && *(str + 1) == 'p')
			ft_pt((long int)va_arg(arg, void *), "0123456789abcdef", count);
		else if (*str == '%' && *(str + 1) == 'd')
			witoa((ssize_t)va_arg(arg, int), "0123456789", 10, count);
		else if (*str == '%' && *(str + 1) == 'i')
			witoa((ssize_t)va_arg(arg, int), "0123456789", 10, count);
		else if (*str == '%' && *(str + 1) == 'u')
			witoa((ssize_t)va_arg(arg, int), "0123456789", 10, count);
		else if (*str == '%' && *(str + 1) == 'x')
			witoa((ssize_t)va_arg(arg, int), "0123456789abcdef", 16, count);
		else if (*str == '%' && *(str + 1) == 'X')
			witoa((ssize_t)va_arg(arg, int), "0123456789ABCDEF", 16, count);
		else if (*str == '%' && *(str + 1) == '%')
			ft_write('%', count);
		else
			ft_write (count->pos[0], count);
		count->pos++;
	}
	va_end(arg);
	result = count->count;
	free (count);
	return (0);
}
