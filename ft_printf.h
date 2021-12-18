/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:30:11 by simonwautel       #+#    #+#             */
/*   Updated: 2021/12/18 07:40:08 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdarg.h>
# include<unistd.h>
# include<stdio.h>
# include<stdint.h>
# include<stdlib.h>

typedef struct s_list
{
	const char	*pos;
	int			count;
}	t_tracker;

int		ft_printf(const char *str, ...);
ssize_t	ft_strlen(char *str);
void	ft_pt(size_t pin, char *tab, t_tracker *count);
int		ft_len(size_t n, size_t b);
void	witoa(ssize_t n, char *str, size_t b, t_tracker *count);
void	ft_write(char c, t_tracker *count);
void	ft_write_string(char *c, t_tracker *count);
void	u_witoa(size_t a, char *str, size_t b, t_tracker *count);

#endif