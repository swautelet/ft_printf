/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:53:31 by simonwautel       #+#    #+#             */
/*   Updated: 2021/12/18 07:51:19 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<limits.h>

int	main(void)
{
	unsigned int a = -1;
	
	printf("	%d\n", ft_printf("%x", a));
	printf("	%d\n", printf("%x", a));
}
