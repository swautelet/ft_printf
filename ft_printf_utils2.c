/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:23:00 by simonwautel       #+#    #+#             */
/*   Updated: 2021/12/18 10:30:57 by simonwautel      ###   ########.fr       */
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

void	ft_pt(size_t pin, char *tab, t_tracker *count)
{
	ft_write('0', count);
	ft_write('x', count);
	u_witoa(pin, tab, count);
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

void	ft_write_char(char c, t_tracker *count)
{
	ft_write(c, count);
	count->pos++;
}
