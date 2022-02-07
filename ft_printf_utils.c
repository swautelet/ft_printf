/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:18:47 by simonwautel       #+#    #+#             */
/*   Updated: 2022/01/28 11:37:27 by simonwautel      ###   ########.fr       */
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

void	witoa(ssize_t a, char *str, size_t b, t_tracker *count)
{
	int		i;
	int		*tab;

	i = 0;
	if (a < 0)
	{
		a = -a;
		ft_write('-', count);
	}
	tab = malloc(sizeof(int) * ft_len(a, b));
	if (!tab)
		return ;
	if (a == 0)
		ft_write (*str, count);
	while (a > 0)
	{
		tab[i++] = a % b;
		a = a / b;
	}
	while (--i >= 0)
		ft_write(str[tab[i]], count);
	free (tab);
	count->pos++;
}

void	u_witoa(size_t a, char *str, t_tracker *count)
{
	int	i;
	int	*tab;
	int	b;

	b = ft_strlen(str);
	i = 0;
	tab = malloc(sizeof(int) * ft_len(a, b));
	if (!tab)
		return ;
	if (a == 0)
		ft_write (*str, count);
	while (a > 0)
	{
		tab[i] = a % b;
		a = a / b;
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
