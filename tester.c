/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:53:31 by simonwautel       #+#    #+#             */
/*   Updated: 2021/12/08 11:09:16 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	//ft_printf("f%i\n", 100);
	printf("%d\n", ft_printf(" %d ", 1));
	//printf("%i\n", 100);
	printf("%d\n", printf(" %d", 1));
	return 0;
}
