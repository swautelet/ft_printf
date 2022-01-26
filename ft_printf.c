/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:29:24 by simonwautel       #+#    #+#             */
/*   Updated: 2022/01/26 18:15:17 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	t_tracker	*count;
	int			result;

	count = malloc(sizeof(t_tracker));
	if (!count)
		return (0);
	count->pos = str;
	count->count = 0;
	va_start(arg, str);
	ft_printf2(arg, count, "0123456789abcdef", "0123456789ABCDEF");
	va_end(arg);
	result = count->count;
	free (count);
	return (result);
}

void	ft_printf2(va_list arg, t_tracker *count, char *hexa, char *Hexa)
{
	while (count->pos[0])
	{
		if (count->pos[0] == '%' && count->pos[1] == 'c')
			ft_write_char(va_arg(arg, int), count);
		else if (count->pos[0] == '%' && count->pos[1] == 's')
			ft_write_string(va_arg(arg, char *), count);
		else if (count->pos[0] == '%' && count->pos[1] == 'p')
			ft_pt((size_t)va_arg(arg, void *), "0123456789abcdef", count);
		else if (count->pos[0] == '%' && count->pos[1] == 'd')
			witoa((ssize_t)va_arg(arg, int), "0123456789", 10, count);
		else if (count->pos[0] == '%' && count->pos[1] == 'i')
			witoa((ssize_t)va_arg(arg, int), "0123456789", 10, count);
		else if (count->pos[0] == '%' && count->pos[1] == 'u')
			u_witoa((size_t)va_arg(arg, unsigned int), "0123456789", count);
		else if (count->pos[0] == '%' && count->pos[1] == 'x')
			u_witoa((size_t)va_arg(arg, unsigned int), hexa, count);
		else if (count->pos[0] == '%' && count->pos[1] == 'X')
			u_witoa((size_t)va_arg(arg, unsigned int), Hexa, count);
		else if (count->pos[0] == '%' && count->pos[1] == '%')
			ft_write_char('%', count);
		else
			ft_write (count->pos[0], count);
		count->pos++;
	}
}
