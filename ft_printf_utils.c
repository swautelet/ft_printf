/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:18:47 by simonwautel       #+#    #+#             */
/*   Updated: 2021/12/09 08:21:05 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_write_string(char *c, t_tracker *count)
{
	int	len;

	if (c == NULL)
	{
		write(1, "(null)", 6);
		count->count += 6;
		count->pos++;
	}
	else
	{
		len = ft_strlen(c);
		write(1, c, len);
		count->count += len;
		count->pos++;
	}
}

void	witoa(ssize_t n, char *str, size_t b, t_tracker *count)
{
	int	i;
	int	*tab;

	i = 0;
	if (n < 0)
	{
		n = -n;
		ft_write('-', count);
	}
	tab = malloc(sizeof(int) * ft_len(n, b));
	if (n == 0)
		ft_write (*str, count);
	while (n > 0)
	{
		tab[i] = n % b;
		n = n / b;
		i++;
	}
	while (--i >= 0)
	{
		ft_write(str[tab[i]], count);
	}
	free (tab);
	count->pos++;
}

void	ft_write(char c, t_tracker *count)
{
	write (1, &c, 1);
	count->count++;
}
