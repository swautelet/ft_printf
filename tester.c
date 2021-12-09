/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:53:31 by simonwautel       #+#    #+#             */
/*   Updated: 2021/12/09 08:18:18 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char *test =  NULL;
	
	printf("	%d\n", ft_printf("%s", test));
	printf("	%d\n", printf("%s", test));
}
