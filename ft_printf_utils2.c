/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:23:00 by simonwautel       #+#    #+#             */
/*   Updated: 2021/12/09 08:09:17 by simonwautel      ###   ########.fr       */
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

void	ft_pt(long int pin, char *tab, t_tracker *count)
{
//	int	index[9];
//	int	i;

	ft_write('0', count);
	ft_write('x', count);
	witoa(pin, tab, 16, count);
/*	i = 0;
	while (i < 9)
	{
		index[i] = pin % 16;
		pin = pin / 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_write(tab[index[i]], count);
	}
	count->pos++;*/
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
