/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:53:31 by simonwautel       #+#    #+#             */
/*   Updated: 2021/12/18 10:36:12 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<limits.h>

int	main(void)
{	
	printf("		%d\n", ft_printf("%c", 300));
	printf("		%d\n", printf("%c", 300));
}
